#include "Game.h"
#include <iostream>

Game::Game()
{
	if (!pointingcursor.loadFromSystem(sf::Cursor::Arrow))
		close = true;
	if (!handcursor.loadFromSystem(sf::Cursor::Hand))
		close = true;
	if (!font->loadFromFile("res/notalot35.ttf"))
		close = true;
	if (!icon.loadFromFile("res/icon.png"))
		close = true;
}

void Game::start()
{
	while (!close)
		calc();
}

/*
0 - 0
...
9 - 9
10 - .
11 - =
12 - +
13 - -
14 - *
15 - /
16 - %
17 - +/-
18 - AC
*/

void Game::calc()
{
	window = new sf::RenderWindow(sf::VideoMode(300, 550), GameName, sf::Style::Close);
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);

	sf::Event evnt;
	clock.restart().asSeconds();

	sf::Vector2f positions[19] = {
		sf::Vector2f(78,476), // 0
		sf::Vector2f(4,402),  // 1
		sf::Vector2f(78,402), // 2
		sf::Vector2f(152,402),// 3
		sf::Vector2f(4,328),  // 4
		sf::Vector2f(78,328), // 5
		sf::Vector2f(152,328),// 6
		sf::Vector2f(4,254),  // 7
		sf::Vector2f(78,254), // 8
		sf::Vector2f(152,254), // 9
		sf::Vector2f(152,476),
		sf::Vector2f(226,476),
		sf::Vector2f(226,402),
		sf::Vector2f(226,328),
		sf::Vector2f(226,254),
		sf::Vector2f(226,180),
		sf::Vector2f(152,180),
		sf::Vector2f(78,180),
		sf::Vector2f(4,180)
	};

	for (int i = 0; i < 19; i++)
	{
		Button* btn = new Button(positions[i], i);
		buttons->push_back(btn);
	}

	int cntcrs = 0;

	while (window->isOpen())
	{
		while (window->pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				close = true;
				window->close();
				delete window;
				return;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					close = true;
					window->close();
					delete window;
					return;
				}
				break;
			}
		}

		for (auto i : *buttons)
		{
			int a = i->update(window, cntcrs);
			if (a >= 0)
				std::cout << a << std::endl;
			switch (a)
			{
			case 1:
				break;
			case 2:
				break;
			default:
				break;
			}
		}


		if (cntcrs > 0)
			window->setMouseCursor(handcursor);
		else
			window->setMouseCursor(pointingcursor);
		cntcrs = 0;

		window->clear();
		for (auto i : *buttons)
			i->draw(window);
		window->display();
	}

	for (auto i = buttons->begin(); i != buttons->end();)
	{
		Button* e = *i;
		i = buttons->erase(i);
		delete e;
	}
	buttons->clear();
	delete buttons;

	close = true;
}
