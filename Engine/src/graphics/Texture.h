#pragma once
#include <string>
#include "externals/stb_image/stb_image.h"
#include <GL/glew.h>
#include "src/Core.h"

namespace illus2d {
	namespace graphics {
		class I2D Texture
		{
		private:
			unsigned int p_textureID;
			std::string p_filePath;
			unsigned char* p_textureData;
			int p_width, p_height, p_channels;

		public:
			Texture(std::string filePath);
			~Texture();

			void Bind(unsigned int slot) const;
			void Unbind(unsigned int slot) const;
		};
	}
}

