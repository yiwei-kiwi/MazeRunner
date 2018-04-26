#pragma once
#include <SFML\Graphics.hpp>
#include "Instance.h"
class DisplayInstance
{
public:
	// Constructor for the DisplayInstance class
	DisplayInstance(sf::RenderWindow &window);
	// Destructor for the DisplayInstance class
	~DisplayInstance();
	Instance game;
	bool isLost = false;
	// Renders the gameplay screen
	void render();
private:
	// The different objects for gameplay use
	sf::Texture playerSprite;
	sf::Texture wallSprite;
	sf::RectangleShape noWall;
	sf::RectangleShape wall;
	sf::RectangleShape vTile;
	sf::RectangleShape player;
	// Displays the corresponding messages for the different tiles
	void displayTrap();
	void displayLost();
	void displayVictory(int seconds = 0);
	// Deterimines what action to take depending on what key the player pressed
	void input();
	// draws the game screen
	void drawInstance();
	sf::RenderWindow &window;
};

