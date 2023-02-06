#pragma once

#include <vector>
#include <memory>

#include "layer.h"

union SDL_Event;

namespace poseidon
{
	class LayerStack
	{
	public:
		void onUpdate();
		bool onEvent(const SDL_Event& event);

		void add(std::unique_ptr<Layer> layer);

	private:
		std::vector<std::unique_ptr<Layer>> layerStack_;
	};
}