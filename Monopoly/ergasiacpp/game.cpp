#include "Game.h"
#include "graphics.h" 
#include "Config.h"

using namespace graphics;

	void Game::update() {
		if (getGlobalTime() > 2000) {
			player1 = new Player("cap.png");
			player2 = new Player("car.png",480);
		}
	}

	void Game::draw() {
		Brush br;
		br.texture = std::string(ASSET_PATH) + "board.png";
		br.outline_opacity = 0.0f;

		// draw background
		drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		// draw player
		if (player1 && player2) {
			player1->draw();
			player2->draw();
		}


	}

	void Game::init() {

	}
	Game::Game()
	{
	}

	Game::~Game()
	{
		if (player1 && player2) {
			delete player1;
			delete player2;
		}
	}