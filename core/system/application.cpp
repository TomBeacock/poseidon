#include "application.h"

#include <SDL.h>

namespace poseidon
{
	void Application::execute()
	{
		SDL_Init(SDL_INIT_VIDEO);

		SDL_Window* window = SDL_CreateWindow("Window Title", 100, 100, 1280, 720, SDL_WINDOW_OPENGL);

		bool running = true;
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					running = false;
			}
		}

		SDL_DestroyWindow(window);

		SDL_Quit();
	}
}
