#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Global.h"
#include "BulletManager.h"
#include "Player.h"

class Shop
{
public:
	std::vector<Button> buttons;

	sf::Font font;
	sf::Text mainText;
	sf::Text moneyText;

	sf::Text statText;

	double lastBought = 0;

	void Initialize();
	void Load();
	void Update(double& deltaTime,sf::Vector2i mousePos, Player& player, BulletManager& bManager);
	void Draw(sf::RenderWindow& window);
};

