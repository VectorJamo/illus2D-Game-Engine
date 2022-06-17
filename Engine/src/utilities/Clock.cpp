#pragma once

#include "Clock.h"
#include <iostream>

namespace illus2d {
	namespace util {
		float Clock::p_lastTime;
		float Clock::p_deltaTime;
		int Clock::p_fps;

		void Clock::Init()
		{
			p_lastTime = 0.0f;
			p_deltaTime = 0.0f;
			p_fps = 0.0f;
		}

		void Clock::Update()
		{
			double currentTime = glfwGetTime();
			p_deltaTime = (float)currentTime - p_lastTime;
			p_lastTime = currentTime;

			p_fps = (int)(1 / p_deltaTime);
		}
		
	}
}
