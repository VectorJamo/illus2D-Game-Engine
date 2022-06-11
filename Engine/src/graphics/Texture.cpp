#include "Texture.h"

#include <iostream>

namespace illus2d {
	namespace graphics {
		Texture::Texture(std::string filePath)
			:p_textureID(0), p_filePath(filePath), p_textureData(nullptr), p_width(0), p_height(0), p_channels(0)
		{
			stbi_set_flip_vertically_on_load(1);

			p_textureData = stbi_load(p_filePath.c_str(), &p_width, &p_height, &p_channels, 4);
		
			if (p_textureData == nullptr)
			{
				std::cout << "Failed to load texture data" << std::endl;
				return;
			}

			glGenTextures(1, &p_textureID);
			glBindTexture(GL_TEXTURE_2D, p_textureID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, p_width, p_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, p_textureData);
			glGenerateMipmap(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, 0);

			stbi_image_free(p_textureData);
		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &p_textureID);
		}

		void Texture::Bind(unsigned int slot) const
		{
			glBindTextureUnit(slot, p_textureID);
		}

		void Texture::Unbind(unsigned int slot) const
		{
			glBindTextureUnit(slot, 0);
		}
	}
}