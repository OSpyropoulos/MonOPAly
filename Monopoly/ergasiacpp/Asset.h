#pragma once
#include "Card.h"

class Asset : public Card{

protected:
	// price = amount of cash & region = color/quality of the card
	const int price , region;
	// the number of the rank is equal to how many houses are built
	int rank = 0;
	// IsOwned -> true if it is not available, false if it is
	bool IsOwned = false;

public:
	void draw() override;
	int getPrice();
	int getRegion();
	int getRank();
	void upgradeRank();
	bool getIsOwned();
	void setIsOwned();
	Asset(const int&, const int&, const std::string&, const int&, const int&);

};