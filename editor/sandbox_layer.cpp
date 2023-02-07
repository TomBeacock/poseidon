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

		// Load texture
		quadTexture_ = std::make_unique<Texture>(RES_DIR "trident.png");

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

		Mat4 rectModel = Mat4::rotation(0.0f, 0.0f, angle_);

		// Render textured quad
		Renderer2D::drawRect(Bounds(Vec2::zero, { 2.0f, 10.0f }), { 0.5f, 0.5f, 0.0f, 1.0f }, rectModel);
		Renderer2D::drawRect(Bounds(Vec2::zero, { 5.0f, 5.0f }, { 0.5f, 0.5f }), Bounds(Vec2::zero, Vec2::one), *quadTexture_, Vec4::one);
	}

	bool SandboxLayer::onEvent(const SDL_Event& event)
	{
		return false;
	}
}