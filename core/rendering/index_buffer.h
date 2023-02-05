#pragma once

#include <vector>

namespace poseidon
{
	class IndexBuffer
	{
		friend class VertexArray;

	public:
		IndexBuffer(const uint32_t* indices, size_t count);
		~IndexBuffer();

		void bind() const;
		void unbind() const;

	private:
		uint32_t id_;
	};
}