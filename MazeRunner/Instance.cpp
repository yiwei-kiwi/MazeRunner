#include "Instance.h"

Instance::Instance() : player(0), iMap(500, 500)
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
	Tile *temp = nullptr;
	
	temp = iMap.getTile(player.getCoord());
	
	return temp->isVictory();

}

bool Instance::isTrap()
{
	Tile *temp = nullptr;

	temp = iMap.getTile(player.getCoord());
	
	return temp->isTrap();
}

void Instance::activateTrap()
{
	if (this->isTrap())
	{
		iMap.getTile(player.getCoord())->performAction(player);
	}
}

Player & Instance::getPlayer()
{
	return this->player;
}

Map &Instance::getMap()
{
	return this->iMap;
}

void Instance::movePlayer(Coord dest)
{
	Tile *temp = nullptr;

	temp = iMap.getTile(dest);

	if (!temp->isWall())
	{
		player.setCoord(dest);
	}
}
