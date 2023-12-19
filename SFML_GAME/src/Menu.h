#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class Menu
{
public:
	std::vector<Button> buttons;

	sf::Font font;
	sf::Text mainText;


	void Initialize();
	void Load();
	void Update(sf::Vector2i mousePos);
	void Draw(sf::RenderWindow& window);
};

