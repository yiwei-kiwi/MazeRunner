#include <Windows.h>
#include <string>
#include "DisplayInstance.h"
#include "Map.h"

DisplayInstance::DisplayInstance(sf::RenderWindow &window) : game(), window(window),
noWall(sf::Vector2f(100, 100)),
wall(sf::Vector2f(100, 100)),
vTile(sf::Vector2f(100, 100)),
player(sf::Vector2f(100, 100))
{
	playerSprite.loadFromFile("mazeRunnerTextures.png");
	wallSprite.loadFromFile("mazeRunnerTextures.png");
	noWall.setFillColor(sf::Color(0,92,9));
	vTile.setFillColor(sf::Color::Yellow);
	wall.setTexture(&wallSprite);
	wall.setTextureRect(sf::IntRect(0, 0, 100, 100));
	player.setTexture(&playerSprite);
	player.setTextureRect(sf::IntRect(0, 100, 100, 100));
}


DisplayInstance::~DisplayInstance()
{
}

void DisplayInstance::render()
{
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:
				this->isLost = true;
				break;
			}
		}

		this->input();

		this->window.clear();
		this->drawInstance();
		this->window.display();

		if (game.isTrap()) {
			this->displayTrap();
			game.activateTrap();
		}

		if (game.isVictory()) {
			this->displayVictory();
			break;
		}
		if (this->isLost) {
			this->displayLost();
			break;
		}
	}
}

void DisplayInstance::displayTrap()
{
	MessageBox(NULL, "You just activated my trap card! ;)", "Trap", MB_OK);
}

void DisplayInstance::displayLost()
{
	MessageBox(NULL, "You lost!", "Loser :(", MB_OK);
}

void DisplayInstance::displayVictory(int seconds)
{
	std::string message;
	if (seconds == 0) {
		message = "Congrats you win!";
	}
	else {
		message = "Congrats you win!\nYou have a time of " + std::to_string(seconds) + "seconds!";
	}
	MessageBox(NULL, message.c_str(), "Winner!", MB_OK);
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
	auto playerLocation = game.getPlayer().getCoord();
	xDiff = playerLocation.x - 4;
	yDiff = playerLocation.y - 4;
	for (int x = 0; x < 9; ++x) {
		for (int y = 0; y < 9; ++y) {
			Coord location = { x + xDiff, y + yDiff };
			sf::Vector2f renderLocation((float)(x * 100), (float)(y * 100));
			if (game.getMap().isCoordInBound(location)) {
				if (game.getMap().getTile(location)->isWall()) {
					this->wall.setPosition(renderLocation);
					window.draw(this->wall);
				}
				else if (game.getMap().getTile(location)->isVictory()) {
					this->vTile.setPosition(renderLocation);
					window.draw(this->vTile);
				}
				else {
					this->noWall.setPosition(renderLocation);
					window.draw(this->noWall);
				}
			}
		}
	}
	player.setPosition(400, 400);
	this->window.draw(this->player);
}
