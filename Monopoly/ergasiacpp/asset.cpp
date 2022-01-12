#include "Asset.h"

// returns the price of the asset
int Asset::getPrice()
{
	return price;
}

// returns the region of the asset (integer from 1 to 6) 
int Asset::getRegion()
{
	return region;
}

// returns the rank of the asset (how many buldings are built on the asset starting from 0)
int Asset::getRank()
{
	return rank;
}

// upgrades the rank of the assets if a new bulding is bought
void Asset::upgradeRank()
{
	rank++;
}

// returns true if the asset is owned by a player
bool Asset::getIsOwned()
{
	return IsOwned;
}

// sets IsOwned true, when someone buys this asset
void Asset::setIsOwned()
{
	IsOwned = true;
}

// Only Constructor for Asset objects
Asset::Asset(const int& pos_x, const int& pos_y, const std::string& description, const int& price, const int& region):Card(pos_x,pos_y,description), price(price), region(region){}
