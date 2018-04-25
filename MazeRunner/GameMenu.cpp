#include "GameMenu.h"
#include "DisplayInstance.h"

void GameMenu::drawRoundedRectangle(int posXCircleLeft, int posYCircleLeft, sf::RenderWindow &window)
{
	const sf::Vector2f rectLine(380, 0);
	const sf::Vector2f rectFill(380, 92.5);
	const sf::Vector2f circle1(posXCircleLeft, posYCircleLeft);
	const sf::Vector2f circle2(posXCircleLeft + 380, posYCircleLeft);
	const sf::Vector2f Fill(posXCircleLeft + 45, posYCircleLeft - 2.5);
	const sf::Vector2f line2(posXCircleLeft + 45, posYCircleLeft + 92.5);

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(5);
	circle.setRadius(45);

	sf::RectangleShape rectangleLine;
	rectangleLine.setSize(rectLine);
	rectangleLine.setOutlineThickness(2.5);

	sf::RectangleShape rectangleFill;
	rectangleFill.setSize(rectFill);
	rectangleFill.setFillColor(sf::Color::Black);

	circle.setPosition(circle1);
	window.draw(circle);

	circle.setPosition(circle2);
	window.draw(circle);

	rectangleFill.setPosition(Fill);
	window.draw(rectangleFill);

	rectangleLine.setPosition(Fill);
	window.draw(rectangleLine);

	rectangleLine.setPosition(line2);
	window.draw(rectangleLine);
}

int GameMenu::checkMousePosMenu(sf::Event pos)//return 0 for no, 1 for start,2 for rules, 3 for exit?
{
	float x = pos.mouseMove.x;
	float y = pos.mouseMove.y;
	if ((x < 723) && (x > 253) && (y < 540) && (y > 450))
	{
		return 1;
	}
	else if ((x < 727) && (x > 257) && (y < 740) && (y > 650))
	{
		return 2;
	}
	else if ((x < 725) && (x > 255) && (y < 940) && (y > 850))
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int GameMenu::checkMousePosClick(sf::Event pos)//return 0 for no, 1 for start,2 for rules, 3 for exit?
{
	float x = pos.mouseButton.x;
	float y = pos.mouseButton.y;
	if ((x < 723) && (x > 253) && (y < 540) && (y > 450))
	{
		return 1;
	}
	else if ((x < 727) && (x > 257) && (y < 740) && (y > 650))
	{
		return 2;
	}
	else if ((x < 725) && (x > 255) && (y < 940) && (y > 850))
	{
		return 3;
	}
	else if ((x < 160) && (x > 30) && (y < 160) && (y > 30))
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

void GameMenu::HighlightRoundedRectangle(int posXCircleLeft, int posYCircleLeft, sf::RenderWindow &window)
{
	const sf::Vector2f rectLine(380, 0);
	const sf::Vector2f rectFill(380, 92.5);
	const sf::Vector2f circle1(posXCircleLeft, posYCircleLeft);
	const sf::Vector2f circle2(posXCircleLeft + 380, posYCircleLeft);
	const sf::Vector2f Fill(posXCircleLeft + 45, posYCircleLeft - 2.5);
	const sf::Vector2f line2(posXCircleLeft + 45, posYCircleLeft + 92.5);

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::White);
	circle.setOutlineThickness(5);
	circle.setRadius(45);

	sf::RectangleShape rectangleLine;
	rectangleLine.setSize(rectLine);
	rectangleLine.setOutlineThickness(2.5);

	sf::RectangleShape rectangleFill;
	rectangleFill.setSize(rectFill);
	rectangleFill.setFillColor(sf::Color::White);

	circle.setPosition(circle1);
	window.draw(circle);

	circle.setPosition(circle2);
	window.draw(circle);

	rectangleFill.setPosition(Fill);
	window.draw(rectangleFill);

	rectangleLine.setPosition(Fill);
	window.draw(rectangleLine);

	rectangleLine.setPosition(line2);
	window.draw(rectangleLine);
}

void GameMenu::displayGameRules(sf::RenderWindow &window, sf::Text rules, sf::Font font)
{
	const sf::Vector2f text(60, 200);
	sf::Text gameRules(
		"The aim of the game is to find the \n\nYELLOW Victory Tile! As you traverse \n\nthrough using your arrow keys, beware of \n\nTrap Tiles. Some will take you back to the \n\nstart, while others will delay your progress. \n\nWatch out because they are hard to see!\n\nBlack tiles are walls which you cannot go \n\nthrough.\n\nGood luck and happy running!",
		font, 40);
	gameRules.setPosition(text);
	window.clear();
	window.draw(rules);
	drawBackArrow(90, 90, window);
	window.draw(gameRules);
	window.display();
}

void GameMenu::drawBackArrow(int posXTriTop, int posYTriTop, sf::RenderWindow &window)
{
	sf::ConvexShape backArrow;
	const sf::Vector2f pos0(posXTriTop, posYTriTop);
	const sf::Vector2f pos1(posXTriTop + 50, posYTriTop - 20);
	const sf::Vector2f pos2(posXTriTop + 50, posYTriTop + 20);
	const sf::Vector2f posLine(posXTriTop + 50, posYTriTop - 30);
	const sf::Vector2f linesize(0, 70);

	backArrow.setPointCount(3);
	backArrow.setPoint(0, pos0);
	backArrow.setPoint(1, pos1);
	backArrow.setPoint(2, pos2);
	backArrow.setOutlineThickness(5);
	backArrow.setFillColor(sf::Color::Transparent);

	sf::RectangleShape line;
	line.setPosition(posLine);
	line.setSize(linesize);
	line.setOutlineThickness(5);
	line.setOutlineColor(sf::Color::Black);

	window.draw(backArrow);
	window.draw(line);
}

void GameMenu::launchGame(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "MazeRunner", sf::Style::Close | sf::Style::Resize);

	sf::Font font;
	font.loadFromFile("Comfortaa-Bold.ttf");

	sf::Text gameName("MazeRunner", font, 150);
	gameName.setStyle(sf::Text::Bold);
	gameName.setPosition(1, 70);

	sf::Text startGame("Start Game", font, 70);
	startGame.setStyle(sf::Text::Bold);
	startGame.setPosition(280, 450);

	sf::Text Rules("Game Rules", font, 70);
	Rules.setStyle(sf::Text::Bold);
	Rules.setPosition(280, 650);

	sf::Text Rules1("Game Rules", font, 70);
	Rules1.setStyle(sf::Text::Bold);
	Rules1.setPosition(280, 50);

	sf::Text Exit("Exit", font, 70);
	Exit.setStyle(sf::Text::Bold);
	Exit.setPosition(406, 850);

	int i = 0;//for distiguishing between what part of the menu you are in. 0 for main menu, 1 for rules and everything else basically

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(gameName);

		drawRoundedRectangle(253, 450, window);
		window.draw(startGame);
		drawRoundedRectangle(257, 650, window);
		window.draw(Rules);
		drawRoundedRectangle(255, 850, window);
		window.draw(Exit);
		window.display();


		while (window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseMoved:
				if (i == 0)
				{
					if (checkMousePosMenu(event) == 1)
					{
						HighlightRoundedRectangle(253, 450, window);
						startGame.setFillColor(sf::Color::Black);
						window.draw(startGame);
						window.display();
					}
					else if (checkMousePosMenu(event) == 2)
					{
						HighlightRoundedRectangle(257, 650, window);
						Rules.setFillColor(sf::Color::Black);
						window.draw(Rules);
						window.display();
					}
					else if (checkMousePosMenu(event) == 3)
					{
						HighlightRoundedRectangle(255, 850, window);
						Exit.setFillColor(sf::Color::Black);
						window.draw(Exit);
						window.display();
					}
					else
					{
						startGame.setFillColor(sf::Color::White);
						Rules.setFillColor(sf::Color::White);
						Exit.setFillColor(sf::Color::White);

						window.clear();

						window.draw(gameName);

						drawRoundedRectangle(253, 450, window);
						window.draw(startGame);
						drawRoundedRectangle(257, 650, window);
						window.draw(Rules);
						drawRoundedRectangle(255, 850, window);
						window.draw(Exit);
						window.display();
					}
				};
				break;

			case sf::Event::MouseButtonPressed:
				if (checkMousePosClick(event) == 1)
				{
					DisplayInstance gameInstance(window);
					gameInstance.render();
				}
				else if (checkMousePosClick(event) == 2)
				{
					displayGameRules(window, Rules1, font);
					i = 1;
				}
				else if (checkMousePosClick(event) == 3)
				{
					window.close();
				}
				else if (checkMousePosClick(event) == 4)
				{
					i = 0;
				};
				break;

			default:
				if (i == 0)
				{
					startGame.setFillColor(sf::Color::White);
					Rules.setFillColor(sf::Color::White);
					Exit.setFillColor(sf::Color::White);

					window.clear();

					window.draw(gameName);

					drawRoundedRectangle(253, 450, window);
					window.draw(startGame);
					drawRoundedRectangle(257, 650, window);
					window.draw(Rules);
					drawRoundedRectangle(255, 850, window);
					window.draw(Exit);
					window.display();

				}
				break;
			}
		}
	}
}

