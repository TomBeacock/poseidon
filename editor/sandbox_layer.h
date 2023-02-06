#pragma once

#include <poseidon/core.h>

union SDL_Event;

namespace editor
{
	class SandboxLayer : public poseidon::Layer
	{
	public:
		virtual void onStart() override;
		virtual void onUpdate() override;
		virtual bool onEvent(const SDL_Event& event) override;
	};
}