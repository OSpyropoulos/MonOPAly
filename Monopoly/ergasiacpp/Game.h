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
	
	// Brown ( region = 0 )
	Asset brown1 = Asset(670, 479, "WC", 45, 0);
	Asset brown2 = Asset(607, 479, "Elevator", 50, 0);
	// Ligh Blue ( region = 1 )
	Asset lightblue1 = Asset(470, 479, "LAB_1", 70, 1);
	Asset lightblue2 = Asset(402, 479, "LAB_2", 75, 1);
	Asset lightblue3 = Asset(332, 479, "LAB_3", 80, 1);
	// Pink ( region = 2 )
	Asset pink1 = Asset(258, 415, "IT_secretariat", 150, 2);
	Asset pink2 = Asset(258, 350, "Statistical_secretariat", 140, 2);
	// Orange ( region = 3 )
	Asset orange1 = Asset(258, 220, "A_21", 100, 3);
	Asset orange2 = Asset(258, 154, "A_22", 100, 3);
	Asset orange3 = Asset(258, 87, "A_23", 100, 3);
	// Red ( region = 4 )
	Asset red1 = Asset(332, 22, "Amphitheater_A", 250, 4);
	Asset red2 = Asset(402, 22, "Amphitheater_B", 200, 4);
	Asset red3 = Asset(470, 22, "Amphitheater_C", 200, 4);
	// Yellow ( region = 5 )
	Asset yellow1 = Asset(607, 22, "Library", 180, 5);
	Asset yellow2 = Asset(670, 22, "Restaurant", 170, 5);
	// Green ( region = 6 )
	Asset green1 = Asset(742, 87, "D_21", 120, 6);
	Asset green2 = Asset(742, 154, "D_22", 120, 6);
	Asset green3 = Asset(742, 220, "D_23", 120, 6);
	// Blue ( region = 7 )
	Asset blue1 = Asset(742, 350, "Amphitheater_Derigni", 300, 7);
	Asset blue2 = Asset(742, 415, "Amphitheater_Antoniadou", 300, 7);

	// 20 asset Cards
	Asset assets[20] = { brown1,brown2,lightblue1,lightblue2,lightblue3,pink1,pink2,orange1,orange2,orange3,red1,red2,red3,yellow1,yellow2,green1,green2,green3,blue1,blue2 };

	// 4 questionmark Cards
	//Questionmark questionmarks[4];


public:
	
	void update();
	void draw();
	void init();
	Game();
	~Game();
};
