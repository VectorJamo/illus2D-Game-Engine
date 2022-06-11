#pragma once

#include <iostream>
#include <cmath>
#include "src/Core.h"

namespace illus2d {
	namespace maths {
		struct I2D vec2
		{
			float x, y;

			vec2();
			vec2(float x, float y);
			
			float getLength();
			vec2 getNormalVector();
			vec2 normalize();

			// Vector arithmetic 
			vec2 operator+(const vec2& vec);
			vec2 operator-(const vec2& vec);
			vec2 operator*(const vec2& vec);
			vec2 operator*(const float& scalar);
			vec2 operator/(const vec2& vec);
			vec2 operator/(const float& scalar);

			// Advanced vector arithmetic
			float dot(const vec2& vec);

			// Vector comparison 
			bool operator==(const vec2& vec);
			bool operator!=(const vec2& vec);

		};

		I2D std::ostream& operator<<(std::ostream& stream, const vec2& vec);

	}

}
