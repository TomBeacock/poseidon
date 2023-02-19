#pragma once

#include "compound_widget.h"

namespace poseidon
{
	class Text;

	class Button : public CompoundWidget
	{
	public:
		Button();

		virtual void onMouseEnter() override;
		virtual void onMouseExit() override;

		Text& text();

	private:
		std::shared_ptr<Text> text_;
	};
}