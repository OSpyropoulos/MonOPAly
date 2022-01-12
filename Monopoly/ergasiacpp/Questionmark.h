#pragma once
#include "Card.h"

class Questionmark : public Card {
private:
	int fee;

public:
	void draw();
	int getFee();
	std::string getDescription();
};