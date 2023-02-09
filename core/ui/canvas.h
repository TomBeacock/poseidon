#pragma once

#include <memory>

#include "system/layer.h"
#include "math/mat4.h"

namespace poseidon
{
	struct VisualElement;

	class Canvas : public Layer
	{
	public:
		Canvas();
		~Canvas();

		virtual void onStart() final;
		virtual void onUpdate(float deltaTime) final;
		virtual bool onEvent(const SDL_Event& event) final;

		void setRoot(std::shared_ptr<VisualElement> root);

	private:
		void layout();
		void paint();

	private:
		std::shared_ptr<VisualElement> root_;
		Mat4 projection_;
	};
}