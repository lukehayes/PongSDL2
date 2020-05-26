#include "entity/entity.h"
#include <iostream>

namespace Entity {

	Entity::Entity(int x, int y) : x(x), y(y), w(10), h(10)
	{
		this->rect = { x,y,w,h };
	}

	Entity::Entity(const Entity& rhs) : x(rhs.x), y(rhs.y), w(rhs.w), h(rhs.h)
	{
		this->rect = { x,y,w,h };
	}

	Entity::~Entity() {}

	SDL_Rect Entity::getRect() const
	{
		return this->rect;
	}
}