#pragma once

#include "math/vec2.h"

namespace poseidon
{
	struct Thickness
	{
		float left;
		float right;
		float top;
		float bottom;

		Thickness();
		Thickness(float thickness);
		Thickness(float horizontal, float vertical);
		Thickness(float left, float right, float top, float bottom);

		inline float horizontal() const { return left + right; }
		inline float vertical() const { return top + bottom; }
		inline Vec2 size() const { return { left + right, top + bottom }; }
	};
}