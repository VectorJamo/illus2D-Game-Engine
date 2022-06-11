#pragma once

#include <iostream>
#include <cmath>
#include "src/Core.h"

namespace illus2d {
	namespace maths {
		struct I2D vec4
		{
			float x, y, z, w;

			vec4();
			vec4(float x, float y, float z);

			float getLength();
			vec4 getNormalVector();
			vec4 normalize();

			// Vector arithmetic 
			vec4 operator+(const vec4& vec);
			vec4 operator-(const vec4& vec);
			vec4 operator*(const vec4& vec);
			vec4 operator*(const float& scalar);
			vec4 operator/(const vec4& vec);
			vec4 operator/(const float& scalar);

			// Advanced vector arithmetic
			float dot(const vec4& vec);
			vec4 cross(const vec4& vec);

			// Vector comparison 
			bool operator==(const vec4& vec);
			bool operator!=(const vec4& vec);

		};

		I2D std::ostream& operator<<(std::ostream& stream, const vec4& vec);

	}

}
