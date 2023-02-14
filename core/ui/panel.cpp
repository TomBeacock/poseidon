#include "panel.h"

namespace poseidon
{
	Panel::Panel() :
		padding_() {}

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

	void Panel::calculateChildArea(Vec2& position, Vec2& size)
	{
		position = Vec2(margin().left, margin().top) + Vec2(padding_.left, padding_.top);
		size = actualSize() - margin().size() - padding_.size();
	}
}