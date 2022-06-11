#pragma once

#include <iostream>
#include <cmath>
#include "src/Core.h"

namespace illus2d {
	namespace maths {
		struct I2D vec3
		{
			float x, y, z;

			vec3();
			vec3(float x, float y, float z);

			float getLength();
			vec3 getNormalVector();
			vec3 normalize();

			// Vector arithmetic 
			vec3 operator+(const vec3& vec);
			vec3 operator-(const vec3& vec);
			vec3 operator*(const vec3& vec);
			vec3 operator*(const float& scalar);
			vec3 operator/(const vec3& vec);
			vec3 operator/(const float& scalar);

			// Advanced vector arithmetic
			float dot(const vec3& vec);
			vec3 cross(const vec3& vec);

			// Vector comparison 
			bool operator==(const vec3& vec);
			bool operator!=(const vec3& vec);

		};

		I2D std::ostream& operator<<(std::ostream& stream, const vec3& vec);

	}

}
