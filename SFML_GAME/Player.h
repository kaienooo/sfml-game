#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture texture;
	sf::Uint8 moveCycle[2];

public:
	sf::Sprite sprite;

public:

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);

};

