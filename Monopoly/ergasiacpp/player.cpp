#include "graphics.h"
#include "scancodes.h"
#include "Player.h"

using namespace graphics;

void Player::update()
{

}

void Player::draw()
{
	Brush br;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.3f; 
	drawRect(pos_x, pos_y, 40, 40, br);

}

void Player::init()
{
}
