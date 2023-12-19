#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Button
{
public:

	sf::RectangleShape shape;
	sf::Text text;

	Button(std::string string, sf::Vector2f size, sf::Vector2f position, sf::Font& font);
	void Draw(sf::RenderWindow& window);
};

