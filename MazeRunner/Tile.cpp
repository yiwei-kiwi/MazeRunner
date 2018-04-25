#include <chrono>
#include <thread>
#include "Tile.h"
#include "Player.h"

Tile::Tile(bool wall = false, bool trap = false, bool victory = false) : wall(wall), trap(trap), victory(victory)
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

bool Tile::isVictory() const
{
	return this->victory;
}

WallTile::WallTile() : Tile(true, false, false)
{
}


VictoryTile::VictoryTile() : Tile(false, false, true)
{
}

ResetTrap::ResetTrap() : Tile(false, true, false)
{
}

void ResetTrap::preformAction(Player &victim)
{
	victim.setCoord({ 0,0 });
}

TeleportTrap::TeleportTrap() : Tile(true, false, false)
{
}

void TeleportTrap::preformAction(Player & victim)
{
	//TODO: Define this method.
}

PauseTrap::PauseTrap(int seconds) : seconds(seconds)
{
}

void PauseTrap::preformAction(Player & victim)
{
	std::this_thread::sleep_for(std::chrono::seconds(this->seconds));
}

