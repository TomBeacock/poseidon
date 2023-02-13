#include "horizontal_panel.h"

#include "ui/layout_params.h"

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
		setMeasuredSize(size);
	}

	void HorizontalPanel::onLayout(const Vec2& position, const Vec2& size)
	{
		// Width pass
		float fixedWidth = 0.0f;
		unsigned int fillCount = 0;

		for (const auto& child : children())
		{
			switch (child->layoutParams().width().type())
			{
			case Dimension::Type::FillParent: ++fillCount; break;
			case Dimension::Type::WrapContent: fixedWidth += child->measuredWidth(); break;
			case Dimension::Type::Exact: fixedWidth += child->layoutParams().width().size(); break;
			}
		}

		float fillWidth = (size.x - fixedWidth) / (float)fillCount;

		// Layout pass
		float x = 0.0f;
		for (const auto& child : children())
		{
			float width = 0.0f;
			switch (child->layoutParams().width().type())
			{
			case Dimension::Type::FillParent: width = fillWidth; break;
			case Dimension::Type::WrapContent: width = child->measuredWidth(); break;
			case Dimension::Type::Exact: width = child->layoutParams().width().size(); break;
			}

			float height = 0.0f;
			switch (child->layoutParams().height().type())
			{
			case Dimension::Type::FillParent: height = size.y; break;
			case Dimension::Type::WrapContent: height = child->measuredHeight(); break;
			case Dimension::Type::Exact: height = child->layoutParams().height().size(); break;
			}

			float y = 0.0f;
			switch (child->verticalAlignment())
			{
			case VerticalAlignment::Top: break;
			case VerticalAlignment::Center: y = (size.y - height) / 2.0f; break;
			case VerticalAlignment::Bottom: y = size.y - height;
			}

			child->layout({ x, y }, { width, height });
			x += width;
		}
	}
}