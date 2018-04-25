#pragma once
#include <SFML\Graphics.hpp>
#include "Instance.h"
class DisplayInstance
{
public:
	DisplayInstance();
	~DisplayInstance();
	Instance game;
	
	void render();
private:
	sf::RectangleShape noWall;
	sf::RectangleShape wall;
	sf::RectangleShape vTile;
	sf::RectangleShape player;

	void displayLost();
	void displayVictory();
	void input();
	void drawInstance();
	sf::RenderWindow &window;
};

