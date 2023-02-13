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

		auto rect2 = std::make_shared<Rectangle>();
		rect2->setLayoutParams(std::make_unique<LayoutParams>(Dimension::fillParent, Dimension(256.0f)));
		rect2->setVerticalAlignment(VerticalAlignment::Bottom);
		rect2->setColor(Vec4(0.0f, 1.0f, 1.0f, 1.0f));
		root->addView(rect2);

		setRoot(root);
	}
}