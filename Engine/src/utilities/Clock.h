#pragma once

#include "GLFW/glfw3.h"
#include "src/Core.h"

namespace illus2d {
	namespace util {
		class I2D Clock
		{
		private:
			static float p_lastTime;
			static float p_deltaTime;
			static int p_fps;

		public:
			static void Init();
			static void Update();
			static inline float GetDeltaTime() { return p_deltaTime; };
			static inline int GetFps() { return p_fps; };
		};
	}
}
