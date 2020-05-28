#ifndef ENTITY_H
#define ENTITY_H

#include "SDL_rect.h";

namespace Entity {

	class Entity : public SDL_Rect {

	public:
		Entity(int x, int y);
		Entity(const Entity& rhs);
		Entity& operator=(const Entity& rhs);
		
		virtual void update(double dt) = 0;

		~Entity();
	private:

	};
}

#endif