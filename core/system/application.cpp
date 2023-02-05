#include "application.h"

#include <SDL.h>
#include <glad/gl.h>
#include <array>
#include <numbers>

#include "math/vec3.h"
#include "math/vec4.h"
#include "math/mat4.h"
#include "rendering/renderer.h"
#include "rendering/array_buffer.h"
#include "rendering/index_buffer.h"
#include "rendering/vertex_array.h"
#include "rendering/shader.h"

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
		SDL_GLContext glContext = SDL_GL_CreateContext(window);

		gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

		// Create vertex buffer
		float vertices[3 * 4 * 6] = {
			-0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, -0.5,
			0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5,
			0.5, -0.5, 0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
			-0.5, -0.5, 0.5, -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5,
			-0.5, 0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 0.5, -0.5, 0.5, 0.5,
			0.5, -0.5, 0.5, -0.5, -0.5, 0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5
		};
		ArrayBuffer vertexBuffer(&vertices, sizeof(vertices), BufferLayout({ DataType::Vec3 }));

		// Create index buffer
		std::array<uint32_t, 6 * 6> indices = {
			0, 1, 2, 0, 2, 3,
			4, 5, 6, 4, 6, 7,
			8, 9, 10, 8, 10, 11,
			12, 13, 14, 12, 14, 15,
			16, 17, 18, 16, 18, 19,
			20, 21, 22, 20, 22, 23 };
		IndexBuffer indexBuffer(indices.data(), indices.size());

		// Create vertex array
		VertexArray vertexArray;
		vertexArray.addVertexBuffer(vertexBuffer);
		vertexArray.setIndexBuffer(indexBuffer);

		// Create shader
		const char* vertexShader = R"(#version 330 core
layout(location = 0) in vec3 v_in_pos;

uniform mat4 u_model;
uniform mat4 u_viewProjection;

void main() {
	gl_Position = u_viewProjection * u_model * vec4(v_in_pos, 1.0);
})";

		const char* fragmentShader = R"(#version 330 core
out vec4 f_out_color;

void main() {
	f_out_color = vec4(1.0, 0.0, 0.0, 1.0);
})";

		Shader shader(vertexShader, fragmentShader);
		shader.bind();

		// Set uniforms
		Mat4 model = Mat4::transformation(
			{ 0.0f, 0.0f, 0.0f },
			{ 0.0f, 0.0f, 0.0f },
			{ 1.0f, 1.0f, 1.0f }
		);
		Mat4 view = Mat4::translation(-Vec3(0.0f, 0.0f, -5.0f));
		Mat4 projection = Mat4::perspective(std::numbers::pi / 2.0f, 16.0f / 9.0f, 0.1f, 10.0f);

		shader.setMat4("u_model", model);
		shader.setMat4("u_viewProjection", projection * view);

		Renderer::setClearColor({ 0.0f, 0.0f, 0.0f, 1.0f });

		bool running = true;
		float angle = 0.0f;
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					running = false;
			}

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			Renderer::clear();

			Mat4 model = Mat4::transformation(
				{ 0.0f, 0.0f, 0.0f },
				{ 0.0f, angle, 0.0f },
				{ 1.0f, 1.0f, 1.0f }
			);
			angle += std::numbers::pi / 180.0f;
			shader.setMat4("u_model", model);

			Renderer::drawIndexed(vertexArray, 6 * 6);

			SDL_GL_SwapWindow(window);
		}

		SDL_DestroyWindow(window);

		SDL_Quit();
	}
}
