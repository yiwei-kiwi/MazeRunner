#include "Tile.h"

Tile::Tile(bool wall, bool trap) : wall(wall), trap(trap)
{
}

void Tile::preformAction(Player &victim)
{
	//nothing, an emtpy tile does nothing
}

bool Tile::isWall() const
{
	return this->wall;
}

bool Tile::isTrap() const
{
	return this->trap;
}

WallTile::WallTile() : Tile(true, false)
{
}

ResetTrap::ResetTrap() : Tile(false, true)
{
}

void ResetTrap::preformAction(Player &victim)
{
}
