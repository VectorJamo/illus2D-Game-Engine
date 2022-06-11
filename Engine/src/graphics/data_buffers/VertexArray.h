#pragma once

#include "GL/glew.h"
#include <vector>

#include "src/Core.h"


namespace illus2d {
	namespace graphics {
		class I2D VertexArray
		{
		private:
			unsigned int p_vao;

		public:
			VertexArray();
			~VertexArray();
			void Bind() const;
			void Unbind() const;
		};

		class I2D VBlayout
		{
		private:
			unsigned int p_indices;
			unsigned int p_dataCountPerVertex;
			std::vector<int> p_dataPerIndex;

		public:
			VBlayout(unsigned int dataCount, unsigned int dataType);
			void pushDataLayout(unsigned int dataCount, unsigned int dataType);
			void setLayout();
			unsigned int getDataOffset(unsigned int index);

			static void setDataLayoutManually(unsigned int index, unsigned int size, unsigned int dataType);

		};
	}
}