#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "entity/shape.h"

namespace Gfx {

	class Renderer {

	public:

		Renderer(SDL_Window* window) {
			this->m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
		}

		~Renderer() {
			SDL_DestroyRenderer(m_renderer);
		}

		void clear() const {
			SDL_SetRenderDrawColor(m_renderer, 55, 100, 55, 255);
			SDL_RenderClear(m_renderer);
		}

		SDL_Renderer* getRenderer() const {
			return m_renderer;
		}

        /**
         * Draw an Entity to the screen
         */
        void draw(const Entity::Entity& entity, Gfx::Color drawColor = {255,0,255,255}) {
			SDL_SetRenderDrawColor(m_renderer, 
                    drawColor.r,
                    drawColor.g,
                    drawColor.b,
                    drawColor.a
            );
            SDL_RenderFillRect(m_renderer, &entity);
        }

        
        /**
         * Draw the current contents to the screen
         */
        void present() {
            SDL_RenderPresent(m_renderer);
        }

	private:
		SDL_Renderer* m_renderer;
	};
}

#endif
