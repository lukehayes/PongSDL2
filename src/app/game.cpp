#include "app/game.h"

namespace App {

	Game::Game(int width, int height, const char* title)
	: WIDTH(width), HEIGHT(height), title(title)
	{
	}

	Game::~Game() {}
}