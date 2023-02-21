#include "events.h"

namespace poseidon
{
	KeyEvent::KeyEvent(KeyCode key, KeyModifier modifier) :
		key(key), modifier(modifier) {}
}