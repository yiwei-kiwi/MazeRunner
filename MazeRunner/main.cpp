#include <SFML\Graphics.hpp>
#include "DisplayInstance.h"
#include "GameMenu.h"

int main(int argc, char *argv[]) {
	/*sf::RenderWindow newWindow(sf::VideoMode(900,900), "Window", sf::Style::Close);
	DisplayInstance instance1(newWindow);*/
	GameMenu myMenu;
	myMenu.launchGame();
	//instance1.render();
	return 0;
}