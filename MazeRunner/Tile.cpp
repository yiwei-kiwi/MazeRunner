#include <chrono>
#include <thread>
#include "Tile.h"
#include "Player.h"

Tile::Tile(bool wall, bool trap, bool victory) : wall(wall), trap(trap), victory(victory)
{
}

void Tile::performAction(Player &victim)
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

void ResetTrap::performAction(Player &victim)
{
	victim.setCoord({ 0,0 });
}


PauseTrap::PauseTrap(int seconds) : Tile(false, true, false), seconds(seconds)
{
}

void PauseTrap::performAction(Player & victim)
{
	std::this_thread::sleep_for(std::chrono::seconds(this->seconds));
}

