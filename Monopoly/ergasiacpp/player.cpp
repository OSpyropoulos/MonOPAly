#include "Player.h"
#include "Config.h"
#include "graphics.h"
using namespace graphics;


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

Player::Player(const std::string& icon_name): icon_name(icon_name) {}
Player::Player(const std::string& icon_name, float pos_y): icon_name(icon_name), pos_y(pos_y) {}
