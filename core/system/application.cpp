#include "application.h"

#include <SDL.h>
#include <SDL_image.h>
#include <glad/gl.h>
#include <array>
#include <numbers>
#include <iostream>

#include "window.h"
#include "layer.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/mat4.h"
#include "poseidon/events.h"
#include "rendering/renderer.h"
#include "rendering/renderer2d.h"

#define RES(file) RES_DIR file

namespace poseidon
{
	const Window& Application::window()
	{
		return *instance_->window_;
	}

	Application* Application::instance_ = nullptr;

	Application::Application() : window_(nullptr), lastFrameTime_(0)
	{
		if (instance_ == nullptr)
			instance_ = this;

		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_PNG);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		window_ = new Window();

		gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

		Renderer::init();
		Renderer2D::init();
	}

	Application::~Application()
	{
		delete window_;
		SDL_Quit();
	}

	void Application::execute()
	{
		bool running = true;
		while (running)
		{
			uint64_t currentTime = SDL_GetTicks64();
			float deltaTime = (currentTime - lastFrameTime_) / 1000.0f;
			lastFrameTime_ = currentTime;

			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				// Required handling
				if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					uint32_t width = event.window.data1;
					uint32_t height = event.window.data2;
					Renderer::setViewport(0, 0, width, height);
				}

				// Dispatch event to layers
				if (dispatchEvent(event))
					continue;

				// Default event handling
				if (event.type == SDL_QUIT)
					running = false;
			}

			Renderer::clear();

			layerStack_.onUpdate(deltaTime);

			window_->swapBuffers();
		}
	}

	bool Application::dispatchEvent(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
		{
			KeyDownEvent e(
				static_cast<KeyCode>(event.key.keysym.sym),
				static_cast<ScanCode>(event.key.keysym.scancode),
				static_cast<KeyModifiers>(event.key.keysym.mod),
				event.key.repeat);

			return layerStack_.onEvent(e);
		}
		case SDL_KEYUP:
		{
			KeyUpEvent e(
				static_cast<KeyCode>(event.key.keysym.sym),
				static_cast<ScanCode>(event.key.keysym.scancode),
				static_cast<KeyModifiers>(event.key.keysym.mod));

			return layerStack_.onEvent(e);
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			MouseButtonDownEvent e(
				static_cast<ButtonCode>(event.button.button),
				event.button.x,
				event.button.y);

			return layerStack_.onEvent(e);
		}
		case SDL_MOUSEBUTTONUP:
		{
			MouseButtonUpEvent e(
				static_cast<ButtonCode>(event.button.button),
				event.button.x,
				event.button.y);

			return layerStack_.onEvent(e);
		}
		case SDL_MOUSEMOTION:
		{
			MouseMotionEvent e(
				event.motion.x,
				event.motion.y,
				event.motion.xrel,
				event.motion.yrel);
			return layerStack_.onEvent(e);
		}
		case SDL_WINDOWEVENT:
		{
			switch (event.window.type)
			{
			case SDL_WINDOWEVENT_MOVED:
			{
				WindowMovedEvent e(
					event.window.data1,
					event.window.data2);
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_RESIZED:
			{
				WindowMovedEvent e(
					event.window.data1,
					event.window.data2);
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			{
				WindowSizeChangedEvent e(
					event.window.data1,
					event.window.data2);
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_MINIMIZED:
			{
				WindowMinimizedEvent e;
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_MAXIMIZED:
			{
				WindowMaximizedEvent e;
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_RESTORED:
			{
				WindowRestoredEvent e;
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			{
				WindowFocusGainedEvent e;
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_FOCUS_LOST:
			{
				WindowFocusLostEvent e;
				return layerStack_.onEvent(e);
			}
			case SDL_WINDOWEVENT_CLOSE:
			{
				WindowCloseEvent e;
				return layerStack_.onEvent(e);
			}
			}
		}
		}
		return false;
	}
}
