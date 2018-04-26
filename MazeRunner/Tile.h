#pragma once

class Player;
class Tile {
public:
	// Constructor for the tile class
	Tile(bool wall = false, bool trap = false, bool victory = false);
	// Performs a certain action depending on the type of tile the player stepped on
	virtual void performAction(Player &victim);
	// Checks to see if a tile is a wall tile
	bool isWall() const;
	// Checks to see if a tile is a trap tile
	bool isTrap() const;
	// Checks to see if a tile is the victory tile
	bool isVictory() const;
protected:
	// Bools for the different types of tiles
	const bool wall;
	const bool trap;
	const bool victory;
};

class WallTile : public Tile {
public:
	WallTile();
};

class VictoryTile : public Tile {
public:
	VictoryTile();
};

class ResetTrap : public Tile {
public:
	ResetTrap();
	// Teleports the player back to the starting title
	void performAction(Player &victim);
};

class PauseTrap : public Tile {
public:
	// Pauses the game for 3 seconds, then resumes action
	PauseTrap(int seconds = 3);
	void performAction(Player &victim);
private:
	const int seconds;
};