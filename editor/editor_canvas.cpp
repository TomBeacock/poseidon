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
		root->addView(menuBar, std::move(menuBarLayout));

		auto fileButton = std::make_shared<Button>();
		fileButton->text().setText(u8"File");
		auto fileButtonLayout = std::make_unique<HorizontalPanel::LayoutParams>();
		menuBar->addView(fileButton, std::move(fileButtonLayout));

		auto editButton = std::make_shared<Button>();
		editButton->text().setText(u8"Edit");
		auto editButtonLayout = std::make_unique<HorizontalPanel::LayoutParams>();
		menuBar->addView(editButton, std::move(editButtonLayout));

		auto contentPanel = std::make_shared<AnchorPanel>();
		auto contentPanelLayout = std::make_unique<VerticalPanel::LayoutParams>(Size::fill, Size::fill);
		root->addView(contentPanel, std::move(contentPanelLayout));

		auto text1 = std::make_shared<Text>();
		text1->setText(u8"Text 1");
		auto text1Layout = std::make_unique<AnchorPanel::LayoutParams>();
		text1Layout->setAnchor({ 0.0f, 0.0f });
		text1Layout->setPosition({ 20.0f, 50.0f });
		contentPanel->addView(text1, std::move(text1Layout));

		auto text2 = std::make_shared<Text>();
		text2->setText(u8"Text 2");
		auto text2Layout = std::make_unique<AnchorPanel::LayoutParams>();
		text2Layout->setAnchor({ 1.0f, 1.0f });
		text2Layout->setPivot({ 1.0f, 1.0f });
		text2Layout->setPosition({ -200.0f, -100.0f });
		contentPanel->addView(text2, std::move(text2Layout));

		auto rect1 = std::make_shared<Rectangle>();
		rect1->setColor({ 0.0f, 1.0f, 0.0f, 1.0f });
		auto rect1Layout = std::make_unique<AnchorPanel::LayoutParams>(16.0f, 16.0f);
		rect1Layout->setPivot({ 1.0f, 0.0f });
		rect1Layout->setAnchorMin({ 0.0f, 0.0f });
		rect1Layout->setAnchorMax({ 1.0f, 1.0f });
		rect1Layout->setOffset({ 128.0f });
		contentPanel->addView(rect1, std::move(rect1Layout));
	}
}