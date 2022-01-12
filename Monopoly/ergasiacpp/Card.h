#pragma once
#include "Gameobject.h"
#include <string>

class Card : public GameObject{
protected:
	std::string description;
	float pox_x, pos_y;

public:
	void update() override;
	void draw() override;
	void init() override;

	std::string getDescription();
	void setDescription(std::string s);

};