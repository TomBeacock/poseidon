#include "vertical_panel.h"

namespace poseidon
{
	void VerticalPanel::onMeasure()
	{
		measureChildren();

		Vec2 size;
		for (const auto& child : children())
		{
			size.y += child->measuredHeight();
			size.x = std::max(size.x, child->measuredWidth());
		}
		setMeasuredSize(size);
	}

	void VerticalPanel::onLayout(const Vec2& position, const Vec2& size)
	{
		// Height pass
		float fixedHeight = 0.0f;
		unsigned int fillCount = 0;

		for (const auto& child : children())
		{
			switch (child->layoutParams().height().type())
			{
			case Dimension::Type::FillParent: ++fillCount; break;
			case Dimension::Type::WrapContent: fixedHeight += child->measuredHeight(); break;
			case Dimension::Type::Exact: fixedHeight += child->layoutParams().height().size(); break;
			}
		}

		float fillHeight = (size.y - fixedHeight) / (float)fillCount;

		// Layout pass
		float y = 0.0f;
		for (const auto& child : children())
		{
			float height = 0.0f;
			switch (child->layoutParams().height().type())
			{
			case Dimension::Type::FillParent: height = fillHeight; break;
			case Dimension::Type::WrapContent: height = child->measuredHeight(); break;
			case Dimension::Type::Exact: height = child->layoutParams().height().size(); break;
			}

			float width = 0.0f;
			switch (child->layoutParams().width().type())
			{
			case Dimension::Type::FillParent: width = size.x; break;
			case Dimension::Type::WrapContent: width = child->measuredWidth(); break;
			case Dimension::Type::Exact: width = child->layoutParams().width().size(); break;
			}

			float x = 0.0f;
			switch (child->horizontalAlignment())
			{
			case HorizontalAlignment::Left: break;
			case HorizontalAlignment::Center: x = (size.x - width) / 2.0f; break;
			case HorizontalAlignment::Right: x = size.x - width;
			}

			child->layout({ x, y }, { width, height });
			y += height;
		}
	}
}