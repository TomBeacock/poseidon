#include "window.h"

#include <SDL.h>

namespace poseidon
{
	Window::Window() :
		window_(SDL_CreateWindow("Window Title", 100, 100, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE))
	{
		SDL_GL_CreateContext(window_);
	}

	Window::~Window()
	{
		SDL_DestroyWindow(window_);
	}

	int Window::width() const
	{
		int w;
		SDL_GetWindowSize(window_, &w, nullptr);
		return w;
	}

	int Window::height() const
	{
		int h;
		SDL_GetWindowSize(window_, nullptr, &h);
		return h;
	}

	void Window::swapBuffers()
	{
		SDL_GL_SwapWindow(window_);
	}
}