#include "Input.h"

namespace illus2d {
	namespace util {
		graphics::Window* Input::p_window;
		bool Input::p_keys[NUM_KEYS];
		bool Input::p_mouseButtons[NUM_MOUSE_BUTTONS];
		bool Input::p_scrollUp;
		bool Input::p_scrollDown;
		maths::vec2 Input::p_mousePos;
		maths::vec2 Input::p_mouseDeltaPos;

		void Input::Init(graphics::Window* window)
		{
			p_window = window;
			memset(p_keys, 0, sizeof(bool) * NUM_KEYS);
			glfwSetKeyCallback(p_window->getWindowObject(), key_callback);

			glfwSetMouseButtonCallback(p_window->getWindowObject(), mouse_button_callback);
			glfwSetScrollCallback(p_window->getWindowObject(), scroll_callback);
		}

		bool Input::IsKeyPressed(int keyCode)
		{
			if (p_keys[keyCode])
			{
				p_keys[keyCode] = false;
				return true;
			}
			return false;
		}
		bool Input::IsKeyHold(int keyCode)
		{
			return p_keys[keyCode];
		}

		bool Input::IsMouseButtonPressed(int buttonCode)
		{
			if (p_mouseButtons[buttonCode])
			{
				p_mouseButtons[buttonCode] = false;
				return true;
			}
			return false;
		}

		bool Input::IsMouseButtonHold(int buttonCode)
		{
			return p_mouseButtons[buttonCode];
		}

		bool Input::IsMouseScrollUp()
		{
			if (p_scrollUp)
			{
				p_scrollUp = false;
				return true;
			}
			return false;
		}

		bool Input::IsMouseScrollDown()
		{
			if (p_scrollDown)
			{
				p_scrollDown = false;
				return true;
			}
			return false;
		}

		void Input::Update()
		{
			// Calculate delta mouse posisiton
			double mouseX, mouseY;
			glfwGetCursorPos(p_window->getWindowObject(), &mouseX, &mouseY);
			p_mouseDeltaPos.x = (float)mouseX - p_mousePos.x;
			p_mouseDeltaPos.y = (float)mouseY - p_mousePos.y;

			p_mousePos.x = (float)mouseX;
			p_mousePos.y = (float)mouseY;
		}

		void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if(action == GLFW_PRESS)
				p_keys[key] = true;
			if (action == GLFW_RELEASE)
				p_keys[key] = false;
		}
		void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			if (action == GLFW_PRESS)
				p_mouseButtons[button] = true;
			if (action == GLFW_RELEASE)
				p_mouseButtons[button] = false;
		}

		void Input::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{
			if (yoffset == 1)
			{
				p_scrollUp = true;
				p_scrollDown = false;
			}
			if (yoffset == -1)
			{
				p_scrollDown = true;
				p_scrollUp = false;
			}

		}
	}
}