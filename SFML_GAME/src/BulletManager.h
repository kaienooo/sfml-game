#pragma once
#include "Bullet.h"


class BulletManager
{
private:
	std::vector<sf::Texture> textures;
	std::vector<Bullet> bullets;

	double cooldown = 100.0f;
	double lastFired = 0;
public:
	void Initialize();
	void Load();
	void Update(double& deltaTime, sf::Sprite& player, sf::Vector2i& mousepos,Enemy& skeleton);
	void Draw(sf::RenderWindow& window);

};