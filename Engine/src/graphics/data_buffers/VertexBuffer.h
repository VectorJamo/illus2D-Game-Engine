#pragma once

#include "GL/glew.h"
#include "src/Core.h"

namespace illus2d {
	namespace graphics {
		class I2D VertexBuffer
		{
		private:
			unsigned int p_vbo;
			unsigned int p_capacity;

		public:
			VertexBuffer(unsigned int dataSize, void* data);
			~VertexBuffer();
			void Bind() const;
			void Unbind() const;
		};
	}
}

