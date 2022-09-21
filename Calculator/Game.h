#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include "Button.h"

enum class Status { def, plus, minus, multi, div, perc};

class Game
{
private:
	std::string GameName = "Calculator";
private:
	sf::RenderWindow* window = nullptr;
	sf::Image icon;
	sf::Font* font = new sf::Font;

	sf::Clock clock;
private:
	sf::Cursor pointingcursor;
	sf::Cursor handcursor;
public:
	bool close = false;
	Game();
	void start();
private:
	void calc();
	std::vector<Button*>* buttons = new std::vector<Button*>;
	Status status = Status::def;

	int temp_, temp_2;
private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& a, const unsigned version)
	{
		a& temp_& temp_2;
	}
};

