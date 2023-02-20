#include "anchor_panel.h"

#include <iostream>

namespace poseidon
{
	AnchorPanel::LayoutParams::LayoutParams() :
		poseidon::LayoutParams(),
		position_(), pivot_(),
		anchorMin_(), anchorMax_(),
		offset_() {}

	AnchorPanel::LayoutParams::LayoutParams(const Size& width, const Size& height) :
		poseidon::LayoutParams(width, height),
		position_(), pivot_(),
		anchorMin_(), anchorMax_(),
		offset_() {}

	AnchorPanel::LayoutParams::LayoutParams(float width, float height) :
		poseidon::LayoutParams(width, height),
		position_(), pivot_(),
		anchorMin_(), anchorMax_(),
		offset_() {}

	Vec2 AnchorPanel::onMeasure()
	{
		measureChildren();

		Vec2 size;
		for (const auto& child : children())
		{
			const Vec2& childSize = child->measuredSize();
			try
			{
				const auto& layout = dynamic_cast<const AnchorPanel::LayoutParams&>(child->layoutParams());
				const Vec2& position = layout.position();
				const Vec2& pivot = layout.pivot();
				const Vec2& anchorMin = layout.anchorMin();
				const Vec2& anchorMax = layout.anchorMax();
				const Thickness& offset = layout.offset();

				// Horizontal fixed
				if (anchorMin.x == anchorMax.x)
				{
					float left = position.x - (pivot.x * childSize.x);
					float right = position.x + ((1.0f - pivot.x) * childSize.x);

					// Include anchor offset in width
					float width = childSize.x;
					if (left > 0.0f)
						width = right / (1.0f - anchorMin.x);
					else if (right < 0.0f)
						width = -left / anchorMin.x;

					size.x = std::max(size.x, width);
				}
				// Horizontal stretch
				else
				{
					float percentWidth = anchorMax.x - anchorMin.x;
					float width = (childSize.x + offset.horizontal()) / percentWidth;
					size.x = std::max(size.x, width);
				}

				// Vertical fixed
				if (anchorMin.y == anchorMax.y)
				{
					float top = position.y - (pivot.y * childSize.y);
					float bottom = position.y + ((1.0f - pivot.y) * childSize.y);

					// Include anchor offset in height
					float height = childSize.y;
					if (top > 0.0f)
						height = bottom / (1.0f - anchorMin.y);
					else if (bottom < 0.0f)
						height = -top / anchorMin.y;

					size.y = std::max(size.y, height);
				}
				// Vertical stretch
				else
				{
					float percentHeight = anchorMax.y - anchorMin.y;
					float height = (childSize.y + offset.vertical()) / percentHeight;
					size.y = std::max(size.y, height);
				}
			}
			catch(std::bad_cast e)
			{
				size.x = std::max(size.x, childSize.x);
				size.y = std::max(size.y, childSize.y);
			}
		}
		return size;
	}

	void AnchorPanel::onLayout(const Vec2& position, const Vec2& size)
	{
		for (const auto& child : children())
		{
			try
			{
				const auto& layout = dynamic_cast<const AnchorPanel::LayoutParams&>(child->layoutParams());
				const Vec2& position = layout.position();
				const Vec2& pivot = layout.pivot();
				const Vec2& anchorMin = layout.anchorMin();
				const Vec2& anchorMax = layout.anchorMax();
				const Thickness& offset = layout.offset();

				Vec2 childPos;
				Vec2 childSize;

				// Horizontal fixed
				if (anchorMin.x == anchorMax.x)
				{
					float pivotPos = (anchorMin.x * actualSize().x) + position.x;
					childPos.x = pivotPos - (pivot.x * child->measuredWidth());
					childSize.x = child->measuredWidth();
				}
				// Horizontal stretch
				else
				{
					childPos.x = (anchorMin.x * actualSize().x) + offset.left;
					childSize.x = ((anchorMax.x - anchorMin.x) * actualSize().x) - offset.horizontal();
				}

				// Vertical fixed
				if (anchorMin.y == anchorMax.y)
				{
					float pivotPos = (anchorMin.y * actualSize().y) + position.y;
					childPos.y = pivotPos - (pivot.y * child->measuredHeight());
					childSize.y = child->measuredHeight();
				}
				// Vertical stretch
				else
				{
					childPos.y = (anchorMin.y * actualSize().y) + offset.top;
					childSize.y = ((anchorMax.y - anchorMin.y) * actualSize().y) - offset.vertical();
				}

				child->layout(childPos, childSize);
			}
			catch (std::bad_cast e)
			{
				child->layout(Vec2::zero, child->measuredSize());
			}
		}
	}
}