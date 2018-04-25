#pragma once
#include "Map.h"
#include "Player.h"

class Instance
{
public:
	Instance();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	bool isVictory();
	bool isTrap();
private:
	Player player;
	Map iMap;

	void movePlayer(Coord dest);
};

