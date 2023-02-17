#include "vertical_panel.h"

#include <iostream>

namespace poseidon
{
	VerticalPanel::LayoutParams::LayoutParams() :
		MarginLayoutParams(), horizontalAlignment_(HorizontalAlignment::Left) {}
	VerticalPanel::LayoutParams::LayoutParams(const Size& width, const Size& height) :
		MarginLayoutParams(width, height), horizontalAlignment_(HorizontalAlignment::Left) {}
	VerticalPanel::LayoutParams::LayoutParams(float width, float height) :
		MarginLayoutParams(width, height), horizontalAlignment_(HorizontalAlignment::Left) {}

	Vec2 VerticalPanel::onMeasure()
	{
		measureChildren();

		const poseidon::LayoutParams& layout = layoutParams();

		if (layout.width().type() == Size::Type::Exact &&
			layout.height().type() == Size::Type::Exact)
			return layout.exactSize();

		Vec2 size;
		for (const auto& child : children())
		{
			Thickness margin;
			try { margin = dynamic_cast<const MarginLayoutParams&>(child->layoutParams()).margin(); }
			catch (std::bad_cast e) { std::cerr << "Failed to cast to margin layout: " << e.what() << std::endl; }

			size.y += child->measuredHeight() + margin.vertical();
			size.x = std::max(size.x, child->measuredWidth() + margin.horizontal());
		}

		size.x = layout.width().type() == Size::Type::Exact ? layout.exactWidth() : size.x;
		size.y = layout.height().type() == Size::Type::Exact ? layout.exactHeight() : size.y;

		return size;
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
			const poseidon::LayoutParams& childLayout = child->layoutParams();

			Thickness childMargin;
			try { childMargin = dynamic_cast<const MarginLayoutParams&>(childLayout).margin(); }
			catch (std::bad_cast e) { std::cerr << "Failed to cast to margin layout: " << e.what() << std::endl; }

			if (childLayout.height().type() == Size::Type::Fill)
				++fillCount;
			else
				fixedHeight += child->measuredHeight() + childMargin.vertical();
		}

		float fillHeight = (s.y - fixedHeight) / (float)fillCount;

		// Layout pass
		Vec2 childPos = p;
		for (const auto& child : children())
		{
			const poseidon::LayoutParams& childLayout = child->layoutParams();

			Thickness margin;
			try { margin = dynamic_cast<const MarginLayoutParams&>(childLayout).margin(); }
			catch (std::bad_cast e) { std::cerr << "Failed to cast to margin layout: " << e.what() << std::endl; }

			Vec2 childSize;

			// Vertical
			childPos.y += margin.top;
			if (childLayout.height().type() == Size::Type::Fill)
				childSize.y = fillHeight - margin.vertical();
			else
				childSize.y = child->measuredHeight();

			// Horizontal
			childPos.x = p.x;

			if (childLayout.width().type() == Size::Type::Fill)
			{
				childPos.x += margin.left;
				childSize.x = s.x - margin.horizontal();
			}
			else
			{
				childSize.x = child->measuredWidth();
				try
				{
					switch (dynamic_cast<const LayoutParams&>(childLayout).horizontalAlignment())
					{
					case HorizontalAlignment::Left: childPos.x += margin.left; break;
					case HorizontalAlignment::Center: childPos.x += (s.x - (childSize.x + margin.horizontal())) / 2.0f; break;
					case HorizontalAlignment::Right: childPos.x += s.x - (childSize.x + margin.right); break;
					}
				}
				catch (std::bad_cast e) { std::cerr << "Failed to cast to vertical layout: " << e.what() << std::endl; }
			}

			child->layout(childPos, childSize);
			childPos.y += childSize.y + margin.bottom;
		}
	}
}