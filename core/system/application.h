#pragma once

#include <vector>
#include "layer_stack.h"

struct SDL_Window;

namespace poseidon
{
	class Application
	{
	public:
		Application();
		~Application();

		void execute();

		inline void addLayer(std::unique_ptr<Layer> layer) { layerStack_.add(std::move(layer)); }

	private:
		LayerStack layerStack_;
		SDL_Window* window_;
		uint64_t lastFrameTime_;
	};
}