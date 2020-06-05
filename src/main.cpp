#include <iostream>
#include "SDL.h"
#include "app/game.h"
#include "entity/shape.h"
#include "math/vec2.h"
#include "gfx/color.h"
#include "gfx/renderer.h"
#include "math/util.h"
#include <cmath>
#include <list>

void render(const Gfx::Renderer& renderer, Gfx::Color c) {
	SDL_RenderClear(renderer.getRenderer());
	SDL_SetRenderDrawColor(renderer.getRenderer(), c.r, c.g, c.b, c.a);
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	App::Game g(800,600, "WINDOW");

	SDL_Window* window;
	window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, SDL_WINDOW_RESIZABLE);

	const Gfx::Renderer r(window);

	SDL_Event event;

	Shape s1(10, 300, 3);

	const int MS_PER_UPDATE = 30;
	double previous = SDL_GetTicks();
	double lag = 0.0;

	while (true)
	{

		double current = SDL_GetTicks();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		// processInput();

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		while (lag >= MS_PER_UPDATE)
		{
			// update();
			lag -= MS_PER_UPDATE;

		}

		if (!Math::moveTo(s1, 300, 300, lag)) {
			std::cout << "Moving..." << std::endl;
		}


		r.clear();
		render(r, Gfx::Color(100,200,200,255));
		SDL_RenderFillRect(r.getRenderer(), &s1);


		SDL_RenderPresent(r.getRenderer());
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

