#include "Instance.h"

Instance::Instance() : player(0), iMap(/*TODO: wait for map*/)
{
}

void Instance::moveRight()
{
	auto location = player.getCoord();
	this->movePlayer({ location.x + 1, location.y });
}

void Instance::moveLeft()
{
	auto location = player.getCoord();
	this->movePlayer({ location.x - 1, location.y });
}

void Instance::moveUp()
{
	auto location = player.getCoord();
	this->movePlayer({ location.x, location.y - 1 });
}

void Instance::moveDown()
{
	auto location = player.getCoord();
	this->movePlayer({ location.x, location.y + 1 });
}

bool Instance::isVictory()
{
	//TODO: wait for map
}

bool Instance::isTrap()
{
	//TODO: wait for map
}

void Instance::movePlayer(Coord dest)
{
	//TODO: wait for map
}
