#ifndef ENTITY_H
#define ENTITY_H

#include "SDL_rect.h";

namespace Entity {

	class Entity {

	public:
		Entity(int x, int y);
		~Entity();

		int x;
		int y;
		int w;
		int h;

	private:

	};
}

#endif