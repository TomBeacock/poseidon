#pragma once

#include "compound_widget.h"

namespace poseidon
{
	class Text;

	class Button : public CompoundWidget
	{
	public:
		Button();

		virtual void onMouseEnter(const class MouseMotionEvent& event) override;
		virtual void onMouseExit(const class MouseMotionEvent& event) override;

		Text& text();

	private:
		std::shared_ptr<Text> text_;
	};
}