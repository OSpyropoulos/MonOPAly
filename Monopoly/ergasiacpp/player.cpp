#include "Player.h"
#include "Config.h"
#include "graphics.h"
#include "Game.h"

using namespace graphics;

bool hold = false;
bool ended = false;

void Player::update()
{

}

void Player::draw()
{
	Brush br;
	br.texture = std::string(ASSET_PATH) + icon_name;
	br.outline_opacity = 0.0f;
	drawRect(pos_x, pos_y,60,60, br);
	
}

void Player::init()
{
}

int Player::getCounter()
{
	return counter;
}

float Player::getPos_x()
{
	return pos_x;
}

float Player::getPos_y()
{
	return pos_y;
}

void Player::setPos_x(float x)
{
	pos_x = x;
}

void Player::setPos_y(float y)
{
	pos_y = y;
}
void Player::setActive(bool x)
{
	active = x;
}
bool Player::contains(float x, float y)
{
	return (x >= pos_x - 30 && x <= pos_x + 30 && y <= pos_y + 30 && y >= pos_y - 30);
}

Player::Player(const std::string& icon_name): icon_name(icon_name) {}
Player::Player(const std::string& icon_name, float pos_y): icon_name(icon_name), pos_y(pos_y) {}

// returns true if the cursor is on a player

