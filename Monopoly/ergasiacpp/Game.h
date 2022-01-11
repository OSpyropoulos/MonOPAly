#pragma once
#include "graphics.h"
#include "Player.h";

class Game {
	Player *player1 = nullptr;
	Player* player2 = nullptr;
	 
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();
};
