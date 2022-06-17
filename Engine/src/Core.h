#pragma once

#ifdef BUILD_DLL
	#define I2D __declspec(dllexport)
#elif defined BUILD_EXE
	#define I2D __declspec(dllimport)
#elif defined BUILD_STATIC
	#define I2D 
#endif
