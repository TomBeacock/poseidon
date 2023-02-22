#pragma once

#include <memory>

#include "system/layer.h"
#include "math/mat4.h"

namespace poseidon
{
	class Widget;

	class Canvas : public Layer
	{
	public:
		Canvas();
		~Canvas();

		virtual void onStart() final;
		virtual void onUpdate(float deltaTime) final;
		virtual bool onEvent(const Event& event) final;

		void setRoot(std::shared_ptr<Widget> root);

	private:
		void measure();
		void layout();
		void paint();

	private:
		std::shared_ptr<Widget> root_;
		std::weak_ptr<Widget> hovered_;
		std::weak_ptr<Widget> focused_;
		Mat4 projection_;
	};
}