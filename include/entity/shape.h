#ifndef SHAPE_H
#define SHAPE_H

#include "entity/entity.h"

namespace Entity {
    
class Shape : public Entity::Entity {
public:
	Shape(int x, int y, int s = 1) : speed(s), Entity::Entity(x, y) {}

	void update(double dt) {
		x += 1 * speed * dt;

		if (x > 100) {
			x = 0;
		}
	}

	double speed;
};

} /* namespace Entity */

#endif
