#pragma once
#include "Map.h"
#include "Player.h"

class Instance
{
public:
	// Constructor for the Instance class
	Instance();
	// Moves the player to a tile depending on their input
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	// Checks to see if the victory tile has been reached
	bool isVictory();
	// Checks to see if a trap tile has been activated
	bool isTrap();
	// Getter for the Player
	Player& getPlayer();
	// Getter for the map
	Map& getMap();
	/* If a trap has been triggered, runs the performAction function to
	 determine what type of trap was activated and performs the corresponding
	 actions */
	void activateTrap();
private:
	Player player;
	Map iMap;
	// Moves the player from their current coordinates to another set of coordinates
	void movePlayer(Coord dest);
};

