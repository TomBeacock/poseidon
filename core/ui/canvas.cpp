#include "canvas.h"

#include <SDL.h>

#include "system/application.h"
#include "system/window.h"
#include "rendering/renderer2d.h"
#include "widget.h"

namespace poseidon
{
	Canvas::Canvas() :
		root_(nullptr),
		hovered_(),
		projection_(Mat4::identity) {}

	Canvas::~Canvas() = default;

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
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
		{
			if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				float width = (float)event.window.data1;
				float height = (float)event.window.data2;
				projection_ = Mat4::orthoOffCenter(0.0f, width, 0.0f, height);
			}
			break;
		}
		case SDL_MOUSEMOTION:
		{
			if (root_)
			{
				auto prevHovered = hovered_.lock();
				auto currHovered = root_->hitTest({ (float)event.motion.x, (float)event.motion.y });

				if (prevHovered != currHovered)
				{
					if (prevHovered)
						prevHovered->onMouseExit();
					if (currHovered)
					{
						currHovered->onMouseEnter();
						currHovered->onMouseMoved();
					}
					hovered_ = currHovered;
				}
				else if(prevHovered)
					prevHovered->onMouseMoved();
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			if (auto hovered = hovered_.lock())
				hovered->onMouseButtonDown();
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			if (auto hovered = hovered_.lock())
				hovered->onMouseButtonDown();
			break;
		}
		}

		return false;
	}

	void Canvas::setRoot(std::shared_ptr<Widget> root)
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
		root_->layout({ 0.0f, 0.0f }, { width, height });
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
