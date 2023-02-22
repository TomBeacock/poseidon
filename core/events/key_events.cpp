#include "key_events.h"

namespace poseidon
{
	KeyEvent::KeyEvent(KeyCode keyCode, ScanCode scanCode, KeyModifiers modifiers) :
		keyCode_(keyCode), scanCode_(scanCode), modifiers_(modifiers) {}

	KeyDownEvent::KeyDownEvent(KeyCode keyCode, ScanCode scanCode, KeyModifiers modifiers, uint32_t repeat) :
		KeyEvent(keyCode, scanCode, modifiers), repeat_(repeat) {}

	KeyUpEvent::KeyUpEvent(KeyCode keyCode, ScanCode scanCode, KeyModifiers modifiers) :
		KeyEvent(keyCode, scanCode, modifiers) {}
}