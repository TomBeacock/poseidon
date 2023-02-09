#pragma once

#include <vector>
#include "layer_stack.h"


namespace poseidon
{
	class Window;

	class Application
	{
	public:
		static const Window& window();

	private:
		static Application* instance_;

	public:
		Application();
		~Application();

		void execute();

		inline void addLayer(std::unique_ptr<Layer> layer) { layerStack_.add(std::move(layer)); }

	private:
		LayerStack layerStack_;
		Window* window_;
		uint64_t lastFrameTime_;
	};
}