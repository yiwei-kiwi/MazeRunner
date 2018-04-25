#pragma once

class Player;
class Tile {
public:
	Tile(bool wall = false, bool trap = false);
	virtual void preformAction(Player &victim);
	bool isWall() const;
	bool isTrap() const;
protected:
	const bool wall;
	const bool trap;
};

class WallTile : public Tile {
public:
	WallTile();
};

class ResetTrap : public Tile {
public:
	ResetTrap();
	void preformAction(Player &victim);
};

class TeleportTrap : public Tile {
public:
	TeleportTrap();
	void preformAction(Player &victim);
};

class PauseTrap : public Tile {
public:
	PauseTrap(int seconds);
	void preformAction(Player &victim);
private:
	const int seconds;
};