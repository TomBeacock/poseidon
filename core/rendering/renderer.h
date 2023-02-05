#pragma once

namespace poseidon
{
	class Renderer
	{
	public:
		static void init();
		static void setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		static void setClearColor(const struct Vec4& color);
		static void clear();
		static void drawIndexed(const class VertexArray& vertexArray, size_t count);
	};
}