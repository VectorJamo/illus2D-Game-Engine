#pragma once

#include "Clock.h"
#include <iostream>

namespace illus2d {
	namespace util {

		Clock::Clock()
			: p_lastTime(0.0f), p_deltaTime(0.0f), p_fps(0)
		{			
		}

		void Clock::processInputs()
		{
			double currentTime = glfwGetTime();
			p_deltaTime = (float)currentTime - p_lastTime;
			p_lastTime = currentTime;

			p_fps = (int)(1 / p_deltaTime);
		}
		
	}
}
