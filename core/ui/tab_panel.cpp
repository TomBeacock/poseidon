#include "tab_panel.h"

#include "text.h"
#include "horizontal_panel.h"
#include "vertical_panel.h"

#include <iostream>

namespace poseidon
{
	Tab::Tab(const std::u8string& label, std::shared_ptr<Widget> content) :
		content_(content)
	{
		setHitTestable(true);

		auto hPanel = std::make_shared<HorizontalPanel>();
		hPanel->setPadding(Thickness(8.0f, 4.0f));
		hPanel->setLayoutParams(std::make_unique<LayoutParams>(Size::wrap, Size::wrap));

		auto labelText = std::make_shared<Text>(label);
		hPanel->addChild(labelText);

		setRoot(hPanel);
	}

	TabPanel::TabPanel()
	{
		auto panel = std::make_shared<VerticalPanel>();

		tabBar_ = std::make_shared<HorizontalPanel>();
		auto tabBarLayout = std::make_unique<LayoutParams>(Size::fill, Size::wrap);
		panel->addChild(tabBar_, std::move(tabBarLayout));

		contentPanel_ = std::make_shared<VerticalPanel>();
		auto contentPanelLayout = std::make_unique<LayoutParams>(Size::fill, Size::fill);
		panel->addChild(contentPanel_, std::move(contentPanelLayout));

		setRoot(panel);
	}

	void TabPanel::addTab(std::shared_ptr<Tab> tab)
	{
		tabs_.push_back(tab);
		tabBar_->addChild(tab);

		if (tabs_.size() == 1)
			selectTab(tab);
	}

	void TabPanel::selectTab(const std::shared_ptr<Tab>& tab)
	{
		if (std::find(tabs_.begin(), tabs_.end(), tab) == tabs_.end())
			return;
		
		int count = contentPanel_->children().size();
		for (size_t i = 0; i < count; i++)
			contentPanel_->removeChild(contentPanel_->children()[0]);
		
		contentPanel_->addChild(tab->content());
	}
}