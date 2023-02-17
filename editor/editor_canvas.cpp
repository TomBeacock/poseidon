#include "editor_canvas.h"

#include <poseidon/math.h>

#include <iostream>

using namespace poseidon;

namespace editor
{
	EditorCanvas::EditorCanvas()
	{
		std::shared_ptr<Font> font = std::make_shared<Font>(RES_DIR "fonts/pixel-font.png", RES_DIR "fonts/pixel-font-values.json");

		auto root = std::make_shared<VerticalPanel>();
		setRoot(root);

		auto menuBar = std::make_shared<HorizontalPanel>();
		menuBar->setPadding(Thickness(8.0f));
		auto menuBarLayout = std::make_unique<VerticalPanel::LayoutParams>(Size::fill, Size::wrap);
		root->addView(menuBar, std::move(menuBarLayout));

		auto fileText = std::make_shared<Text>();
		fileText->setText(u8"File");
		fileText->setFont(font);
		auto fileTextLayout = std::make_unique<HorizontalPanel::LayoutParams>();
		menuBar->addView(fileText, std::move(fileTextLayout));

		auto editText = std::make_shared<Text>();
		editText->setText(u8"Edit");
		editText->setFont(font);
		auto editTextLayout = std::make_unique<HorizontalPanel::LayoutParams>();
		editTextLayout->setMargin(Thickness(8.0f, 0.0f, 0.0f, 0.0f));
		menuBar->addView(editText, std::move(editTextLayout));

		auto contentPanel = std::make_shared<VerticalPanel>();
		contentPanel->setPadding(Thickness(16.0f));
		auto contentPanelLayout = std::make_unique<VerticalPanel::LayoutParams>(Size::fill, Size::fill);
		root->addView(contentPanel, std::move(contentPanelLayout));

		auto contentText = std::make_shared<Text>();
		contentText->setText(u8"Content area");
		contentText->setFont(font);
		auto contentTextLayout = std::make_unique<VerticalPanel::LayoutParams>();
		contentPanel->addView(contentText, std::move(contentTextLayout));
	}
}