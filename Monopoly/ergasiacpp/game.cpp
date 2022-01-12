#include "Game.h"

using namespace graphics;

// update()
void Game::update() {
	if (getGlobalTime() > 2000) {
		player1 = new Player("cap.png");
		player2 = new Player("car.png",480);
	}
}

// draw()
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

	kafe1.draw();

	//draw cards
	/*
	* 	for (int i; i < 28; i++) {
		cards[i]->draw();
	}
	*/

}

// init()
void Game::init() {

}

// Constructor
Game::Game()
{
}

// Destructor
Game::~Game()
{
	if (player1 && player2) {
		delete player1;
		delete player2;
	}
}