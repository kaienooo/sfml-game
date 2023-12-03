#pragma once
#include "Enemy.h"
#include "include/constants.h"

class Player
{
private:
	sf::Texture texture;
	sf::Uint8 moveCycle[2];
	sf::RectangleShape boundingRectangle;

	bool moving = 0;

	float speed = MOV_SPEED;

	float animationDelta = 0;

	float width = 64;
	float height = 64;

public:
	sf::Sprite sprite;

public:

	void Initialize();
	void Load();
	void Update(float& deltaTime , Enemy& skeleton);
	void Draw(sf::RenderWindow& window);

};

