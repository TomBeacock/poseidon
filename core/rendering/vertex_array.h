#pragma once

namespace poseidon
{
	class ArrayBuffer;
	class IndexBuffer;

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void bind() const;
		void unbind() const;

		void addVertexBuffer(const ArrayBuffer& vertexBuffer);
		void setIndexBuffer(const IndexBuffer& indexBuffer);

	private:
		unsigned int id_;
		unsigned int bufferCount_;
	};
}