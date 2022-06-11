#include "IndexBuffer.h"

namespace illus2d {
	namespace graphics {
		IndexBuffer::IndexBuffer(unsigned int dataSize, void* indices)
			:p_ibo(0), p_capacity(0)
		{
			glGenBuffers(1, &p_ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, indices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			p_capacity = dataSize;
		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &p_ibo);
		}
		void IndexBuffer::Bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_ibo);
		}

		void IndexBuffer::Unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}



