#include "entity/entity.h"
#include <iostream>

namespace Entity {

	Entity::Entity(int x, int y, Gfx::Color c)
	{
		this->x = x;
		this->y = y;
		this->w = 10;
		this->h = 10;
		this->color = c;
	}

	Entity::Entity(const Entity& rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->w = rhs.w;
		this->h = rhs.h;
	}

	Entity& Entity::operator=(const Entity& rhs) 
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->w = rhs.w;
		this->h = rhs.h;
	
		return *this;
	}

	Entity::~Entity() {}
}