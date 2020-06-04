#ifndef SHAPE_H
#define SHAPE_H

#include "entity/entity.h"

class Shape : public Entity::Entity {
public:
	Shape(int x, int y, int s = 1) : speed(s), Entity::Entity(x, y) {}

	void update(double dt) {
		x += 1 * speed;

		if (x > 100) {
			x = 0;
		}
	}

	int speed;
};

#endif
