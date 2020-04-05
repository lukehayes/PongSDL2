#ifndef APP_GAME_H
#define APP_GAME_H

namespace App {

	class Game {
	public:
		Game(int width, int height, const char* title);
		~Game();
	private:
		const int WIDTH;
		const int HEIGHT;
		const char* title;

	};
}

#endif