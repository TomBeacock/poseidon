#include "application.h"

#include <SDL.h>
#include <glad/gl.h>

namespace poseidon
{
	void Application::execute()
	{
		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		SDL_Window* window = SDL_CreateWindow("Window Title", 100, 100, 1280, 720, SDL_WINDOW_OPENGL);
		SDL_GLContext gl_context = SDL_GL_CreateContext(window);

		gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
		bool running = true;
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					running = false;
			}

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

			SDL_GL_SwapWindow(window);
		}

		SDL_DestroyWindow(window);

		SDL_Quit();
	}
}
