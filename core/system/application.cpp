#include "application.h"

#include <SDL.h>
#include <SDL_image.h>
#include <glad/gl.h>
#include <array>
#include <numbers>

#include "layer.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/mat4.h"
#include "rendering/renderer.h"
#include "rendering/array_buffer.h"
#include "rendering/index_buffer.h"
#include "rendering/vertex_array.h"
#include "rendering/shader.h"
#include "rendering/texture.h"

#define RES(file) RES_DIR file

namespace poseidon
{
	Application::Application() : window_(nullptr)
	{
		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_PNG);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		window_ = SDL_CreateWindow("Window Title", 100, 100, 1280, 720, SDL_WINDOW_OPENGL);
		SDL_GLContext glContext = SDL_GL_CreateContext(window_);

		gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

		Renderer::init();
	}

	Application::~Application()
	{
		SDL_DestroyWindow(window_);
		SDL_Quit();
	}

	void Application::execute()
	{
		bool running = true;
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				// Send event to layers
				if (layerStack_.onEvent(event))
					continue;

				// Default handling
				if (event.type == SDL_QUIT)
					running = false;
			}

			Renderer::clear();

			layerStack_.onUpdate();

			SDL_GL_SwapWindow(window_);
		}
	}
}
