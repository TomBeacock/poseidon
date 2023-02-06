#pragma once

#include <vector>
#include "layer_stack.h"

namespace poseidon
{
	class Application
	{
	public:
		void execute();

		inline void addLayer(std::unique_ptr<Layer> layer) { layerStack_.add(std::move(layer)); }

	private:
		LayerStack layerStack_;
	};
}