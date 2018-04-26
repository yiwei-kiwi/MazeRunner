#pragma once
#include <SFML/Graphics.hpp>

class GameMenu
{
public:
	// Runs the game
	void launchGame(void);
private:
	// Draws a rounded rectangle
	void drawRoundedRectangle(int posXCircleLeft, int posYCircleLeft, sf::RenderWindow &window);
	int checkMousePosMenu(sf::Event pos);//return 0 for no, 1 for start,2 for rules, 3 for exit?
	int checkMousePosClick(sf::Event pos);//return 0 for no, 1 for start,2 for rules, 3 for exit?
	void HighlightRoundedRectangle(int posXCircleLeft, int posYCircleLeft, sf::RenderWindow &window);
	// Shows the rules of the game to the user
	void displayGameRules(sf::RenderWindow &window, sf::Text rules, sf::Font font);
	void drawBackArrow(int posXTriTop, int posYTriTop, sf::RenderWindow &window);
};

