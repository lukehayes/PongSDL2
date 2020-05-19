#include "entity/entity.h"

namespace Entity {

	Entity::Entity(int x, int y) : x(x), y(y), w(100), h(10)
	{}

	Entity::~Entity() {}
}