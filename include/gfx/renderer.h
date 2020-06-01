#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"

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
			SDL_RenderClear(m_renderer);
			SDL_SetRenderDrawColor(m_renderer, 55, 100, 55, 255);
		}

		SDL_Renderer* getRenderer() const {
			return m_renderer;
		}

	private:
		SDL_Renderer* m_renderer;
	};
}

#endif;
