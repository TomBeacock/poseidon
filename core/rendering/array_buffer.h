#pragma once

#include <vector>

namespace poseidon
{
	class DataType
	{
	public:
		enum Type : uint8_t {
			None,
			Int, Int2, Int3, Int4,
			Float, Vec2, Vec3, Vec4, Mat3, Mat4,
			Bool
		};

		DataType(Type type) : type_(type) {}

		uint32_t size() const;
		uint8_t componentCount() const;
		uint32_t toOpenGlType() const;

	private:
		Type type_;
	};

	struct BufferAttribute
	{
		DataType type;
		uint32_t offset;

		BufferAttribute(DataType type, uint32_t offset);
	};

	class BufferLayout
	{
	public:
		BufferLayout(const std::vector<DataType>& types);

		inline const std::vector<BufferAttribute>& attributes() const { return attributes_; };
		inline uint32_t stride() const { return stride_; };

	private:
		std::vector<BufferAttribute> attributes_;
		uint32_t stride_;
	};

	class ArrayBuffer
	{
		friend class VertexArray;

	public:
		ArrayBuffer(const void* data, size_t size, const BufferLayout& layout);
		ArrayBuffer(size_t size, const BufferLayout& layout);
		~ArrayBuffer();

		void bind() const;
		void unbind() const;

		inline const BufferLayout& layout() const { return layout_; };
		void setData(const void* data, size_t size);

	private:
		uint32_t id_;
		BufferLayout layout_;
	};
}