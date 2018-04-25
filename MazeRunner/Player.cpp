#include "Player.h"

Player::~Player()
{

}

Coord Player::getCoord() const
{
	return location;
}

void Player::setCoord(Coord newLocation)
{
	location = newLocation;
}

int Player::getID() const
{
	return teamID;
}