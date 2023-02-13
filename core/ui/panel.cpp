#include "panel.h"

namespace poseidon
{
	void Panel::onDraw(const Vec2& relativeOrigin)
	{
		Vec2 newRelativeOrigin = relativeOrigin + actualPosition();
		for (auto& child : children_)
			child->draw(newRelativeOrigin);
	}

	void Panel::measureChildren()
	{
		for (auto& child : children_)
			child->measure();
	}
}