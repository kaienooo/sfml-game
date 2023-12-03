#pragma once
#include "Bullet.h"


class BulletManager
{
private:
	std::vector<sf::Texture> textures;
	std::vector<Bullet> bullets;

	float cooldown = 0.0001f;
	float lastFired = 0;
public:
	void Initialize();
	void Load();
	void Update(float& deltaTime, sf::Sprite& player, sf::RenderWindow& window,Enemy& skeleton);
	void Draw(sf::RenderWindow& window);

};