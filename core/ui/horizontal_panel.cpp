#include "horizontal_panel.h"

namespace poseidon
{
	const Vec2& HorizontalPanel::onMeasure()
	{
		measureChildren();

		Vec2 size;
		for (const auto& child : children())
		{
			size.x += child->measuredWidth();
			size.y = std::max(size.y, child->measuredHeight());
		}
		return size + margin().size();
	}

	void HorizontalPanel::onLayout(const Vec2& position, const Vec2& size)
	{
		Vec2 p, s;
		calculateChildArea(p, s);

		// Width pass
		float fixedWidth = 0.0f;
		unsigned int fillCount = 0;

		for (const auto& child : children())
		{
			if (child->autoWidth())
			{
				if (child->horizontalAlignment() == HorizontalAlignment::Fill)
					++fillCount;
				else
					fixedWidth += child->measuredWidth();
			}
			else
				fixedWidth += child->preferredWidth();
		}

		float fillWidth = (s.x - fixedWidth) / (float)fillCount;

		// Layout pass
		Vec2 childPos = p;
		for (const auto& child : children())
		{
			Vec2 childSize;
			// Child width
			if (child->autoWidth())
			{
				if (child->horizontalAlignment() == HorizontalAlignment::Fill)
					childSize.x = fillWidth;
				else
					childSize.x = child->measuredWidth();
			}
			else
				childSize.x = child->preferredWidth();

			// Child y and height
			childPos.y = p.y;
			childSize.y = child->measuredHeight();
			switch (child->verticalAlignment())
			{
			case VerticalAlignment::Top: break;
			case VerticalAlignment::Center: childPos.y += (s.y - childSize.y) / 2.0f; break;
			case VerticalAlignment::Bottom: childPos.y += s.y - childSize.y; break;
			case VerticalAlignment::Fill: childSize.y = s.y; break;
			}

			const Thickness& m = child->margin();
			child->layout(childPos + Vec2(m.left, m.top), childSize - m.size());
			childPos.x += childSize.x;
		}
	}
}