#include "canvas.h"

#include <SDL.h>

#include "system/application.h"
#include "system/window.h"
#include "rendering/renderer2d.h"
#include "view.h"

namespace poseidon
{
	Canvas::Canvas() : root_(nullptr), projection_(Mat4::identity)
	{

	}

	Canvas::~Canvas()
	{

	}

	void Canvas::onStart()
	{
		float width = (float)Application::window().width();
		float height = (float)Application::window().height();
		projection_ = Mat4::orthoOffCenter(0.0f, width, 0.0f, height);
	}

	void Canvas::onUpdate(float deltaTime)
	{
		measure();
		layout();
		paint();
	}

	bool Canvas::onEvent(const SDL_Event& event)
	{
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			float width = (float)event.window.data1;
			float height = (float)event.window.data2;
			projection_ = Mat4::orthoOffCenter(0.0f, width, 0.0f, height);
		}
		return false;
	}

	void Canvas::setRoot(std::shared_ptr<View> root)
	{
		root_ = root;
	}

	void Canvas::measure()
	{
		if (root_ == nullptr)
			return;
		root_->measure();
	}

	void Canvas::layout()
	{
		if (root_ == nullptr)
			return;

		float width = (float)Application::window().width();
		float height = (float)Application::window().height();
		root_->layout(0.0f, width, 0.0f, height);
	}

	void Canvas::paint()
	{
		if (root_ == nullptr)
			return;

		Renderer2D::begin(projection_);
		root_->draw(Vec2::zero);
		Renderer2D::end();
	}
}
