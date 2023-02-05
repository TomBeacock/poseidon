#include "texture.h"

#include <SDL_image.h>
#include <glad/gl.h>

namespace poseidon
{
	Texture::Texture(const char* filepath)
	{
		SDL_Surface* surface = IMG_Load(filepath);

		// Flip image vertically
		int pitch = surface->pitch;
		uint8_t* temp = new uint8_t[pitch];
		uint8_t* pixels = (uint8_t*)surface->pixels;

		for (int i = 0; i < surface->h / 2; ++i)
		{
			uint8_t* row1 = pixels + i * pitch;
			uint8_t* row2 = pixels + (surface->h - i - 1) * pitch;
			memcpy(temp, row1, pitch);
			memcpy(row1, row2, pitch);
			memcpy(row2, temp, pitch);
		}
		delete[] temp;

		// Create OpenGL texture
		glCreateTextures(GL_TEXTURE_2D, 1, &id_);
		glBindTexture(GL_TEXTURE_2D, id_);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			surface->w,
			surface->h,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			surface->pixels
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		SDL_FreeSurface(surface);
	}

	Texture::Texture(const uint8_t* data, uint32_t width, uint32_t height)
	{
		// Create OpenGL texture
		glCreateTextures(GL_TEXTURE_2D, 1, &id_);
		glBindTexture(GL_TEXTURE_2D, id_);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			width,
			height,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			data
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &id_);
	}

	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, id_);
	}

	void Texture::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::slot(uint32_t slot) const
	{
		glBindTextureUnit(slot, id_);
	}
}