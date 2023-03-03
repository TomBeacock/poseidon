#include "editor_canvas.h"

#include <poseidon/math.h>

#include <iostream>

using namespace poseidon;

namespace editor
{
	EditorCanvas::EditorCanvas()
	{
		auto root = std::make_shared<VerticalPanel>();
		setRoot(root);

		auto menuBar = std::make_shared<HorizontalPanel>();
		menuBar->setColor({ 0.9f, 0.9f, 0.9f, 1.0f });
		auto menuBarLayout = std::make_unique<VerticalPanel::LayoutParams>(Size::fill, Size::wrap);
		root->addChild(menuBar, std::move(menuBarLayout));

		auto fileButton = std::make_shared<Button>();
		fileButton->text().setText(u8"File");
		auto fileButtonLayout = std::make_unique<HorizontalPanel::LayoutParams>();
		menuBar->addChild(fileButton, std::move(fileButtonLayout));

		auto editButton = std::make_shared<Button>();
		editButton->text().setText(u8"Edit");
		auto editButtonLayout = std::make_unique<HorizontalPanel::LayoutParams>();
		menuBar->addChild(editButton, std::move(editButtonLayout));

		auto contentPanel = std::make_shared<TabPanel>();
		auto contentPanelLayout = std::make_unique<VerticalPanel::LayoutParams>(Size::fill, Size::fill);
		root->addChild(contentPanel, std::move(contentPanelLayout));

		auto text1 = std::make_shared<Text>(u8"Tab 1 Content");
		auto tab1 = std::make_shared<Tab>(u8"Tab 1", text1);
		contentPanel->addTab(tab1);

		auto text2 = std::make_shared<Text>(u8"Tab 2 Content");
		auto tab2 = std::make_shared<Tab>(u8"Tab 2", text2);
		contentPanel->addTab(tab2);
	}
}