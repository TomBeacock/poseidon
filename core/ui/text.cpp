#include "text.h"

#include "rendering/renderer2d.h"
#include "rendering/texture.h"
#include "util/utf8_iterator.h"
#include "font.h"
#include "math/vec4.h"

namespace poseidon
{
	const Vec2& Text::onMeasure()
	{
		if (font_ == nullptr)
			return Vec2::zero;

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
		baseline_ = maxY;
		size.y = maxY - minY;
		return size + margin().size();
	}

	void Text::onLayout(const Vec2& position, const Vec2& size)
	{

	}

	void Text::onDraw(const Vec2& relativeOrigin)
	{
		if (font_ == nullptr)
			return;

		Vec2 pen = relativeOrigin + actualPosition() + Vec2(0.0f, baseline_);
		for (Utf8Iterator it = text_.begin(); it != text_.end(); ++it)
		{
			const GlyphMeasurements& glyph = font_->glyph(*it);
			Bounds bounds(
				pen + Vec2((float)glyph.bearingX, -(float)glyph.bearingY),
				Vec2((float)glyph.width, (float)glyph.height)
			);
			std::shared_ptr<Texture> atlas = font_->atlas();
			Vec2 atlasSize = Vec2(atlas->width(), atlas->height());
			Vec2 uvMin = {
				(float)glyph.uvX / atlasSize.x,
				(atlasSize.y - (float)(glyph.uvY + glyph.height)) / atlasSize.y
			};
			Vec2 uvMax = {
				(float)(glyph.uvX + glyph.width) / atlasSize.x,
				(atlasSize.y - (float)glyph.uvY) / atlasSize.y
			};
			Bounds uv(uvMin.x, uvMax.x, uvMin.y, uvMax.y);
			Renderer2D::drawRect(bounds, uv, font_->atlas(), Vec4::one);
			//Renderer2D::drawRect(bounds, Vec4::one);
			pen.x += glyph.advance;
		}
	}
}