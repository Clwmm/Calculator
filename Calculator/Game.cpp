#include "Game.h"

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
10 - *
11 - /
12 - +
13 - -
14 - =
15 - ,
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

	for (int i = 0; i < 9; i++)
	{
		Button* btn = new Button(sf::Vector2f(35, 35+(i*40)), i);
		buttons.push_back(btn);
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

		for (auto i : buttons)
			i->update(window, cntcrs);


		if (cntcrs > 0)
			window->setMouseCursor(handcursor);
		else
			window->setMouseCursor(pointingcursor);
		cntcrs = 0;

		window->clear();
		for (auto i : buttons)
			i->draw(window);
		window->display();
	}

	close = true;
}
