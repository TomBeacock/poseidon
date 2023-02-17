#include "text.h"

#include "rendering/renderer2d.h"
#include "rendering/texture.h"
#include "util/utf8_iterator.h"
#include "font.h"
#include "math/vec4.h"

namespace poseidon
{
	Text::Text() :
		fontSize_(16.0f),
		color_(0.0f, 0.0f, 0.0f, 1.0f),
		baseline_(0.0f) {}

	Vec2 Text::onMeasure()
	{
		if (font_ == nullptr)
			return Vec2::zero;

		float scale = fontSize_ / (float)font_->height();
		float minY = 0.0f, maxY = 0.0f;

		Vec2 size;
		for (Utf8Iterator it = text_.begin(); it != text_.end(); ++it)
		{
			char32_t codePoint = *it;
			const GlyphMeasurements& glyph = font_->glyph(*it);
			minY = std::min(minY, (float)glyph.bearingY - (float)glyph.height);
			maxY = std::max(maxY, (float)glyph.bearingY);
			size.x += glyph.advance;
		}
		baseline_ = maxY * scale;
		size.y = maxY - minY;
		return size * scale;
	}

	void Text::onLayout(const Vec2& position, const Vec2& size)
	{

	}

	void Text::onDraw(const Vec2& relativeOrigin)
	{
		if (font_ == nullptr)
			return;
		float scale = fontSize_ / (float)font_->height();
		Vec2 pen = relativeOrigin + actualPosition() + Vec2(0.0f, baseline_);

		for (Utf8Iterator it = text_.begin(); it != text_.end(); ++it)
		{
			const GlyphMeasurements& glyph = font_->glyph(*it);
			Bounds bounds(
				pen + Vec2((float)glyph.bearingX, -(float)glyph.bearingY) * scale,
				Vec2((float)glyph.width, (float)glyph.height) * scale
			);
			std::shared_ptr<Texture> atlas = font_->atlas();
			Vec2 atlasSize = Vec2((float)atlas->width(), (float)atlas->height());
			Vec2 uvMin = {
				(float)glyph.uvX / atlasSize.x,
				(atlasSize.y - (float)(glyph.uvY + glyph.height)) / atlasSize.y
			};
			Vec2 uvMax = {
				(float)(glyph.uvX + glyph.width) / atlasSize.x,
				(atlasSize.y - (float)glyph.uvY) / atlasSize.y
			};
			Bounds uv(uvMin.x, uvMax.x, uvMin.y, uvMax.y);
			Renderer2D::drawRect(bounds, uv, font_->atlas(), color_);
			pen.x += glyph.advance * scale;
		}
	}
}