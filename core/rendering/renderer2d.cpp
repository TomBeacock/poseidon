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
		Vec3 position;
		Vec2 uv;
		Vec4 color;
		uint32_t textureSlot;
	};

	class QuadBatch
	{
	public:
		QuadBatch();

		void addQuad(QuadVertex bottomLeft, QuadVertex bottomRight, QuadVertex topRight, QuadVertex topLeft);
		uint32_t addTexture(const std::shared_ptr<Texture>& texture);
		void draw();
		void reset();

	private:
		static const uint32_t maxQuads_ = 1000;
		static const uint32_t maxTextures_ = 32;

		std::unique_ptr<VertexArray> vao_;
		std::unique_ptr<ArrayBuffer> vbo_;
		std::unique_ptr<IndexBuffer> ibo_;
		std::unique_ptr<QuadVertex[]> vertices_;
		std::array<std::shared_ptr<Texture>, maxTextures_> textures_;
		uint32_t currentQuads_;
		uint32_t currentTextures_;
	};

	QuadBatch::QuadBatch() :
		vertices_(new QuadVertex[maxQuads_ * 4]),
		currentQuads_(0),
		currentTextures_(1)
	{
		vbo_ = std::make_unique<ArrayBuffer>(
			maxQuads_ * 4,
			BufferLayout({ DataType::Vec3, DataType::Vec2, DataType::Vec4, DataType::Int })
		);

		uint32_t* indices = new uint32_t[maxQuads_ * 6];
		for (int q = 0, i = 0, v = 0; q < maxQuads_; ++q, i += 6, v += 4) {
			indices[i + 0] = v + 0;
			indices[i + 1] = v + 1;
			indices[i + 2] = v + 2;
			indices[i + 3] = v + 0;
			indices[i + 4] = v + 2;
			indices[i + 5] = v + 3;
		}
		ibo_ = std::make_unique<IndexBuffer>(indices, maxQuads_ * 6);
		delete[] indices;

		vao_ = std::make_unique<VertexArray>();
		vao_->addVertexBuffer(*vbo_);
		vao_->setIndexBuffer(*ibo_);
	}

	void QuadBatch::addQuad(QuadVertex bottomLeft, QuadVertex bottomRight, QuadVertex topRight, QuadVertex topLeft)
	{
		size_t index = currentQuads_ * 4;
		vertices_[index + 0] = bottomLeft;
		vertices_[index + 1] = bottomRight;
		vertices_[index + 2] = topRight;
		vertices_[index + 3] = topLeft;
		++currentQuads_;
	}

	uint32_t QuadBatch::addTexture(const std::shared_ptr<Texture>& texture)
	{
		auto it = std::find(textures_.begin(), textures_.end(), texture);
		if (it != textures_.end())
			return it - textures_.begin();
		texture->slot(currentTextures_);
		++currentTextures_;
		return currentTextures_ - 1;
	}

	void QuadBatch::draw()
	{
		vbo_->setData(vertices_.get(), currentQuads_ * sizeof(QuadVertex) * 4);
		Renderer::drawIndexed(*vao_, currentQuads_ * 6);
	}

	void QuadBatch::reset()
	{
		currentQuads_ = 0;
		currentTextures_ = 1;
	}

	struct Renderer2DData
	{
		std::unique_ptr<QuadBatch> quadBatch;
		std::unique_ptr<Shader> shader;
		std::unique_ptr<Texture> defaultTexture;
	};

	static Renderer2DData data;

	void Renderer2D::init()
	{
		data.quadBatch = std::make_unique<QuadBatch>();

		data.shader = std::make_unique<Shader>(RES_DIR "shaders/default2d.vert", RES_DIR "shaders/default2d.frag");
		data.shader->bind();
		uint32_t textures[32] = { 0 };
		for (uint32_t i = 0; i < 32; ++i)
			textures[i] = i;
		data.shader->setIntArray("u_textures", (int*)textures, 32);

		uint8_t textureData[4] = { 255, 255, 255, 255 };
		data.defaultTexture = std::make_unique<Texture>(textureData, 1, 1);
	}

	void Renderer2D::begin(const Mat4& viewProjection)
	{
		data.shader->bind();
		data.shader->setMat4("u_viewProjection", viewProjection);
		data.defaultTexture->slot(0);
		data.quadBatch->reset();
	}

	void Renderer2D::end()
	{
		data.quadBatch->draw();
	}

	void Renderer2D::drawRect(const Bounds& bounds, const Vec4& color, const Mat4& transform)
	{
		data.quadBatch->addQuad(
			{ { bounds.left, bounds.bottom, 0.0f }, { 0.0f, 0.0f }, color, 0 },
			{ { bounds.right, bounds.bottom, 0.0f }, { 1.0f, 0.0f }, color, 0 },
			{ { bounds.right, bounds.top, 0.0f }, { 1.0f, 1.0f }, color, 0 },
			{ { bounds.left, bounds.top, 0.0f }, { 0.0f, 1.0f }, color, 0 }
		);
	}

	void Renderer2D::drawRect(const Bounds& bounds, const Bounds& uv, const std::shared_ptr<Texture>& texture, const Vec4& tint, const Mat4& transform)
	{
		uint32_t slot = data.quadBatch->addTexture(texture);
		data.quadBatch->addQuad(
			{ { bounds.left, bounds.bottom, 0.0f }, { uv.left, uv.bottom }, tint, slot },
			{ { bounds.right, bounds.bottom, 0.0f }, { uv.right, uv.bottom }, tint, slot },
			{ { bounds.right, bounds.top, 0.0f }, { uv.right, uv.top }, tint, slot },
			{ { bounds.left, bounds.top, 0.0f }, { uv.left, uv.top }, tint, slot }
		);
	}
}