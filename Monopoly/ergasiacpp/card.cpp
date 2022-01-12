#include "Card.h"
#include "Config.h"
#include "graphics.h"
#include <string>
using namespace graphics;


void Card::update()
{
}

void Card::draw()
{
	Brush br;
	br.fill_color[0] = 0.58f;
	br.fill_color[1] = 0.32f;
	br.fill_color[2] = 0.2f;
	drawRect(pos_x, pos_y, 75, 55, br);
}

void Card::init()
{
}

// if the Card object is Asset, returns the name, else (if Questionmark) returns the paragraph 
std::string Card::getDescription()
{
	return description;
}

Card::Card(const int& pos_x, const int& pos_y, const std::string& description ): pos_x(pos_x), pos_y(pos_y), description(description) {}
