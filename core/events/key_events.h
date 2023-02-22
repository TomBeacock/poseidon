#pragma once

#include "event.h"

#include "input/key_codes.h"

namespace poseidon
{
	class KeyEvent : public Event
	{
		inline KeyCode keyCode() const { return keyCode_; }
		inline ScanCode scanCode() const { return scanCode_; }
		inline KeyModifiers modifiers() const { return modifiers_; }

		inline bool isShiftDown() const { return (modifiers_ & KeyModifiers::Shift) != KeyModifiers::None; }
		inline bool isCtrlDown() const { return (modifiers_ & KeyModifiers::Ctrl) != KeyModifiers::None; }
		inline bool isAltDown() const { return (modifiers_ & KeyModifiers::Alt) != KeyModifiers::None; }

	protected:
		KeyEvent(KeyCode keyCode, ScanCode scanCode, KeyModifiers modifiers);

	private:
		KeyCode keyCode_;
		ScanCode scanCode_;
		KeyModifiers modifiers_;
	};

	class KeyDownEvent : public KeyEvent
	{
	public:
		KeyDownEvent(KeyCode keyCode, ScanCode scanCode, KeyModifiers modifiers, uint32_t repeat);

		virtual Type type() const override { return Type::KeyDown; }

		inline uint32_t repeat() const { return repeat_; }

	private:
		uint32_t repeat_;
	};

	class KeyUpEvent : public KeyEvent
	{
	public:
		KeyUpEvent(KeyCode keyCode, ScanCode scanCode, KeyModifiers modifiers);

		virtual Type type() const override { return Type::KeyUp; }
	};
}