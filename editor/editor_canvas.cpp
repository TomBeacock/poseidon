#include "editor_canvas.h"

#include <poseidon/math.h>

#include <iostream>

using namespace poseidon;

namespace editor
{
	EditorCanvas::EditorCanvas()
	{

		auto root = std::make_shared<HorizontalPanel>();
		root->setPadding(Thickness(16.0f));

		auto rect1 = std::make_shared<Rectangle>();
		rect1->setColor(Vec4(1.0f, 1.0f, 0.0f, 1.0f));
		auto rect1Layout = std::make_unique<HorizontalPanel::LayoutParams>(Size::fill, Size::fill);
		rect1Layout->setMargin(Thickness(16.0f, 32.0f, 64.0f, 128.0f));
		root->addView(rect1, std::move(rect1Layout));

		auto vertical = std::make_shared<VerticalPanel>();
		auto verticalLayout = std::make_unique<HorizontalPanel::LayoutParams>(Size::fill, Size::fill);
		root->addView(vertical, std::move(verticalLayout));

		auto rect2 = std::make_shared<Rectangle>();
		rect2->setColor(Vec4(0.0f, 1.0f, 1.0f, 1.0f));
		auto rect2Layout = std::make_unique<VerticalPanel::LayoutParams>(Size(128.0f), Size::fill);
		rect2Layout->setHorizontalAlignment(HorizontalAlignment::Right);
		vertical->addView(rect2, std::move(rect2Layout));

		auto rect3 = std::make_shared<Rectangle>();
		rect3->setColor(Vec4(1.0f, 0.0f, 1.0f, 1.0f));
		auto rect3Layout = std::make_unique<VerticalPanel::LayoutParams>(Size(256.0f), Size(128.0f));
		rect3Layout->setMargin(Thickness(0.0f, 32.0f));
		rect3Layout->setHorizontalAlignment(HorizontalAlignment::Center);
		vertical->addView(rect3, std::move(rect3Layout));

		std::shared_ptr<Font> font = std::make_shared<Font>(RES_DIR "fonts/pixel-font.png", RES_DIR "fonts/pixel-font-values.json");
		auto text1 = std::make_shared<Text>();
		text1->setText(u8"the quick brown fox jumped over the lazy dog");
		text1->setColor(Vec4::one);
		text1->setFont(font);
		auto text1Layout = std::make_unique<VerticalPanel::LayoutParams>();
		text1Layout->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text1, std::move(text1Layout));

		auto text2 = std::make_shared<Text>();
		text2->setText(u8"THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG");
		text2->setColor({ 1.0f, 0.0f, 0.0f, 1.0f });
		text2->setFont(font);
		auto text2Layout = std::make_unique<VerticalPanel::LayoutParams>();
		text2Layout->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text2, std::move(text2Layout));

		auto text3 = std::make_shared<Text>();
		text3->setText(u8"0123456789");
		text3->setColor({ 0.0f, 1.0f, 0.0f, 1.0f });
		text3->setFont(font);
		auto text3Layout = std::make_unique<VerticalPanel::LayoutParams>();
		text3Layout->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text3, std::move(text3Layout));

		auto text4 = std::make_shared<Text>();
		text4->setText(u8"!\"£$%^&*()-_+=[]{};:'@~#<,>.?/`¬¦\\|¥€");
		text4->setColor({ 0.0f, 0.0f, 1.0f, 1.0f });
		text4->setFont(font);
		auto text4Layout = std::make_unique<VerticalPanel::LayoutParams>();
		text4Layout->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text4, std::move(text4Layout));

		setRoot(root);
	}
}