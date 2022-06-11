#include "VertexArray.h"

#include <iostream>

namespace illus2d {
	namespace graphics {

		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &p_vao);
		}

		VertexArray::~VertexArray()
		{
			glDeleteVertexArrays(1, &p_vao);
		}
		void VertexArray::Bind() const
		{
			glBindVertexArray(p_vao);
		}

		void VertexArray::Unbind() const
		{
			glBindVertexArray(0);
		}

		// Vertex Buffer Layout Class
		VBlayout::VBlayout(unsigned int dataCount, unsigned int dataType)
			:p_indices(0), p_dataCountPerVertex(0)
		{
			p_indices++;
			p_dataCountPerVertex += dataCount;
			p_dataPerIndex.push_back(dataCount);
		}

		void VBlayout::pushDataLayout(unsigned int dataCount, unsigned int dataType)
		{
			p_indices++;
			p_dataCountPerVertex += dataCount;
			p_dataPerIndex.push_back(dataCount);
		}

		unsigned int VBlayout::getDataOffset(unsigned int index)
		{
			if (index == 0)
				return 0;

			unsigned int offset = 0;
			for (int i = 0; i < index; i++)
			{
				offset += p_dataPerIndex[i];
			}

			return offset;
		}

		void VBlayout::setLayout()
		{
			//std::cout << "Indices:: " << p_indices << std::endl;
			//std::cout << "Data Count Per Vertex:: " << p_dataCountPerVertex << std::endl;

			for (int i = 0; i <= p_indices; i++)
			{
				glEnableVertexAttribArray(i);
				glVertexAttribPointer(i, p_dataPerIndex[i], GL_FLOAT, GL_FALSE, p_dataCountPerVertex * sizeof(float), (const void*)(sizeof(float) * getDataOffset(i)));
			}
		}

		// For single VAO and multiple VBO rendering systems
		void VBlayout::setDataLayoutManually(unsigned int index, unsigned int size, unsigned int dataType)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, size, dataType, GL_FALSE, sizeof(float) * size, 0);
		}
	}
}

