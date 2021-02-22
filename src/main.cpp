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

    Entity::Shape s1(100.0, 300.0, 50);
    Entity::Shape s2(300, 100, 100);


	const int MS_PER_UPDATE = 30;
	double previous = SDL_GetTicks();
	double lag = 0.0;
	double delta = 0.0;

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
            delta = lag/MS_PER_UPDATE;

            std::cout << delta << std::endl;


            s1.update(delta);
            s2.update(delta);

		}


        r.clear();
        r.draw(s2, Gfx::BLACK);
        r.draw(s1);
        r.present();
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

