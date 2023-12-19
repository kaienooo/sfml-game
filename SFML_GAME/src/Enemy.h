#pragma once
#include <SFML/Graphics.hpp>
#include "include/constants.h"

class Enemy
{
private:
	sf::Texture texture;
	float width;
	float height;

	

	
	sf::Vector2f velocity;

	sf::Uint8 moveCycle[2];
	double animationDelta = 0;

	sf::Font font;
	sf::Text healthText;

	sf::Vector2f respawnPattern[10] = { sf::Vector2f(0,0),
										sf::Vector2f(1020,0),
										sf::Vector2f(1200,1020),
										sf::Vector2f(1880,500),
										sf::Vector2f(0,500),
										sf::Vector2f(1020,800),
										sf::Vector2f(1880,0),
										sf::Vector2f(1880,1020),
										sf::Vector2f(1020,0),
										sf::Vector2f(900,1020) };
	int currentResp = 0;
	
public:
	int maxHealth = 100;
	float speed = MOV_SPEED * 1.03f;
	bool collect_gold = 0;
	bool moving = 0;
	int health;
	sf::RectangleShape boundingRectangle;
	sf::Sprite sprite;

public:

	Enemy();
	void ChangeHealth(int hp);

	void Initialize();
	void Load();
	void Update(double& deltaTime, sf::Vector2f playerPos);
	void Draw(sf::RenderWindow& window);
};

