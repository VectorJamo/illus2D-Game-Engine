#include "VertexBuffer.h"

namespace illus2d {
	namespace graphics {
		VertexBuffer::VertexBuffer(unsigned int dataSize, void* data)
			:p_vbo(0), p_capacity(0)
		{
			glGenBuffers(1, &p_vbo);
			glBindBuffer(GL_ARRAY_BUFFER, p_vbo);
			glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			p_capacity = dataSize;
		}

		VertexBuffer::~VertexBuffer()
		{
			glDeleteBuffers(1, &p_vbo);
		}

		void VertexBuffer::Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, p_vbo);
		}

		void VertexBuffer::Unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}




