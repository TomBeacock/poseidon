#include "button.h"

#include "vertical_panel.h"
#include "text.h"

namespace poseidon
{
	Button::Button()
	{
		setHitTestable(true);

		auto hPanel = std::make_unique<VerticalPanel>();
		hPanel->setPadding(Thickness(8.0f, 4.0f));

		text_ = std::make_shared<Text>();
		auto textLayout = std::make_unique<VerticalPanel::LayoutParams>();
		textLayout->setHorizontalAlignment(HorizontalAlignment::Center);
		hPanel->addView(text_, std::move(textLayout));

		setRoot(std::move(hPanel));
	}

	Text& Button::text()
	{
		return *text_;
	}
}