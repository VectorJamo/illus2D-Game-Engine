#pragma once

#include "GL/glew.h"

#include "src/Core.h"

namespace illus2d {
	namespace graphics {
		class I2D IndexBuffer
		{
		private:
			unsigned int p_ibo;
			unsigned int p_capacity;

		public:
			IndexBuffer(unsigned int dataSize, void* indices);
			~IndexBuffer();
			void Bind() const;
			void Unbind() const;

		};
	}
}
