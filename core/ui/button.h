#pragma once

#include "compound_widget.h"

namespace poseidon
{
	class Text;

	class Button : public CompoundWidget
	{
	public:
		Button();

		Text& text();

	private:
		std::shared_ptr<Text> text_;
	};
}