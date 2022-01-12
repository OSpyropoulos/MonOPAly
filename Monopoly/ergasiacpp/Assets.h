#pragma once
#include "Card.h"

class Assets : public Card{

protected:
	const int price , region;
	int rank = 0;
	bool IsOwned = false;

public:
	void draw() override;

	bool getIsOwned();

	std::string getDescription();

	int getPrice();

	int getRank();
	void upgradeRank();

	int getRegion();
};