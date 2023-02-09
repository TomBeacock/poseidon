#include "horizontal_panel.h"

namespace poseidon
{
	void HorizontalPanel::onMeasure()
	{
		measureChildren();

		Vec2 size;
		for (const auto& child : children())
		{
			size.x += child->measuredWidth();
			size.y = std::max(size.y, child->measuredHeight());
		}
		setDesiredSize(size);
	}

	void HorizontalPanel::onLayout(float left, float right, float top, float bottom)
	{
		float x = left;

		for (const auto& child : children())
		{
			float width = child->measuredWidth();
			child->layout(x, x + width, top, bottom);
			x += width;
		}
	}
}