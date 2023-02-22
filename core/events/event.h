#pragma once

namespace poseidon
{
	class Event
	{
	public:
		enum class Type
		{
			None = 0,
			MouseMotion,
			MouseButtonDown, MouseButtonUp,
			KeyDown, KeyUp,
			WindowMoved, WindowResized, WindowSizeChanged, WindowMinimized, WindowMaximized, WindowRestored,
			WindowFocusGained, WindowFocusLost, WindowClose
		};

		virtual ~Event() = default;

		virtual Type type() const = 0;

	protected:
		Event() = default;
	};
}