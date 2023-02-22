#include "mouse_events.h"

namespace poseidon
{
	MouseButtonEvent::MouseButtonEvent(ButtonCode buttonCode, int32_t x, int32_t y) :
		buttonCode_(buttonCode), x_(x), y_(y) {}

	MouseButtonDownEvent::MouseButtonDownEvent(ButtonCode buttonCode, int32_t x, int32_t y) :
		MouseButtonEvent(buttonCode, x, y) {}

	MouseButtonUpEvent::MouseButtonUpEvent(ButtonCode buttonCode, int32_t x, int32_t y) :
		MouseButtonEvent(buttonCode, x, y) {}

	MouseMotionEvent::MouseMotionEvent(int32_t x, int32_t y, int32_t deltaX, int32_t deltaY) :
		x_(x), y_(y), deltaX_(deltaY), deltaY_(deltaY) {}
}