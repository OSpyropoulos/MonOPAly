#include "Game.h"
#include "graphics.h"

using namespace graphics;
int counter = 0;

// update()
void Game::update() {

	MouseState ms;
	getMouseState(ms);
	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);

	Player* cur_player = nullptr;
	
	if (counter % 2 == 0)
		cur_player = player1;
	else
		cur_player = player2;

	if (cur_player->contains(mx, my))
		active_player = cur_player;

	//moving a player
	if (ms.dragging && active_player)
	{
		active_player->setPos_x(mx);
		active_player->setPos_y(my);
	}
	if (ms.button_left_released && active_player)
	{
		active_player->setActive(false);
		active_player = nullptr;
		counter++;
	}

}


// draw()
void Game::draw() {
	Brush br;
	br.texture = std::string(ASSET_PATH) + "board.png";
	br.outline_opacity = 0.0f;

	// draw background
	drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	kafe1.draw();

	// draw player
	if (player1 && player2) {
		player1->draw();
		player2->draw();
	}

	

	//draw cards
	/*
	* 	for (int i; i < 28; i++) {
		cards[i]->draw();
	}
	*/

}

// init()
void Game::init() {
	player1 = new Player("cap.png");
	player1->setPos_x(730);
	player1->setPos_y(450);
	player2 = new Player("car.png");
	player2->setPos_x(730);
	player2->setPos_y(480);
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