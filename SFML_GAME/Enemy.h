#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;
	float width = 64;
	float height = 64;

	

public:
	int health = 1000;
	sf::RectangleShape boundingRectangle;
	sf::Sprite sprite;

public:

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
};

