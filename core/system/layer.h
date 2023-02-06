#pragma once

union SDL_Event;

namespace poseidon
{
	class Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void onStart() = 0;
		virtual void onUpdate() = 0;
		virtual bool onEvent(const SDL_Event& event) = 0;
	};
}