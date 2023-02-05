#pragma once

#include <string>

namespace poseidon
{
	class Texture
	{
	public:
		Texture(const char* filepath);
		Texture(const uint8_t* data, uint32_t width, uint32_t height);
		~Texture();

		void bind() const;
		void unbind() const;

		void slot(uint32_t slot) const;

	private:
		uint32_t id_;
	};
}