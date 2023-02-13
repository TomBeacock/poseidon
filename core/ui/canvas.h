#pragma once

#include <memory>

#include "system/layer.h"
#include "math/mat4.h"

namespace poseidon
{
	class View;

	class Canvas : public Layer
	{
	public:
		Canvas();
		~Canvas();

		virtual void onStart() final;
		virtual void onUpdate(float deltaTime) final;
		virtual bool onEvent(const SDL_Event& event) final;

		void setRoot(std::shared_ptr<View> root);

	private:
		void measure();
		void layout();
		void paint();

	private:
		std::shared_ptr<View> root_;
		Mat4 projection_;
	};
}