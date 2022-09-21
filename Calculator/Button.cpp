#include "Button.h"

Button::Button(sf::Vector2f position, int _id)
{
	id = _id;
	body.setPosition(position);
	body.setTexture(*TextureManager::AcquireTexture("res/1.png"));
}

int Button::update(sf::RenderWindow* window, int &cntcrs)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::FloatRect boundingBox = body.getGlobalBounds();
	sf::Vector2f point = window->mapPixelToCoords(pixelPos);
	if (boundingBox.contains(point))
	{
		cntcrs++;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && click == 0)
		{
			body.setTexture(*TextureManager::AcquireTexture("res/1.png"));
			click++;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && click == 0)
		{
			body.setTexture(*TextureManager::AcquireTexture("res/2.png"));
			click++;
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !sf::Mouse::isButtonPressed(sf::Mouse::Right))
			click = 0;

	}
	else
		click = 0;
	return 0;
}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(body);
}
