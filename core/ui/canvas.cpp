#include "canvas.h"

#include <SDL.h>

#include "system/application.h"
#include "system/window.h"
#include "rendering/renderer2d.h"
#include "visual_element.h"

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
		int width = Application::window().width();
		int height = Application::window().height();
		projection_ = Mat4::orthoOffCenter(0.0f, width, 0.0f, height);
	}

	void Canvas::onUpdate(float deltaTime)
	{
		layout();
		paint();
	}

	bool Canvas::onEvent(const SDL_Event& event)
	{
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			uint32_t width = event.window.data1;
			uint32_t height = event.window.data2;
			projection_ = Mat4::orthoOffCenter(0.0f, width, 0.0f, height);
		}
		return false;
	}

	void Canvas::setRoot(std::shared_ptr<VisualElement> root)
	{
		root_ = root;
	}

	void Canvas::layout()
	{
		if (root_ == nullptr)
			return;

		root_->position = Vec2::zero;
		float width = Application::window().width();
		float height = Application::window().height();
		root_->size = { width, height };

		root_->layout();
	}

	void Canvas::paint()
	{
		if (root_ == nullptr)
			return;

		Renderer2D::begin(projection_);
		root_->paint();
		Renderer2D::end();
	}
}
