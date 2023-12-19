#include "Button.h"


Button::Button(std::string string, sf::Vector2f size, sf::Vector2f position, sf::Font& font)
{
	shape.setSize(size);
	shape.setPosition(position);
	
	text.setString(string);
	text.setFont(font);
	text.setPosition(position);
	text.setFillColor(sf::Color::Black);
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
}
