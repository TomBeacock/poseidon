#pragma once

#include <string>

namespace poseidon
{
	class Texture
	{
	public:
		Texture(const std::string& filepath);
		Texture(const uint8_t* data, uint32_t width, uint32_t height);
		~Texture();

		void bind() const;
		void unbind() const;

		void slot(uint32_t slot) const;

		inline uint32_t width() const { return width_; }
		inline uint32_t height() const { return height_; }

	private:
		uint32_t id_;
		uint32_t width_, height_;
	};
}