#pragma once
#include "Gameobject.h"
#include <string>

class Player : public GameObject{
private:
	float pos_x, pos_y;
	int counter = 1;
	std::string icon_name;
	bool active = false;

public:
	void update() override;
	void draw() override;
	void init() override;

	int getCounter();

	float getPos_x();
	float getPos_y();
	void setPos_x(float x);
	void setPos_y(float y);
	void setActive(bool x);

	Player(const std::string&);
	Player(const std::string&, float y);

	bool contains(float x, float y);
};