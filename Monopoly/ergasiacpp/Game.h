#pragma once
#include "graphics.h"
#include "Config.h"
#include "Player.h"
#include "Asset.h"
#include "Questionmark.h"

class Game {
	// the Game has:
	// 
	// 2 players
protected:
	Player *player1 = nullptr;
	Player *player2 = nullptr;

	Player* active_player = nullptr;

	// 27 cards in total
	// 27 onomata aithouswn sto description & sto rank ena int poy ua phgainei se kapoio xrwma me sygkekrimeno brush to kathena
	// p.x. rank 0 -> kafe -> Brush	Brush br { 0.58f, 0.32f, 0.2f }
	Asset kafe1 = Asset(670, 472, "D11", 69, 0);

	// 20 asset Cards
	//Asset assets[20];

	// 4 questionmark Cards
	//Questionmark questionmarks[4];


public:
	enum game_state_t {STATE_INIT , STATE_IDLE , STATE_MOVING};

	void update();
	void draw();
	void init();
	Game();
	~Game();
};
