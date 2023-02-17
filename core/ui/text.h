#pragma once

#include <string>

#include "view.h"
#include "math/vec4.h"

namespace poseidon
{
	class Font;

	class Text : public View
	{
	public:
		Text();

		inline const std::u8string& text() const { return text_; }
		inline void setText(std::u8string text) { text_ = text; }

		inline const std::shared_ptr<Font>& font() const { return font_; }
		inline void setFont(std::shared_ptr<Font> font) { font_ = font; }

		inline const Vec4& color() const { return color_; }
		inline void setColor(const Vec4& color) { color_ = color; }

		inline float fontSize() const { return fontSize_; }
		inline void setFontSize(float fontSize) { fontSize_ = fontSize; }

	protected:
		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
		virtual void onDraw(const Vec2& relativeOrigin) override;

	private:
		std::u8string text_;
		std::shared_ptr<Font> font_;
		Vec4 color_;
		float fontSize_;
		float baseline_;
	};
}