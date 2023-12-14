#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;
	float width;
	float height;

	sf::Font font;
	sf::Text healthText;
	
public:
	int health;
	sf::RectangleShape boundingRectangle;
	sf::Sprite sprite;

public:

	Enemy();
	void ChangeHealth(int hp);

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
};

