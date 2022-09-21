#include "Button.h"

Button::Button(sf::Vector2f position, int _id, sf::Font &font)
{
	id = _id;
	body.setPosition(position);
	if (id <= 10)
		body.setTexture(*TextureManager::AcquireTexture("res/1.png"));
	else if (id <= 15)
		body.setTexture(*TextureManager::AcquireTexture("res/3.png"));
	else
		body.setTexture(*TextureManager::AcquireTexture("res/5.png"));

	tx.setCharacterSize(64);
	tx.setFont(font);
	tx.setFillColor(sf::Color::White);
	tx.setPosition(sf::Vector2f(body.getPosition().x + 25, body.getPosition().y - 15));
	tx.setString(std::to_string(id));

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
		tx.setString(",");
		tx.setPosition(sf::Vector2f(body.getPosition().x + 30, body.getPosition().y - 15));
		break;
	case 11:
		tx.setPosition(sf::Vector2f(body.getPosition().x + 27, body.getPosition().y - 15));
		tx.setString("=");
		break;
	case 12:
		tx.setString("+");
		tx.setPosition(sf::Vector2f(body.getPosition().x + 27, body.getPosition().y - 15));
		break;
	case 13:
		tx.setString("-");
		tx.setPosition(sf::Vector2f(body.getPosition().x + 27, body.getPosition().y - 15));
		break;
	case 14:
		tx.setString("*");
		tx.setPosition(sf::Vector2f(body.getPosition().x + 22, body.getPosition().y - 18));
		break;
	case 15:
		tx.setString("/");
		break;
	case 16:
		tx.setString("%");
		break;
	case 17:
		tx.setString("+/-");
		tx.setPosition(sf::Vector2f(body.getPosition().x + 5, body.getPosition().y - 15));
		break;
	case 18:
		tx.setString("AC");
		tx.setPosition(sf::Vector2f(body.getPosition().x + +15, body.getPosition().y - 15));
		break;
	}
}

int Button::update(sf::RenderWindow* window, int &cntcrs)
{
	int return_ = -1;
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f point = window->mapPixelToCoords(pixelPos);
	float distX = point.x - body.getPosition().x-35;
	float distY = point.y - body.getPosition().y-35;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= 35)
	{
		cntcrs++;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			if (id <= 10)
				body.setTexture(*TextureManager::AcquireTexture("res/2.png"));
			else if (id <= 15)
				body.setTexture(*TextureManager::AcquireTexture("res/4.png"));
			else
				body.setTexture(*TextureManager::AcquireTexture("res/6.png"));
			if (hold == false)
				return_ = id;
			hold = true;
		}
		else
		{
			hold = false;
			if (id <= 10)
				body.setTexture(*TextureManager::AcquireTexture("res/1.png"));
			else if (id <= 15)
				body.setTexture(*TextureManager::AcquireTexture("res/3.png"));
			else
				body.setTexture(*TextureManager::AcquireTexture("res/5.png"));
		}
	}
	return return_;
}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(body);
	window->draw(tx);
}
