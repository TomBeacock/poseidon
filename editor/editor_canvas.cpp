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

		auto contentPanel = std::make_shared<VerticalPanel>();
		contentPanel->setPadding(Thickness(16.0f));
		auto contentPanelLayout = std::make_unique<VerticalPanel::LayoutParams>(Size::fill, Size::fill);
		root->addView(contentPanel, std::move(contentPanelLayout));

		auto contentText = std::make_shared<Text>();
		contentText->setText(u8"Content area");
		auto contentTextLayout = std::make_unique<VerticalPanel::LayoutParams>();
		contentPanel->addView(contentText, std::move(contentTextLayout));
	}
}