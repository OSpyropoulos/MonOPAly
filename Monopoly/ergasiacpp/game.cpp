#include "Game.h"
#include "graphics.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <random>

using namespace graphics;
int counter = 0 , i, price;
bool isOwned = false, isOwnedbyPlayer1 = false, ongoingPayment = false, cantpurchase = false;
std::string desc;

// update()
void Game::update() {

	MouseState ms;
	getMouseState(ms);
	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);

	if (counter % 2 == 0)
	{
		cur_player = player1;
		next_player = player2;
	}
	else
	{
		cur_player = player2;
		next_player = player1;
	}

	if (cur_player->contains(mx, my))
		active_player = cur_player;

	//moving a player
	if (ms.dragging && active_player)
	{
		if (mx > 225 && mx < 772 && my < 490 && my > 10) //restricting the player within the borders
		{
			if (my > 445 || my < 40 && mx >300 && mx < 710 || mx < 300 || mx >710)
			{
				active_player->setPos_x(mx);
				active_player->setPos_y(my);
				desc = "";
			}
		}
	}

	if (ms.button_left_released && active_player)
	{

		// "shuffle" the cards (just change the position)
		//for (i = 0; i < 20; i++)
		{
			//size_t j = i + rand() / (RAND_MAX / (20 - i) + 1);
			//float tempX = assets[j].getX();
			//float tempY = assets[j].getY();
			//assets[j].setX(assets[i].getX());
			//assets[j].setY(assets[i].getY());
			//assets[i].setX(tempX);
			//assets[i].setY(tempY);
		}

		for (int i = 0; i < 20; i++)
		{
			if (mx > assets[i].getX() - 35 && mx<assets[i].getX() + 10 && my>assets[i].getY() - 40 && my < assets[i].getY() + 30) {
				cur_asset = assets[i];
				desc = cur_asset.getDescription();
				price = cur_asset.getPrice();
				isOwned = cur_asset.getIsOwned();
				isOwnedbyPlayer1 = cur_asset.getIsOwnedbyPlayer1();
				ongoingPayment = true;
				cantpurchase = false;
			}
		}

		counter++;
		active_player->setActive(false);
		active_player = nullptr;

		//auto rng = std::default_random_engine{};
		//std::shuffle(std::begin(assets), std::end(assets), rng);
	}

	if (isOwned && ongoingPayment)
	{
		if (isOwnedbyPlayer1)
		{
			if (cur_player == player2)
			{
				player1->setBalance(player1->getBalance() + cur_asset.getPrice());
				player2->setBalance(player2->getBalance() - cur_asset.getPrice());
			}
		}
		else
			if (cur_player == player1)
			{
				player1->setBalance(player1->getBalance() - cur_asset.getPrice());
				player2->setBalance(player2->getBalance() + cur_asset.getPrice());
			}
		ongoingPayment = false;
	}
	else if (ongoingPayment && !isOwned)
	{
		if (getKeyState(SCANCODE_Y))
		{
			if (cur_player->getBalance() > price)
			{
				ongoingPayment = false;
				cur_asset.setIsOwned();
				isOwned = true;
				cur_player->setBalance(cur_player->getBalance() - cur_asset.getPrice());
				if (cur_player == player1)
					cur_asset.setIsOwnedbyPlayer1();
			}
			else
				cantpurchase = true;
		}
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
		br.fill_color[0] = 0;
		br.fill_color[1] = 0;
		br.fill_color[2] = 0;

		assets[i].draw();
		char p[50];
		// if the asset's description is bigger than 10 letters
		if (assets[i].getDescription().length() > 10)
		{
			sprintf_s(p, "%s", assets[i].getDescription().c_str());
			drawText(assets[i].getX() - 32, assets[i].getY() - 10, 10, p, br);
		}
		else
		{
			sprintf_s(p, "%s", assets[i].getDescription().c_str());
			drawText(assets[i].getX() - 20, assets[i].getY() - 10, 12, p, br);
		}

		sprintf_s(p, "EUR  %s",std::to_string(assets[i].getPrice()).c_str());
		drawText(assets[i].getX()-25, assets[i].getY()+20, 15, p, br);

	}

	//draw balance
	if (player1 && player2)
	{
		char board[50];
		sprintf_s(board, "Balance: %6.1f  EUR",player1->getBalance()) ;
		drawText(30, 80, 20 , board, br);

		sprintf_s(board, "Balance: %6.1f  EUR", player2->getBalance());
		drawText(820, 80, 20, board, br);
	}

	// draw player
	if (player1 && player2) {
		player1->draw();
		player2->draw();
	}

	// draw messages at the center of the board
	if (player1 && player2)
	{
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		char info[50];
	
		// question for acquisition
		if (isOwned == false) {
			if (cantpurchase)
			{
				sprintf_s(info, "Not enough funds");
				drawText(355, 190, 37, info, br);
			}
			else
			{
				sprintf_s(info, "Do you want to Buy ");
				drawText(348, 190, 22, info, br);
				sprintf_s(info, "Y (for Yes)  ||   N (for No)");
				drawText(430, 220, 15, info, br);

				br.fill_color[0] = 0;
				br.fill_color[1] = 0;
				br.fill_color[2] = 0;
				sprintf_s(info, "%s", desc.c_str());
				// if the asset's description is big
				if (desc.length() > 10)
				{
					drawText(510, 190, 20, info, br);
				}
				else
				{
					drawText(520, 190, 30, info, br);
				}
			}
		}
		// message for payment
		else {
			// if the current player can't afford the fine -> GAME OVER
			if ((price * 0.1) > cur_player->getBalance())
			{
			sprintf_s(info, "GAME IS OVER");
			drawText(355, 190, 37, info, br);
			}
			else
			{
			sprintf_s(info, "Property owned");
			drawText(355, 190, 37, info, br);
			}
		}
		// whose turn it is next
		if (cur_player == player1)
			sprintf_s(info, "cap move");
		else
			sprintf_s(info, "car move");
		drawText(445, 270, 30, info, br);
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
	playMusic(std::string(ASSET_PATH) + "soundtrack.mp3",0.1f,false,4000);

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