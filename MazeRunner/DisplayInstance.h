#pragma once
#include <SFML\Graphics.hpp>
#include "Instance.h"
class DisplayInstance
{
public:
	DisplayInstance(sf::RenderWindow &window);
	~DisplayInstance();
	Instance game;
	bool isLost = false;

	void render();
private:
	sf::Texture playerSprite;
	sf::Texture wallSprite;
	sf::RectangleShape noWall;
	sf::RectangleShape wall;
	sf::RectangleShape vTile;
	sf::RectangleShape player;

	void displayTrap();
	void displayLost();
	void displayVictory(int seconds = 0);
	void input();
	void drawInstance();
	sf::RenderWindow &window;
};

