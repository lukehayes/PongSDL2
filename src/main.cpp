#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer);

	SDL_Event event;

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

		// render();
		SDL_SetRenderDrawColor(renderer, 0, 150, 0, 155);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

