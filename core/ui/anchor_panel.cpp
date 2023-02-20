#include "anchor_panel.h"

#include <iostream>

namespace poseidon
{
	AnchorPanel::LayoutParams::LayoutParams() :
		poseidon::LayoutParams(), x_(0.0f), y_(0.0f) {}

	AnchorPanel::LayoutParams::LayoutParams(const Size& width, const Size& height, float x, float y) :
		poseidon::LayoutParams(width, height), x_(x), y_(y) {}

	AnchorPanel::LayoutParams::LayoutParams(float width, float height, float x, float y) :
		poseidon::LayoutParams(width, height), x_(x), y_(y) {}

	Vec2 AnchorPanel::onMeasure()
	{
		measureChildren();

		Vec2 size;
		for (const auto& child : children())
		{
			const Vec2& childPos = child->actualPosition();
			const Vec2& childSize = child->actualSize();
			size.x = std::max(size.x, childPos.x + childSize.x);
			size.y = std::max(size.y, childPos.y + childSize.y);
		}
		return size;
	}

	void AnchorPanel::onLayout(const Vec2& position, const Vec2& size)
	{
		for (const auto& child : children())
		{
			Vec2 childPos;
			try { childPos = dynamic_cast<const AnchorPanel::LayoutParams&>(child->layoutParams()).position(); }
			catch (std::bad_cast e) { std::cerr << "Failed to cast to anchor layout: " << e.what() << std::endl; }

			child->layout(childPos, child->measuredSize());
		}
	}
}