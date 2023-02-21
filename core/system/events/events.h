#pragma once

#include "keycode.h"

namespace poseidon
{
	struct Event
	{

	};

	struct KeyEvent : public Event
	{
		KeyCode key;
		KeyModifier modifier;

		KeyEvent(KeyCode key, KeyModifier modifier);
	};
}