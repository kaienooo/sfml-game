#pragma once
#include "Bullet.h"


class BulletManager
{
private:
	std::vector<sf::Texture> textures;
	

	
	double lastFired = 0;
public:
	std::vector<Bullet> bullets;
	double cooldown = 100.0;

	void Initialize();
	void Load();
	void Update(double& deltaTime, sf::Sprite& player, sf::Vector2i& mousepos,Enemy& skeleton);
	void Draw(sf::RenderWindow& window);
};