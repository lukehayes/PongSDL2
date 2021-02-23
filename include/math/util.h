#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include "entity/entity.h"
#include <iostream>

namespace Math {
	
	void moveTo(Entity::Entity& entity, int x, int y, double dt) {
		entity.x -= x * dt;
		entity.y -= y * dt;
	}
}

#endif
