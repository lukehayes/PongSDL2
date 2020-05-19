#include "entity/entity.h"

namespace Entity {

	Entity::Entity(int x, int y) : x(x), y(y), w(100), h(10)
	{
		this->rect = { x,y,w,h };
	}

	Entity::~Entity() {}

	SDL_Rect Entity::getRect() const
	{
		return this->rect;
	}
}