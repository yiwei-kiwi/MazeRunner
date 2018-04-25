#include "Player.h"

Player::Player(const teamID) : teamID(teamID)
{
	location.x = 0;
	location.y = 0;
}

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