#include "renderer.h"

#include <cstdint>
#include <glad/gl.h>

#include "math/vec4.h"
#include "vertex_array.h"

namespace poseidon
{
	void Renderer::setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	{
		glViewport(x, y, width, height);
	}

	void Renderer::setClearColor(const Vec4& color)
	{
		glClearColor(color.x, color.y, color.z, color.w);
	}

	void Renderer::clear()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void Renderer::drawIndexed(const VertexArray& vertexArray, size_t count)
	{
		vertexArray.bind();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}
}