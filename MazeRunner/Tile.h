#pragma once

class Player;
class Tile {
public:
	Tile(bool wall = false, bool trap = false, bool victory = false);
	virtual void preformAction(Player &victim);
	bool isWall() const;
	bool isTrap() const;
	bool isVictory() const;
protected:
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