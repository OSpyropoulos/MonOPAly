#include "Game.h"
#include "graphics.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace graphics;
int counter = 0 , i, price;
bool isOwned = false;
std::string desc;

// update()
void Game::update() {

	MouseState ms;
	getMouseState(ms);
	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);
	
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
				desc = "";
			}
		}
	}
	if (ms.button_left_released && active_player)
	{
		counter++;

		if (active_player->getPos_y() > 445 && active_player->getPos_y() < 490 && active_player->getPos_x() < 700 && active_player->getPos_x() > 630)
		{
			i = rand() % 20;
			desc = assets[i].getDescription();
			price = assets[i].getPrice();
			isOwned = assets[i].getIsOwned();
				
		}
		active_player->setActive(false);
		active_player = nullptr;

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

	//draw cards
	for (int i = 0; i < 20; i++) {
		assets[i].draw();
	}

	//draw balance
	if (player1 && player2)
	{
		char board[50];
		sprintf_s(board, "Balance: %6.1f",player1->getBalance()) ;
		drawText(50, 80, 20 , board, br);

		sprintf_s(board, "Balance: %6.1f", player2->getBalance());
		drawText(850, 80, 20, board, br);
	}

	//draw asset
	if (desc != "")
	{
		char p[50];
		sprintf_s(p, "Description:");
		drawText(400, 180, 20, p, br);
		sprintf_s(p ,"%s", desc.c_str());
		drawText(500, 180, 20, p, br);
		if (!isOwned)
		{
			sprintf_s(p, "Price:");
			drawText(400, 210, 20, p, br);
			sprintf_s(p, std::to_string(price).c_str());
			drawText(500, 210, 20, p, br);
		}
	}

	// draw player
	if (player1 && player2) {
		player1->draw();
		player2->draw();
	}

	// draw whose turn is it to move
	if (player1 && player2)
	{
		char info[50];
		if (cur_player == player1)
			sprintf_s(info, "cap move");
		else
			sprintf_s(info, "car move");
		drawText(425, 260, 40, info, br);
	}

}

// init()
void Game::init() {
	player1 = new Player("cap.png");
	player1->setPos_x(730);
	player1->setPos_y(450);
	player1->setBalance(2000);
	
	player2 = new Player("car.png");
	player2->setPos_x(730);
	player2->setPos_y(480);
	player2->setBalance(2000);


	setFont(std::string(ASSET_PATH) + "font.ttf");


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