#pragma once
#include "Gameobject.h"
#include <string>

class Player : public GameObject{
private:
	float pos_x = 730, pos_y = 450 ;
	std::string icon_name;

public:
	void update() override;
	void draw() override;
	void init() override;
	Player(const std::string&);
	Player(const std::string&, float y);
};