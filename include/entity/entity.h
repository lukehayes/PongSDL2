#ifndef ENTITY_H
#define ENTITY_H

#include "SDL_rect.h";
#include "gfx/color.h"

namespace Entity {

	class Entity : public SDL_Rect {

	public:
		Entity(int x, int y, Gfx::Color = Gfx::Color(255,200,0,255)); 
		Entity(const Entity& rhs);
		Entity& operator=(const Entity& rhs);
		
		void update(double dt) {}

		~Entity();
	private:
		Gfx::Color color;

	};
}

#endif