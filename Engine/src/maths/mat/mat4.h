#pragma once

#include <iostream>
#include <cmath>

#include "src/maths/vec/vec3.h"
#include "src/maths/vec/vec4.h"
#include "src/Core.h"

namespace illus2d {
	namespace maths {
		struct I2D mat4
		{
			float mat4x4[4][4];

			mat4(float diagonal = 1.0f);
			void makeNull();
			void makeIdentity();
			
			float* operator[](int index);

		};
	
		// Transformation matrices
		struct I2D scale : public mat4
		{
			scale(const vec3& sc);

		};
		struct I2D translate : public mat4

		{
			translate(const vec3& tr);
		};
		struct I2D rotate : public mat4
		{
			rotate(float angle, const vec3& rot);
		};

		// Pojection matrices
		struct I2D orthographic :public mat4
		{
			orthographic(float left, float right, float top, float bottom, float znear, float zfar);
		};

		// Matrix - Vector multiplication
		I2D vec4 operator*(const mat4& mat, const vec4& vec);

		// Matrix - Matrix multiplication
		I2D mat4 operator* (const mat4& mat1, const mat4& mat2);

		I2D std::ostream& operator<<(std::ostream& stream, const mat4& mat);

	}
}
