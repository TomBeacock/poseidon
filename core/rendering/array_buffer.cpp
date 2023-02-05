#include "array_buffer.h"

#include <glad/gl.h>

namespace poseidon
{
    uint32_t DataType::size() const
    {
        switch (type_)
        {
        case DataType::None:    return 0;
        case DataType::Int:     return 4;
        case DataType::Int2:    return 4 * 2;
        case DataType::Int3:    return 4 * 3;
        case DataType::Int4:    return 4 * 4;
        case DataType::Float:   return 4;
        case DataType::Vec2:    return 4 * 2;
        case DataType::Vec3:    return 4 * 3;
        case DataType::Vec4:    return 4 * 4;
        case DataType::Mat3:    return 4 * 3 * 3;
        case DataType::Mat4:    return 4 * 4 * 4;
        case DataType::Bool:    return 1;
        }
        return 0;
    }

    uint8_t DataType::componentCount() const
    {
        switch (type_)
        {
        case DataType::None:    return 0;
        case DataType::Int:     return 1;
        case DataType::Int2:    return 2;
        case DataType::Int3:    return 3;
        case DataType::Int4:    return 4;
        case DataType::Float:   return 1;
        case DataType::Vec2:    return 2;
        case DataType::Vec3:    return 3;
        case DataType::Vec4:    return 4;
        case DataType::Mat3:    return 3 * 3;
        case DataType::Mat4:    return 4 * 4;
        case DataType::Bool:    return 1;
        }
        return 0;
    }

    GLenum DataType::toOpenGlType() const
    {
        switch (type_)
        {
        case DataType::None:    return GL_NONE;
        case DataType::Int:
        case DataType::Int2:
        case DataType::Int3:
        case DataType::Int4:    return GL_INT;
        case DataType::Float:
        case DataType::Vec2:
        case DataType::Vec3:
        case DataType::Vec4:
        case DataType::Mat3:
        case DataType::Mat4:    return GL_FLOAT;
        case DataType::Bool:    return GL_BOOL;
        }
        return 0;
    }

    BufferAttribute::BufferAttribute(DataType type, uint32_t offset) :
        type(type), offset(offset) {}

    BufferLayout::BufferLayout(const std::vector<DataType>& types) :
        attributes_(types.size(), { DataType::None, 0 }), stride_(0)
    {
        uint32_t currOffset = 0;
        for (int i = 0; i < types.size(); ++i)
        {
            attributes_[i] = { types[i], currOffset };
            currOffset += types[i].size();
        }
        stride_ = currOffset;
    }

    ArrayBuffer::ArrayBuffer(const void* data, size_t size, const BufferLayout& layout) :
        id_(0), layout_(layout)
    {
        glCreateBuffers(1, &id_);
        glNamedBufferData(id_, size, data, GL_STATIC_DRAW);
    }

    ArrayBuffer::ArrayBuffer(size_t size, const BufferLayout& layout) :
        id_(0), layout_(layout)
    {
        glCreateBuffers(1, &id_);
        glNamedBufferData(id_, size, nullptr, GL_DYNAMIC_DRAW);
    }

    ArrayBuffer::~ArrayBuffer()
    {
        glDeleteBuffers(1, &id_);
    }

    void ArrayBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, id_);
    }

    void ArrayBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void ArrayBuffer::setData(const void* data, size_t size)
    {
        glNamedBufferSubData(id_, 0, size, data);
    }
}