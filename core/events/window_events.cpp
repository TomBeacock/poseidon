#include "window_events.h"

namespace poseidon
{
	WindowMovedEvent::WindowMovedEvent(int32_t x, int32_t y) :
		x_(x), y_(y) {}

	WindowResizedEvent::WindowResizedEvent(int32_t width, int32_t height) :
		width_(width), height_(height) {}

	WindowSizeChangedEvent::WindowSizeChangedEvent(int32_t width, int32_t height) :
		width_(width), height_(height) {}
}