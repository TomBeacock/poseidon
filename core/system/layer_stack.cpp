#include "layer_stack.h"

#include "layer.h"
#include "events/event.h"

namespace poseidon
{
	void LayerStack::onUpdate(float deltaTime)
	{
		for (auto& layer : layerStack_)
		{
			layer->onUpdate(deltaTime);
		}
	}

	bool LayerStack::onEvent(const Event& event)
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