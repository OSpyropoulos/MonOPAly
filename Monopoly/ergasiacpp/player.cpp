#include "Player.h"
#include "Config.h"
#include "graphics.h"
using namespace graphics;

bool hold = false;

void Player::update()
{
	MouseState mouse;
	getMouseState(mouse);
	float mx = windowToCanvasX(mouse.cur_pos_x);
	float my = windowToCanvasY(mouse.cur_pos_y);

	if (mx >= pos_x - 30 && mx <= pos_x + 30 && my <= pos_y + 30 && my >= pos_y - 30 || hold == true)
	{
		if (mouse.button_left_down)
		{
			pos_x = mx;
			pos_y = my;
			hold = true;
		}
		else
		{
			hold = false;
		}
	}

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

Player::Player(const std::string& icon_name): icon_name(icon_name) {}
Player::Player(const std::string& icon_name, float pos_y): icon_name(icon_name), pos_y(pos_y) {}
