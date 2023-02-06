#include "sandbox_layer.h"

#include <poseidon/math.h>
#include <poseidon/rendering.h>
#include <array>
#include <numbers>

using namespace poseidon;

namespace editor
{
	SandboxLayer::SandboxLayer() : angle_(0.0f)
	{

	}

	SandboxLayer::~SandboxLayer()
	{

	}

	void SandboxLayer::onStart()
	{
		// Cube example
		// Create vertex buffer
		float cubeVertices[3 * 4 * 6] = {
			-0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, -0.5,
			0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5,
			0.5, -0.5, 0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
			-0.5, -0.5, 0.5, -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5,
			-0.5, 0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 0.5, -0.5, 0.5, 0.5,
			0.5, -0.5, 0.5, -0.5, -0.5, 0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5
		};
		cubeVbo_ = std::make_unique<ArrayBuffer>(&cubeVertices, sizeof(cubeVertices), BufferLayout({ DataType::Vec3 }));

		// Create index buffer
		std::array<uint32_t, 6 * 6> indices = {
			0, 1, 2, 0, 2, 3,
			4, 5, 6, 4, 6, 7,
			8, 9, 10, 8, 10, 11,
			12, 13, 14, 12, 14, 15,
			16, 17, 18, 16, 18, 19,
			20, 21, 22, 20, 22, 23 };
		cubeIbo_ = std::make_unique<IndexBuffer>(indices.data(), indices.size());

		// Create vertex array
		cubeVao_ = std::make_unique<VertexArray>();
		cubeVao_->addVertexBuffer(*cubeVbo_);
		cubeVao_->setIndexBuffer(*cubeIbo_);

		// Create shader
		const char* cubeVertexShader = R"(#version 330 core
layout(location = 0) in vec3 v_in_pos;

uniform mat4 u_model;
uniform mat4 u_viewProjection;

void main() {
	gl_Position = u_viewProjection * u_model * vec4(v_in_pos, 1.0);
})";

		const char* cubeFragmentShader = R"(#version 330 core
out vec4 f_out_color;

void main() {
	f_out_color = vec4(1.0, 0.0, 0.0, 1.0);
})";

		cubeShader_ = std::make_unique<Shader>(cubeVertexShader, cubeFragmentShader);
		cubeShader_->bind();

		// Set uniforms
		Mat4 model = Mat4::transformation(
			{ 0.0f, 0.0f, 0.0f },
			{ 0.0f, 0.0f, 0.0f },
			{ 1.0f, 1.0f, 1.0f }
		);
		Mat4 view = Mat4::translation(-Vec3(0.0f, 0.0f, -5.0f));
		Mat4 projection = Mat4::persp(std::numbers::pi / 2.0f, 16.0f / 9.0f, 0.1f, 10.0f);

		cubeShader_->setMat4("u_model", model);
		cubeShader_->setMat4("u_viewProjection", projection * view);

		// Example textured quad
		// Create vertex buffer
		float quadVertices[4 * 5] = {
			-0.5, -0.5, -0.0, 0.0f, 0.0f,
			0.5, -0.5, -0.0, 1.0f, 0.0f,
			0.5, 0.5, -0.0, 1.0f, 1.0f,
			-0.5, 0.5, -0.0, 0.0f, 1.0f
		};
		quadVbo_ = std::make_unique<ArrayBuffer>(
			&quadVertices,
			sizeof(quadVertices),
			BufferLayout({ DataType::Vec3, DataType::Vec2 })
		);

		// Create index buffer
		std::array<uint32_t, 6> quadIndices = { 0, 1, 2, 0, 2, 3 };
		quadIbo_ = std::make_unique<IndexBuffer>(quadIndices.data(), quadIndices.size());

		// Create vertex array
		quadVao_ = std::make_unique<VertexArray>();
		quadVao_->addVertexBuffer(*quadVbo_);
		quadVao_->setIndexBuffer(*quadIbo_);

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

		quadShader_ = std::make_unique<Shader>(quadVertexShader, quadFragmentShader);
		quadShader_->bind();

		// Load texture
		quadTexture_ = std::make_unique<Texture>(RES_DIR "trident.png");
		quadTexture_->slot(0);

		// Set uniforms
		Mat4 quadModel = Mat4::transformation(
			{ 0.0f, 0.0f, 0.0f },
			{ 0.0f, 0.0f, 0.0f },
			{ 1.0f, 1.0f, 1.0f }
		);
		Mat4 quadView = Mat4::translation(-Vec3(0.0f, 0.0f, -5.0f));
		Mat4 quadProjection = Mat4::ortho(16.0f, 9.0f, 0.1f, 10.0f);

		quadShader_->setMat4("u_model", quadModel);
		quadShader_->setMat4("u_viewProjection", quadProjection * quadView);
		quadShader_->setInt("u_texture", 0);

		Renderer::setClearColor({ 0.0f, 0.0f, 0.0f, 1.0f });
	}

	void SandboxLayer::onUpdate()
	{
		// Rotate and render cube
		Mat4 model = Mat4::transformation(
			{ 0.0f, 0.0f, 0.0f },
			{ 0.0f, angle_, 0.0f },
			{ 1.0f, 1.0f, 1.0f }
		);
		angle_ += std::numbers::pi / 180.0f;
		cubeShader_->bind();
		cubeShader_->setMat4("u_model", model);
		Renderer::drawIndexed(*cubeVao_, 6 * 6);

		// Render textured quad
		quadShader_->bind();
		Renderer::drawIndexed(*quadVao_, 6);
	}

	bool SandboxLayer::onEvent(const SDL_Event& event)
	{
		return false;
	}
}