#pragma once

#include "Clock.h"
#include <iostream>

namespace illus2d {
	namespace util {
		float Clock::p_lastTime;
		float Clock::p_deltaTime;
		int Clock::p_fps;
		int Clock::p_counter;

		void Clock::Init()
		{
			p_lastTime = 0.0f;
			p_deltaTime = 0.0f;
			p_fps = 0.0f;
			p_counter = 0.0f;
		}

		void Clock::ShowFps()
		{
			p_counter++;
			if (p_counter >= 1000)
			{
				std::cout << "|| FPS: || " << p_fps <<  "\n";
				p_counter = 0;
			}
		}
		void Clock::Update()
		{
			// Calculate delta time
			double currentTime = glfwGetTime();
			p_deltaTime = (float)currentTime - p_lastTime;
			p_lastTime = currentTime;

			p_fps = (int)(1 / p_deltaTime);
		}
		
	}
}
