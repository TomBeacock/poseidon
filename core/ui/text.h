#pragma once

#include <string>

#include "view.h"

namespace poseidon
{
	class Font;

	class Text : public View
	{
	public:
		inline const std::u8string& text() const { return text_; }
		inline void setText(std::u8string text) { text_ = text; }

		inline const std::shared_ptr<Font>& font() const { return font_; }
		inline void setFont(std::shared_ptr<Font> font) { font_ = font; }

	protected:
		virtual const Vec2& onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
		virtual void onDraw(const Vec2& relativeOrigin) override;

	private:
		std::u8string text_;
		std::shared_ptr<Font> font_;
		uint32_t baseline_;
	};
}