#pragma once

#include "event.h"

#include <cstdint>

namespace poseidon
{
	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int32_t x, int32_t y);

		virtual Type type() const override { return Type::WindowMoved; }

		inline int32_t x() const { return x_; }
		inline int32_t y() const { return y_; }

	private:
		int32_t x_;
		int32_t y_;
	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int32_t width, int32_t height);

		virtual Type type() const override { return Type::WindowResized; }

		inline int32_t width() const { return width_; }
		inline int32_t height() const { return height_; }

	private:
		int32_t width_;
		int32_t height_;
	};

	class WindowSizeChangedEvent : public Event
	{
	public:
		WindowSizeChangedEvent(int32_t width, int32_t height);

		virtual Type type() const override { return Type::WindowSizeChanged; }

		inline int32_t width() const { return width_; }
		inline int32_t height() const { return height_; }

	private:
		int32_t width_;
		int32_t height_;
	};

	class WindowMinimizedEvent : public Event
	{
	public:
		virtual Type type() const override { return Type::WindowMinimized; }
	};

	class WindowMaximizedEvent : public Event
	{
	public:
		virtual Type type() const override { return Type::WindowMaximized; }
	};

	class WindowRestoredEvent : public Event
	{
	public:
		virtual Type type() const override { return Type::WindowRestored; }
	};

	class WindowFocusGainedEvent : public Event
	{
	public:
		virtual Type type() const override { return Type::WindowFocusGained; }
	};

	class WindowFocusLostEvent : public Event
	{
	public:
		virtual Type type() const override { return Type::WindowFocusLost; }
	};

	class WindowCloseEvent : public Event
	{
	public:
		virtual Type type() const override { return Type::WindowClose; }
	};
}