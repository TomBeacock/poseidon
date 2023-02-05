#include "index_buffer.h"

#include <glad/gl.h>

namespace poseidon
{
	IndexBuffer::IndexBuffer(const uint32_t* indices, size_t count)
	{
		glCreateBuffers(1, &id_);
		glNamedBufferData(id_, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &id_);
	}

	void IndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
	}

	void IndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}