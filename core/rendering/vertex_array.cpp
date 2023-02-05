#include "vertex_array.h"

#include <glad/gl.h>

#include "array_buffer.h"
#include "index_buffer.h"

namespace poseidon
{
	VertexArray::VertexArray() : bufferCount_(0)
	{
		glCreateVertexArrays(1, &id_);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &id_);
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(id_);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::addVertexBuffer(const ArrayBuffer& vertexBuffer)
	{
		const BufferLayout& layout = vertexBuffer.layout();

		// Create binding to vertex buffer
		glVertexArrayVertexBuffer(id_, 0, vertexBuffer.id_, bufferCount_, layout.stride());

		for (int i = 0; i < layout.attributes().size(); ++i)
		{
			// Set attribute to use vertex buffer
			glVertexArrayAttribBinding(id_, i, bufferCount_);

			// Set the attribute format
			const auto& attribute = layout.attributes()[i];
			GLenum glType = attribute.type.toOpenGlType();

			if (glType == GL_FLOAT)
			{
				glVertexArrayAttribFormat(
					id_, i, attribute.type.componentCount(), glType, GL_FALSE, attribute.offset);
			}
			else if (glType == GL_INT)
			{
				glVertexArrayAttribIFormat(
					id_, i, attribute.type.componentCount(), glType, attribute.offset);
			}
			// Enable the attribute
			glEnableVertexArrayAttrib(id_, i);
		}
		++bufferCount_;
	}

	void VertexArray::setIndexBuffer(const IndexBuffer& indexBuffer)
	{
		glVertexArrayElementBuffer(id_, indexBuffer.id_);
	}
}