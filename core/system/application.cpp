#include "application.h"

#include <SDL.h>

namespace poseidon
{
	void Application::execute()
	{
		SDL_Init(SDL_INIT_VIDEO);

		SDL_Window* window = SDL_CreateWindow("Window Title", 100, 100, 1280, 720, SDL_WINDOW_OPENGL);

		SDL_Delay(3000);

		SDL_DestroyWindow(window);

		SDL_Quit();
	}
}
