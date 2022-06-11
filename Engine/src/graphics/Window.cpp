#pragma once

#include "Window.h"

#include <iostream>

namespace illus2d {
	namespace graphics {
		Window::Window(unsigned int width, unsigned int height, const char* title)
			:p_window(nullptr), p_width(width), p_height(height), p_title(title)
		{
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "| FATAL ERROR: | Failed to init GLFW" << std::endl;
				return false;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			p_window = glfwCreateWindow(p_width, p_height, p_title, NULL, NULL);
			if (p_window == nullptr)
			{
				std::cout << "| FATAL ERROR: | Failed to init GLFW Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(p_window);
			glfwSetFramebufferSizeCallback(p_window, framebuffer_size_callback);
			
			if (glewInit() != GLEW_OK)
			{
				std::cout << "| FATAL ERROR: | Failed to init GLEW" << std::endl;
				return false;
			}

			return true;
		}

		void Window::bgColor(float r, float g, float b, float a) const
		{
			glClearColor(r, g, b, a);
		}
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::pollEvents()
		{
			glfwPollEvents();

			glfwGetFramebufferSize(p_window, &p_width, &p_height);
			// Keyboard inputs
			if (glfwGetKey(p_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(p_window, true);
			}

			// [ TEMPORARY: ]
			unsigned int error = glGetError();
			if(error != 0)
				std::cout << "| OpenGL ERROR | " << error << std::endl;

		}

		void Window::setVSyncEnabled(bool status) const
		{
			glfwSwapInterval(status);
		}

		bool Window::isClosed() const
		{
			return glfwWindowShouldClose(p_window);
		}

		void Window::swapBuffers() const
		{
			glfwSwapBuffers(p_window);
		}

		int Window::getWidth() const { return p_width; }
		int Window::getHeight() const { return p_height; }

		void framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}

}