#pragma once
#include "Enemy.h"
#include "include/constants.h"
#include "BulletManager.h"

class Player
{
private:

	

	sf::Texture texture;
	sf::Uint8 moveCycle[2];
	sf::RectangleShape boundingRectangle;

	bool moving = 0;

	

	double animationDelta = 0;

	float width = 64;
	float height = 64;

	sf::Font font;
	sf::Text scoreText;
	sf::Text moneyText;
	int score = 0;
	

public:
	sf::Sprite sprite;
	int money = 0;
	float speed = MOV_SPEED;

public:

	void Initialize();
	void Load();
	void Update(double& deltaTime, Enemy& skeleton, BulletManager& bManager);
	void Draw(sf::RenderWindow& window);

};

