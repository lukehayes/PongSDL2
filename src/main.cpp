#include <iostream>
#include "SDL.h"
#include "app/game.h"
#include <cmath>

class Shape {
public:

	Shape() {
		this->r.x = 100;
		this->r.y = 100;
		this->r.w = 10;
		this->r.h = 10;
	}
	
	void update(float delta) {
		this->r.x = this->r.x + 1;
		this->r.y = this->r.y + 1;
	}

	void render(SDL_Renderer* renderer) {
		SDL_RenderFillRect(renderer, &this->r);
	}

	SDL_Rect r;
	int x = 100;
	int y = 100;
};

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	App::Game g(800,600, "WINDOW");

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer);

	SDL_Event event;

	Shape shape;

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
			shape.update(10.0);
			lag -= MS_PER_UPDATE;
		}

		// render();
		SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		shape.render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

