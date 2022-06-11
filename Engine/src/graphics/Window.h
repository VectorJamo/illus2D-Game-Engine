#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "src/Core.h"

namespace illus2d {
	namespace graphics {
		class I2D Window
		{
		private:
			GLFWwindow* p_window;
			int p_width, p_height;
			const char* p_title;

		public:
			Window(unsigned int width, unsigned int height, const char* title);
			~Window();


			bool init();
			void bgColor(float r, float g, float b, float a) const;
			void clear() const;
			void pollEvents();
			void swapBuffers() const;
			bool isClosed() const;
			void setVSyncEnabled(bool status) const;

			int getWidth() const;
			int getHeight() const;
		};
		I2D void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	}
	
}
