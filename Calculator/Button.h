#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Button
{
public:
	Button(sf::Vector2f position, int _id, sf::Font &font);
	int update(sf::RenderWindow* window, int &cntcrs);
	void draw(sf::RenderWindow* window, sf::Shader &shader);
private:
	sf::Sprite body;
	int id;
	int click = 0;
	bool hold = false;
	sf::Text tx;
};

