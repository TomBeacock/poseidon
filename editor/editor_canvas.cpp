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
		rect1->setHorizontalAlignment(HorizontalAlignment::Fill);
		rect1->setVerticalAlignment(VerticalAlignment::Fill);
		rect1->setMargin(Thickness(16.0f, 32.0f, 64.0f, 128.0f));
		rect1->setColor(Vec4(1.0f, 1.0f, 0.0f, 1.0f));
		root->addView(rect1);

		auto vertical = std::make_shared<VerticalPanel>();
		vertical->setHorizontalAlignment(HorizontalAlignment::Fill);
		vertical->setVerticalAlignment(VerticalAlignment::Fill);

		auto rect2 = std::make_shared<Rectangle>();
		rect2->setPreferredWidth(128.0f);
		rect2->setHorizontalAlignment(HorizontalAlignment::Right);
		rect2->setVerticalAlignment(VerticalAlignment::Fill);
		rect2->setColor(Vec4(0.0f, 1.0f, 1.0f, 1.0f));
		vertical->addView(rect2);

		auto rect3 = std::make_shared<Rectangle>();
		rect3->setHorizontalAlignment(HorizontalAlignment::Center);
		rect3->setMargin(Thickness(0.0f, 32.0f));
		rect3->setPreferredSize({ 256.0f, 128.0f });
		rect3->setColor(Vec4(1.0f, 0.0f, 1.0f, 1.0f));
		vertical->addView(rect3);

		std::shared_ptr<Font> font = std::make_shared<Font>(RES_DIR "fonts/pixel-font.png", RES_DIR "fonts/pixel-font-values.json");
		auto text1 = std::make_shared<Text>();
		text1->setText(u8"the quick brown fox jumped over the lazy dog");
		text1->setFont(font);
		text1->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text1);

		auto text2 = std::make_shared<Text>();
		text2->setText(u8"THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG");
		text2->setFont(font);
		text2->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text2);

		auto text3 = std::make_shared<Text>();
		text3->setText(u8"0123456789");
		text3->setFont(font);
		text3->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text3);

		auto text4 = std::make_shared<Text>();
		text4->setText(u8"!\"£$%^&*()-_+=[]{};:'@~#<,>.?/`¬¦\\|¥€");
		text4->setFont(font);
		text4->setMargin(Thickness(0.0f, 1.0f));
		vertical->addView(text4);

		root->addView(vertical);

		setRoot(root);
	}
}