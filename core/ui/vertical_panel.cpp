#include "vertical_panel.h"

namespace poseidon
{
	const Vec2& VerticalPanel::onMeasure()
	{
		measureChildren();

		Vec2 size;
		for (const auto& child : children())
		{
			size.y += child->measuredHeight();
			size.x = std::max(size.x, child->measuredWidth());
		}
		return size + margin().size();
	}

	void VerticalPanel::onLayout(const Vec2& position, const Vec2& size)
	{
		Vec2 p, s;
		calculateChildArea(p, s);

		// Height pass
		float fixedHeight = 0.0f;
		unsigned int fillCount = 0;

		for (const auto& child : children())
		{
			if (child->autoHeight())
			{
				if (child->verticalAlignment() == VerticalAlignment::Fill)
					++fillCount;
				else
					fixedHeight += child->measuredHeight();
			}
			else
				fixedHeight += child->preferredHeight();
		}

		float fillHeight = (s.y - fixedHeight) / (float)fillCount;

		// Layout pass
		Vec2 childPos = p;
		for (const auto& child : children())
		{
			Vec2 childSize;
			// Child height
			if (child->autoHeight())
			{
				if (child->verticalAlignment() == VerticalAlignment::Fill)
					childSize.y = fillHeight;
				else
					childSize.y = child->measuredHeight();
			}
			else
				childSize.y = child->preferredHeight();

			// Child x and width
			childPos.x = p.x;
			childSize.x = child->measuredWidth();
			switch (child->horizontalAlignment())
			{
			case HorizontalAlignment::Left: break;
			case HorizontalAlignment::Center: childPos.x += (s.x - childSize.x) / 2.0f; break;
			case HorizontalAlignment::Right: childPos.x += s.x - childSize.x; break;
			case HorizontalAlignment::Fill: childSize.x = s.x; break;
			}

			const Thickness& m = child->margin();
			child->layout(childPos + Vec2(m.left, m.top), childSize - m.size());
			childPos.y += childSize.y;
		}
	}
}