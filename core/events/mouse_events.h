#pragma once

#include "event.h"

#include "input/button_codes.h"

namespace poseidon
{
	enum class ButtonState
	{
		Pressed = 1,
		Released = 2
	};

	class MouseButtonEvent : public Event
	{
		inline ButtonCode buttonCode() const { return buttonCode_; }
		inline int32_t x() const { return x_; }
		inline int32_t y() const { return y_; }

	protected:
		MouseButtonEvent(ButtonCode buttonCode, int32_t x, int32_t y);

	private:
		ButtonCode buttonCode_;
		int32_t x_;
		int32_t y_;
	};

	class MouseButtonDownEvent : public MouseButtonEvent
	{
	public:
		MouseButtonDownEvent(ButtonCode buttonCode, int32_t x, int32_t y);

		virtual Type type() const override { return Type::MouseButtonDown; }
	};

	class MouseButtonUpEvent : public MouseButtonEvent
	{
	public:
		MouseButtonUpEvent(ButtonCode buttonCode, int32_t x, int32_t y);

		virtual Type type() const override { return Type::MouseButtonUp; }
	};

	class MouseMotionEvent : public Event
	{
	public:
		MouseMotionEvent(int32_t x, int32_t y, int32_t deltaX, int32_t deltaY);

		virtual Type type() const override { return Type::MouseMotion; }

		inline int32_t x() const { return x_; }
		inline int32_t y() const { return y_; }
		inline int32_t deltaX() const { return deltaX_; }
		inline int32_t deltaY() const { return deltaY_; }

	private:
		int32_t x_;
		int32_t y_;
		int32_t deltaX_;
		int32_t deltaY_;
	};
}