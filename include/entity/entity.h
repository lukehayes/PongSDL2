#ifndef ENTITY_H
#define ENTITY_H

#include "SDL_rect.h";

namespace Entity {

	class Entity {

	public:
		Entity(int x, int y);
		Entity(const Entity& rhs);
		~Entity();

		SDL_Rect getRect() const;

		int x;
		int y;
		int w;
		int h;

	private:
		SDL_Rect rect;

	};
}

#endif