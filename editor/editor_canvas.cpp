#include "editor_canvas.h"

#include <poseidon/math.h>

using namespace poseidon;

namespace editor
{
	EditorCanvas::EditorCanvas()
	{
		auto root = std::make_shared<HorizontalPanel>();

		auto rect1 = std::make_shared<Rectangle>();
		rect1->setLayoutParams(std::make_unique<LayoutParams>(Dimension::fillParent, Dimension::fillParent));
		rect1->setColor(Vec4(1.0f, 1.0f, 0.0f, 1.0f));
		root->addView(rect1);

		auto vertical = std::make_shared<VerticalPanel>();
		vertical->setLayoutParams(std::make_unique<LayoutParams>(Dimension::fillParent, Dimension::fillParent));

		auto rect2 = std::make_shared<Rectangle>();
		rect2->setLayoutParams(std::make_unique<LayoutParams>(Dimension(128.0f), Dimension::fillParent));
		rect2->setHorizontalAlignment(HorizontalAlignment::Right);
		rect2->setColor(Vec4(0.0f, 1.0f, 1.0f, 1.0f));
		vertical->addView(rect2);

		auto rect3 = std::make_shared<Rectangle>();
		rect3->setLayoutParams(std::make_unique<LayoutParams>(Dimension(256.0f), Dimension(128.0f)));
		rect3->setHorizontalAlignment(HorizontalAlignment::Center);
		rect3->setColor(Vec4(1.0f, 0.0f, 1.0f, 1.0f));
		vertical->addView(rect3);

		root->addView(vertical);

		setRoot(root);
	}
}