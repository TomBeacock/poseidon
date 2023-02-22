#pragma once

namespace poseidon
{
	class Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void onStart() = 0;
		virtual void onUpdate(float deltaTime) = 0;
		virtual bool onEvent(const class Event& event) = 0;
	};
}