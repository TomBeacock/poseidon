#pragma once

#include <memory>

struct SDL_Window;

namespace poseidon
{
	class Window
	{
	public:
		Window();
		~Window();

		int width() const;
		int height() const;

		void swapBuffers();

	private:
		SDL_Window* window_;
	};
}