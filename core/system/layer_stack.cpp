#include "layer_stack.h"

#include "layer.h"

namespace poseidon
{
	void LayerStack::onUpdate()
	{
		for (auto& layer : layerStack_)
		{
			layer->onUpdate();
		}
	}

	bool LayerStack::onEvent(const SDL_Event& event)
	{
		for (auto& layer : layerStack_)
		{
			if (layer->onEvent(event))
				return true;
		}
		return false;
	}

	void LayerStack::add(std::unique_ptr<Layer> layer)
	{
		layerStack_.push_back(std::move(layer));
		layerStack_.back()->onStart();
	}
}