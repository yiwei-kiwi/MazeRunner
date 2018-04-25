#include <Windows.h>
#include "DisplayInstance.h"
#include "Map.h"

DisplayInstance::DisplayInstance() : game(),
noWall(sf::Vector2f(100, 100)),
wall(sf::Vector2f(100, 100)),
vTile(sf::Vector2f(100, 100)),
player(sf::Vector2f(100, 100))
{
	noWall.setFillColor(sf::Color::Green);
	wall.setFillColor(sf::Color::Black);
	vTile.setFillColor(sf::Color::Yellow);
	//TODO: set player texture file
}


DisplayInstance::~DisplayInstance()
{
}

void DisplayInstance::render()
{
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		this->input();
		if (game.isVictory()) {
			this->displayVictory();
		}
		//is lost
		if (game.isTrap()) {
			//TODO: activate trap
		}


	}
}

void DisplayInstance::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		game.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		game.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		game.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		game.moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		game.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		game.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		game.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		game.moveDown();
	}
}

void DisplayInstance::drawInstance()
{
	int xDiff = 0, yDiff = 0;
	auto location = game.getPlayer().getCoord();
	xDiff = location.x - 4;
	yDiff = location.y - 4;
	for (int x = 0; x < 9; ++x) {
		for (int y = 0; y < 9; ++y) {
			if (game.getMap().getTile())
		}
	}
}
