#pragma once
#include "KeyCodes.h"
#include "src/Core.h"
#include "src/graphics/Window.h"
#include "src/maths/vec/vec2.h"

#include <iostream>

#define NUM_KEYS 350
#define NUM_MOUSE_BUTTONS 9

namespace illus2d {
	namespace util {
		class I2D Input
		{
		private:
			static graphics::Window* p_window;
			static bool p_keys[NUM_KEYS];
			static bool p_mouseButtons[NUM_MOUSE_BUTTONS];
			static bool p_scrollUp;
			static bool p_scrollDown;
			static maths::vec2 p_mousePos;
			static maths::vec2 p_mouseDeltaPos;

		public:
			static void Init(graphics::Window* window);
			static bool IsKeyPressed(int keyCode);
			static bool IsKeyHold(int keyCode);

			static bool IsMouseButtonPressed(int buttonCode);
			static bool IsMouseButtonHold(int buttonCode);

			static bool IsMouseScrollUp();
			static bool IsMouseScrollDown();

			static void Update();

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

			static inline maths::vec2 GetMousePos() { return p_mousePos; }
			static inline maths::vec2 GetMouseDeltaPos() { return p_mouseDeltaPos; }
		};
	}
}


