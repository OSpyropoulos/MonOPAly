#pragma once
#include "Gameobject.h"

class Card : public GameObject{

public:
	void update() override;
	void draw() override;
	void init() override;
};