#include "Assets.h"

void Assets::draw()
{
}

//returns true if the asset is owned by a player
bool Assets::getIsOwned()
{
	return IsOwned;
}

//returns the description of the card ( name of the asset )
std::string Assets::getDescription()
{
	return description;
}


//returns the price of the asset
int Assets::getPrice()
{
	return price;
}

//returns the rank of the asset (how many buldings are built on the asset starting from 0)
int Assets::getRank()
{
	return rank;
}

//upgrades the rank of the assets if a new bulding is bought
void Assets::upgradeRank()
{
	rank++;
}
//returns the region of the asset (integer from 1 to 6) 
int Assets::getRegion()
{
	return region;
}
