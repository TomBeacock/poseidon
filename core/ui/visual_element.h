#pragma once

#include "math/vec2.h"

namespace poseidon
{
	struct VisualElement
	{
		Vec2 position;
		Vec2 size;

		void layout();
		void paint();
	};
}