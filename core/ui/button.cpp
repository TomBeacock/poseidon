#include "button.h"

#include "vertical_panel.h"
#include "text.h"

namespace poseidon
{
	Button::Button()
	{
		setHitTestable(true);

		auto vPanel = std::make_unique<VerticalPanel>();
		vPanel->setPadding(Thickness(8.0f, 4.0f));

		text_ = std::make_shared<Text>();
		auto textLayout = std::make_unique<VerticalPanel::LayoutParams>();
		textLayout->setHorizontalAlignment(HorizontalAlignment::Center);
		vPanel->addView(text_, std::move(textLayout));

		setRoot(std::move(vPanel));
	}

	void Button::onMouseEnter(const class MouseMotionEvent& event)
	{
		if (root())
		{
			auto vPanel = (VerticalPanel*const)root();
			vPanel->setColor({ 0.96f, 0.96f, 0.98f, 1.0f });
		}
	}

	void Button::onMouseExit(const class MouseMotionEvent& event)
	{
		if (root())
		{
			auto vPanel = (VerticalPanel* const)root();
			vPanel->setColor(Vec4::one);
		}
	}

	Text& Button::text()
	{
		return *text_;
	}
}