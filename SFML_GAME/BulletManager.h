#pragma once
#include "Bullet.h"


class BulletManager
{
private:
	std::vector<sf::Texture> textures;
	std::vector<Bullet> bullets;
public:
	void Initialize();
	void Load();
	void Update(sf::Sprite& player, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

};