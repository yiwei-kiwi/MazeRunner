#include "Util.h"

class Player
{
public:
	Player(const int teamID) : teamID(teamID) {}
	~Player();
	Coord getCoord() const;
	int getID() const;
	void setCoord(Coord newLocation);

private:
	Coord location;
	const int teamID;
};