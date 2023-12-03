#pragma once
#include <SFML/Graphics.hpp>
#include "include/constants.h"
#include "Enemy.h"

class Bullet
{
private:
	sf::Texture texture;
	sf::Vector2f velocity;

	float speed = MOV_SPEED * 3.0f;

	sf::FloatRect boundingRectangle;

public:

	sf::Sprite sprite;

public:

	void Initialize(sf::Texture& texture,sf::Sprite& player,sf::RenderWindow& window);
	void Load();
	int Update(float& deltaTime, Enemy& skeleton);
	void Draw(sf::RenderWindow& window);

};

