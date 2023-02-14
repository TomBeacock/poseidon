#include "thickness.h"

namespace poseidon
{
	Thickness::Thickness() :
		left(0.0f), right(0.0f), top(0.0f), bottom(0.0f) {}

	Thickness::Thickness(float thickness) :
		left(thickness), right(thickness),
		top(thickness), bottom(thickness) {}

	Thickness::Thickness(float horizontal, float vertical) :
		left(horizontal), right(horizontal),
		top(vertical), bottom(vertical) {}

	Thickness::Thickness(float left, float right, float top, float bottom) :
		left(left), right(right), top(top), bottom(bottom) {}
}