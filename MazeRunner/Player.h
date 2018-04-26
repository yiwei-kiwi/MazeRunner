#include "Util.h"

class Player
{
public:
	// Constructor for the Player class
	Player(const int teamID) : teamID(teamID) {}
	// Destructor for the Player class
	~Player();
	// Getter for the location coordinates
	Coord getCoord() const;
	// Getter for the teamID
	int getID() const;
	// Setter for the location coordinates
	void setCoord(Coord newLocation);

private:
	// The coordinates of the current location
	Coord location;
	// Determines what team the current user is on
	const int teamID;
};