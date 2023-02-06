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
	void Application::execute()
	{
		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_PNG);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		SDL_Window* window = SDL_CreateWindow("Window Title", 100, 100, 1280, 720, SDL_WINDOW_OPENGL);
		SDL_GLContext glContext = SDL_GL_CreateContext(window);

		gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

		Renderer::init();

		// Cube example
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
		Mat4 projection = Mat4::persp(std::numbers::pi / 2.0f, 16.0f / 9.0f, 0.1f, 10.0f);

		shader.setMat4("u_model", model);
		shader.setMat4("u_viewProjection", projection * view);

		// Example textured quad
		// Create vertex buffer
		float quadVertices[4 * 5] = {
			-0.5, -0.5, -0.0, 0.0f, 0.0f,
			0.5, -0.5, -0.0, 1.0f, 0.0f,
			0.5, 0.5, -0.0, 1.0f, 1.0f,
			-0.5, 0.5, -0.0, 0.0f, 1.0f
		};
		ArrayBuffer quadVbo(
			&quadVertices,
			sizeof(quadVertices),
			BufferLayout({ DataType::Vec3, DataType::Vec2 })
		);

		// Create index buffer
		std::array<uint32_t, 6> quadIndices = { 0, 1, 2, 0, 2, 3 };
		IndexBuffer quadIbo(quadIndices.data(), quadIndices.size());

		// Create vertex array
		VertexArray quadVao;
		quadVao.addVertexBuffer(quadVbo);
		quadVao.setIndexBuffer(quadIbo);

		// Create shader
		const char* quadVertexShader = R"(#version 330 core
layout(location = 0) in vec3 v_in_pos;
layout(location = 1) in vec2 v_in_uv;

out vec2 v_out_uv;

uniform mat4 u_model;
uniform mat4 u_viewProjection;

void main() {
	v_out_uv = v_in_uv;
	gl_Position = u_viewProjection * u_model * vec4(v_in_pos, 1.0);
})";

		const char* quadFragmentShader = R"(#version 330 core
in vec2 v_out_uv;

out vec4 f_out_color;

uniform sampler2D u_texture;

void main() {
	f_out_color = texture(u_texture, v_out_uv);
})";

		Shader quadShader(quadVertexShader, quadFragmentShader);
		quadShader.bind();

		// Load texture
		Texture texture(RES("trident.png"));
		texture.slot(0);

		// Set uniforms
		Mat4 quadModel = Mat4::transformation(
			{ 0.0f, 0.0f, 0.0f },
			{ 0.0f, 0.0f, 0.0f },
			{ 1.0f, 1.0f, 1.0f }
		);
		Mat4 quadView = Mat4::translation(-Vec3(0.0f, 0.0f, -5.0f));
		Mat4 quadProjection = Mat4::ortho(16.0f, 9.0f, 0.1f, 10.0f);

		quadShader.setMat4("u_model", quadModel);
		quadShader.setMat4("u_viewProjection", quadProjection* quadView);
		quadShader.setInt("u_texture", 0);

		Renderer::setClearColor({ 0.0f, 0.0f, 0.0f, 1.0f });

		bool running = true;
		float angle = 0.0f;
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

			layerStack_.onUpdate();

			Renderer::clear();

			// Rotate and render cube
			Mat4 model = Mat4::transformation(
				{ 0.0f, 0.0f, 0.0f },
				{ 0.0f, angle, 0.0f },
				{ 1.0f, 1.0f, 1.0f }
			);
			angle += std::numbers::pi / 180.0f;
			shader.bind();
			shader.setMat4("u_model", model);

			Renderer::drawIndexed(vertexArray, 6 * 6);

			// Render textured quad
			quadShader.bind();
			Renderer::drawIndexed(quadVao, 6);

			SDL_GL_SwapWindow(window);
		}

		SDL_DestroyWindow(window);

		SDL_Quit();
	}
}
