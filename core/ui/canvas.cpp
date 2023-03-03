#include "canvas.h"

#include <SDL.h>

#include "system/application.h"
#include "system/window.h"
#include "poseidon/events.h"
#include "events/key_events.h"
#include "events/mouse_events.h"
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

	bool Canvas::onEvent(const Event& event)
	{
		switch (event.type())
		{
		case Event::Type::WindowResized:
		{
			const auto& e = static_cast<const WindowResizedEvent&>(event);
			projection_ = Mat4::orthoOffCenter(0.0f, (float)e.width(), 0.0f, (float)e.height());
			break;
		}
		case Event::Type::MouseMotion:
		{
			if (root_)
			{
				const auto& e = static_cast<const MouseMotionEvent&>(event);

				auto prevHovered = hovered_.lock();
				auto currHovered = root_->hitTest({ (float)e.x(), (float)e.y() });

				if (prevHovered != currHovered)
				{
					if (prevHovered)
						prevHovered->onMouseExit(e);
					if (currHovered)
					{
						currHovered->onMouseEnter(e);
						currHovered->onMouseMoved(e);
					}
					hovered_ = currHovered;
				}
				else if(prevHovered)
					prevHovered->onMouseMoved(e);
			}
			break;
		}
		case Event::Type::MouseButtonDown:
		{
			auto hovered = hovered_.lock();
			auto focused = focused_.lock();
			if (focused != hovered)
			{
				if (focused)
					focused->onFocusedLost();
				if (hovered)
					hovered->onFocusedGained();
				focused_ = hovered;
			}

			if (auto hovered = hovered_.lock())
			{
				const auto& e = static_cast<const MouseButtonDownEvent&>(event);
				hovered->onMouseButtonDown(e);
			}
			break;
		}
		case Event::Type::MouseButtonUp:
		{
			if (auto hovered = hovered_.lock())
			{
				const auto& e = static_cast<const MouseButtonUpEvent&>(event);
				hovered->onMouseButtonUp(e);
			}
			break;
		}
		case Event::Type::KeyDown:
		{
			if (auto focused = focused_.lock())
			{
				const auto& e = static_cast<const KeyDownEvent&>(event);
				focused->onKeyDown(e);
			}
			break;
		}
		case Event::Type::KeyUp:
		{
			if (auto focused = focused_.lock())
			{
				const auto& e = static_cast<const KeyUpEvent&>(event);
				focused->onKeyUp(e);
			}
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
