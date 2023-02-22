#pragma once

#include <vector>
#include <memory>

#include "layer.h"

namespace poseidon
{
	class LayerStack
	{
	public:
		void onUpdate(float deltaTime);
		bool onEvent(const class Event& event);

		void add(std::unique_ptr<Layer> layer);

	private:
		std::vector<std::unique_ptr<Layer>> layerStack_;
	};
}