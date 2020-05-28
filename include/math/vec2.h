#ifndef VEC2_H
#define VEC2_H

namespace Math {

	class Vec2 {

	public:
		Vec2() : x(0), y(0) {}
		Vec2(int x, int y) : x(x), y(y) {}

		Vec2& operator=(const Vec2& rhs) {
			this->x = rhs.x;
			this->y = rhs.y;

			return *this;
		}

		Vec2 operator+ (const Vec2& rhs) {
			return Vec2(
				x + rhs.x,
				y + rhs.y
			);
		}

		Vec2 operator- (const Vec2& rhs) {
			return Vec2(
				x - rhs.x,
				y - rhs.y
			);
		}

		~Vec2(){}

		int x;
		int y;

	};
}

#endif