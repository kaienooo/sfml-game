#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::Texture texture;
	sf::Vector2f velocity;
public:

	sf::Sprite sprite;

public:

	void Initialize(sf::Texture& texture,sf::Sprite& player,sf::RenderWindow& window);
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);

};

