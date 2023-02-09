#include "panel.h"

namespace poseidon
{
	void Panel::onDraw()
	{

	}

	void Panel::measureChildren()
	{
		for (auto& child : children_)
			child->measure();
	}
}