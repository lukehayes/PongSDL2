#include <iostream>
#include "SDL.h"
#include "app/game.h"
#include "entity/shape.h"
#include "math/vec2.h"
#include "gfx/color.h"
#include "gfx/renderer.h"
#include "math/util.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	App::Game g(800,600, "WINDOW");

	SDL_Window* window;
	window = SDL_CreateWindow("Sand Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, SDL_WINDOW_RESIZABLE);

	Gfx::Renderer r(window);

	SDL_Event event;

    Entity::Shape s1(100, 300, 3);


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


        r.draw(s1);
        r.present();
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

