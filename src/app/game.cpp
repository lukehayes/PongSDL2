#include "app/game.h"

namespace App {
	Game::Game() { std::cout << "Game Loaded" << std::endl; }
	Game::~Game() { std::cout << "Game Destroyed" << std::endl; }
}