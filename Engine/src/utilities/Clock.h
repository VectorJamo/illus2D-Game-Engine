#pragma once

#include "GLFW/glfw3.h"
#include "src/Core.h"

namespace illus2d {
	namespace util {
		class I2D Clock
		{
		private:
			float p_lastTime;
			float p_deltaTime;
			int p_fps;

		public:
			Clock();
			void processInputs();
			inline float getDeltaTime() { return p_deltaTime; };
			inline int getFps() { return p_fps; };
		};
	}
}
