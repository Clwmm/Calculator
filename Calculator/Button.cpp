#include "Button.h"

Button::Button(sf::Vector2f position, int _id)
{
	id = _id;
	body.setPosition(position);
	if (id <= 10)
		body.setTexture(*TextureManager::AcquireTexture("res/1.png"));
	else if (id <= 15)
		body.setTexture(*TextureManager::AcquireTexture("res/3.png"));
	else
		body.setTexture(*TextureManager::AcquireTexture("res/5.png"));
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
}
