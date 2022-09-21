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
	switch (id)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	}
*/

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

	sf::Text tx;
	tx.setCharacterSize(100);
	tx.setFont(*font);
	tx.setFillColor(sf::Color::White);
	tx.setPosition(10,70);

	sf::Text tx2;
	tx2.setCharacterSize(55);
	tx2.setFont(*font);
	tx2.setFillColor(sf::Color(40,40,40));
	tx2.setPosition(10, 60);

	float display = 0;
	float temp = 0;

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
		Button* btn = new Button(positions[i], i, *font);
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
			{
				std::cout << a << std::endl;
				switch (a)
				{
				case 0:
					display *= 10;
					break;
				case 1:
					display *= 10;
					display += 1;
					break;
				case 2:
					display *= 10;
					display += 2;
					break;
				case 3:
					display *= 10;
					display += 3;
					break;
				case 4:
					display *= 10;
					display += 4;
					break;
				case 5:
					display *= 10;
					display += 5;
					break;
				case 6:
					display *= 10;
					display += 6;
					break;
				case 7:
					display *= 10;
					display += 7;
					break;
				case 8:
					display *= 10;
					display += 8;
					break;
				case 9:
					display *= 10;
					display += 9;
					break;
				case 10:
					break;
				case 11:
					switch (status)
					{
					case Status::plus:
						display = temp + display;
						break;
					case Status::minus:
						display = temp - display;
						break;
					case Status::multi:
						display = temp * display;
						break;
					case Status::div:
						display = temp / display;
						break;
					case Status::perc:
						
						break;
					default:
						break;
					}
					status = Status::def;
					break;
				case 12:
					status = Status::plus;
					tx2.setString(std::to_string(display) + " +");
					temp = display;
					display = 0;
					break;
				case 13:
					status = Status::minus;
					tx2.setString(std::to_string(display) + " -");
					temp = display;
					display = 0;
					break;
				case 14:
					status = Status::multi;
					tx2.setString(std::to_string(display) + " *");
					temp = display;
					display = 0;
					break;
				case 15:
					status = Status::div;
					tx2.setString(std::to_string(display) + " /");
					temp = display;
					display = 0;
					break;
				case 16:
					status = Status::perc;
					break;
				case 17:
					display = -display;
					break;
				case 18:
					status = Status::def;
					display = 0;
					break;
				default:
					break;
				}
			}
		}

		tx.setString(std::to_string(display));


		if (cntcrs > 0)
			window->setMouseCursor(handcursor);
		else
			window->setMouseCursor(pointingcursor);
		cntcrs = 0;

		window->clear();
		for (auto i : *buttons)
			i->draw(window);
		window->draw(tx);
		if (status != Status::def)
		window->draw(tx2);
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
