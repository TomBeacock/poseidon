#include "horizontal_panel.h"

#include <iostream>

namespace poseidon
{
	HorizontalPanel::LayoutParams::LayoutParams() :
		MarginLayoutParams(), verticalAlignment_(VerticalAlignment::Top) {}
	HorizontalPanel::LayoutParams::LayoutParams(const Size& width, const Size& height) :
		MarginLayoutParams(width, height), verticalAlignment_(VerticalAlignment::Top) {}
	HorizontalPanel::LayoutParams::LayoutParams(float width, float height) :
		MarginLayoutParams(width, height), verticalAlignment_(VerticalAlignment::Top) {}

	Vec2 HorizontalPanel::onMeasure()
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

			size.x += child->measuredWidth() + margin.horizontal();
			size.y = std::max(size.y, child->measuredHeight() + margin.vertical());
		}

		size.x = layout.width().type() == Size::Type::Exact ? layout.exactWidth() : size.x;
		size.y = layout.height().type() == Size::Type::Exact ? layout.exactHeight() : size.y;

		return size + padding().size();
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
			const poseidon::LayoutParams& childLayout = child->layoutParams();

			Thickness childMargin;
			try { childMargin = dynamic_cast<const MarginLayoutParams&>(childLayout).margin(); }
			catch (std::bad_cast e) { std::cerr << "Failed to cast to margin layout: " << e.what() << std::endl; }

			if (childLayout.width().type() == Size::Type::Fill)
				++fillCount;
			else
				fixedWidth += child->measuredWidth() + childMargin.horizontal();
		}

		float fillWidth = (s.x - fixedWidth) / (float)fillCount;

		// Layout pass
		Vec2 childPos = p;
		for (const auto& child : children())
		{
			const poseidon::LayoutParams& childLayout = child->layoutParams();

			Thickness margin;
			try { margin = dynamic_cast<const MarginLayoutParams&>(childLayout).margin(); }
			catch (std::bad_cast e) { std::cerr << "Failed to cast to margin layout: " << e.what() << std::endl; }

			Vec2 childSize;

			// Horizontal
			childPos.x += margin.left;
			if (childLayout.width().type() == Size::Type::Fill)
				childSize.x = fillWidth - margin.horizontal();
			else
				childSize.x = child->measuredWidth();

			// Vertical
			childPos.y = p.y;

			if (childLayout.height().type() == Size::Type::Fill)
			{
				childPos.y += margin.top;
				childSize.y = s.y - margin.vertical();
			}
			else
			{
				childSize.y = child->measuredHeight();
				try
				{ 
					switch (dynamic_cast<const LayoutParams&>(childLayout).verticalAlignment())
					{
					case VerticalAlignment::Top: childPos.y += margin.top; break;
					case VerticalAlignment::Center: childPos.y += (s.x - (childSize.y + margin.vertical())) / 2.0f; break;
					case VerticalAlignment::Bottom: childPos.y += s.x - (childSize.y + margin.bottom); break;
					}
				}
				catch (std::bad_cast e) { std::cerr << "Failed to cast to horizontal layout: " << e.what() << std::endl;  }
			}

			child->layout(childPos, childSize);
			childPos.x += childSize.x + margin.right;
		}
	}
}