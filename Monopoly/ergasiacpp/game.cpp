#include "Game.h"
#include "graphics.h"
#include <stdlib.h>
#include <algorithm>

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
		if (mx > 225 && mx < 772 && my <490 && my > 10) //restricting the player within the borders
		{
			if (my > 445 || my < 40 && mx >300 && mx <710 || mx <300 || mx >710)
			{
				active_player->setPos_x(mx);
				active_player->setPos_y(my);
			}
		}
	}
	if (ms.button_left_released && active_player)
	{
		active_player->setstartingPos_x(mx);
		active_player->setstartingPos_y(my);
		active_player->setActive(false);
		active_player = nullptr;
		counter++;

		//std::random_shuffle(std::begin(assets), std::end(assets));
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

	//draw cards
	for (int i=0; i < 20; i++) {
		assets[i].draw();
	}

}

// init()
void Game::init() {
	player1 = new Player("cap.png");
	player1->setPos_x(730);
	player1->setPos_y(450);
	player1->setstartingPos_x(730);
	player1->setstartingPos_y(450);
	player2 = new Player("car.png");
	player2->setPos_x(730);
	player2->setPos_y(480);
	player2->setstartingPos_x(730);
	player2->setstartingPos_y(480);
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