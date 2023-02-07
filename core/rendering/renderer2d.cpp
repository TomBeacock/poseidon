#include "renderer2d.h"

#include <memory>
#include <array>

#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "renderer.h"
#include "array_buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "texture.h"
#include "shader.h"

namespace poseidon
{
	Bounds::Bounds(const Vec2& position, const Vec2& size) :
		left(position.x),
		right(position.x + size.x),
		top(position.y + size.y),
		bottom(position.y)
	{
	}

	Bounds::Bounds(const Vec2& position, const Vec2& size, const Vec2& pivot) :
		left(position.x - size.x * pivot.x),
		right(position.x + size.x * (1.0f - pivot.x)),
		top(position.y + size.y * (1.0f - pivot.y)),
		bottom(position.y - size.y * pivot.y)
	{
	}

	Bounds::Bounds(float left, float right, float top, float bottom) :
		left(left), right(right), top(top), bottom(bottom)
	{
	}

	struct QuadVertex
	{
		Vec2 position;
		Vec2 uv;
		Vec4 color;
		int textureSlot;
	};

	struct Renderer2DData
	{
		std::unique_ptr<Shader> shader;
		std::unique_ptr<Texture> texture;
	};

	static Renderer2DData data;

	void Renderer2D::init()
	{
		data.shader = std::make_unique<Shader>(RES_DIR "shaders/default2d.vert", RES_DIR "shaders/default2d.frag");
		data.shader->bind();

		uint8_t textureData[4] = { 255, 255, 255, 255 };
		data.texture = std::make_unique<Texture>(textureData, 1, 1);

		// Set uniforms
		Mat4 projection = Mat4::ortho(16.0f, 9.0f);

		data.shader->setMat4("u_projection", projection);
		data.shader->setInt("u_texture", 0);
	}

	void Renderer2D::drawRect(const Bounds& bounds, const Vec4& color, const Mat4& transform)
	{
		// Create vertex buffer
		QuadVertex quadVertices[4] = {
			{ { bounds.left, bounds.bottom }, { 0.0f, 0.0f }, color, 0 },
			{ { bounds.right, bounds.bottom }, { 1.0f, 0.0f }, color, 0 },
			{ { bounds.right, bounds.top }, { 1.0f, 1.0f }, color, 0 },
			{ { bounds.left, bounds.top }, { 0.0f, 1.0f }, color, 0 }
		};
		ArrayBuffer quadVbo(
			&quadVertices,
			sizeof(quadVertices),
			BufferLayout({ DataType::Vec2, DataType::Vec2, DataType::Vec4, DataType::Int })
		);

		// Create index buffer
		std::array<uint32_t, 6> quadIndices = { 0, 1, 2, 0, 2, 3 };
		IndexBuffer quadIbo(quadIndices.data(), quadIndices.size());

		// Create vertex array
		VertexArray quadVao;
		quadVao.addVertexBuffer(quadVbo);
		quadVao.setIndexBuffer(quadIbo);

		data.texture->slot(0);
		data.shader->bind();
		data.shader->setMat4("u_model", transform);
		Renderer::drawIndexed(quadVao, 6);
	}

	void Renderer2D::drawRect(const Bounds& bounds, const Bounds& uv, const Texture& texture, const Vec4& tint, const Mat4& transform)
	{
		// Create vertex buffer
		QuadVertex quadVertices[4] = {
			{ { bounds.left, bounds.bottom }, { uv.left, uv.bottom }, tint, 0 },
			{ { bounds.right, bounds.bottom }, { uv.right, uv.bottom }, tint, 0 },
			{ { bounds.right, bounds.top }, { uv.right, uv.top }, tint, 0 },
			{ { bounds.left, bounds.top }, { uv.left, uv.top }, tint, 0 }
		};
		ArrayBuffer quadVbo(
			&quadVertices,
			sizeof(quadVertices),
			BufferLayout({ DataType::Vec2, DataType::Vec2, DataType::Vec4, DataType::Int })
		);

		// Create index buffer
		std::array<uint32_t, 6> quadIndices = { 0, 1, 2, 0, 2, 3 };
		IndexBuffer quadIbo(quadIndices.data(), quadIndices.size());

		// Create vertex array
		VertexArray quadVao;
		quadVao.addVertexBuffer(quadVbo);
		quadVao.setIndexBuffer(quadIbo);

		texture.slot(0);
		data.shader->bind();
		data.shader->setMat4("u_model", transform);
		Renderer::drawIndexed(quadVao, 6);
	}
}