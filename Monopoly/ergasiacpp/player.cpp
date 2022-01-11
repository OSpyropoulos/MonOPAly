#include "Player.h"
#include "graphics.h"

using namespace graphics;


Brush br;

void Player::update()
{
}

void Player::draw()
{
	Brush br;
	br.texture = std::string(ASSET_PATH) + icon_name;
	drawRect(pos_x, pos_y,60,60, br);
	
}

void Player::init()
{
}

Player::Player(const std::string& icon) { icon_name = icon;}
Player::Player(const std::string& icon, float y) { icon_name = icon; pos_y = y; }
