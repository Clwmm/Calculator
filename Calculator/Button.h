#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Button
{
public:
	Button(sf::Vector2f position, int _id);
	int update(sf::RenderWindow* window, int &cntcrs);
	void draw(sf::RenderWindow* window);
private:
	sf::Sprite body;
	int id;
	int click = 0;
};

