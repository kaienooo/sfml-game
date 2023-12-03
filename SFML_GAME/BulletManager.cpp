#include "BulletManager.h"
#include "Player.h"
#include "include/constants.h"
#include <iostream>

void BulletManager::Initialize()
{
	bullets.reserve(BULLET_RESERVE);
	textures.reserve(TEXTURE_RESERVE);
}

void BulletManager::Load()
{
    sf::Texture bulletTexture;

    if (bulletTexture.loadFromFile("assets/player/textures/bullet.png"))
    {
        std::cout << "Bullet texture 1 loaded succesfully" << std::endl;
    }
    else
    {
        std::cout << "Bullet texture failed to load" << std::endl;
    }

    textures.push_back(bulletTexture);
}

void BulletManager::Update(float& deltaTime,sf::Sprite& player,sf::RenderWindow& window,Enemy& skeleton)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (lastFired > cooldown)
        {
            Bullet bullet;
            bullet.Initialize(textures[0], player, window);

            bullets.push_back(bullet);
            lastFired = 0;
        }
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].Update(deltaTime, skeleton))
            bullets.erase(bullets.begin() + i);
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        float x = bullets[i].sprite.getPosition().x;
        float y = bullets[i].sprite.getPosition().y;

        if (x < -100 or y < -100 or x > 1920 or y > 1080) {
            bullets.erase(bullets.begin() + i);
        }
    }

    std::cout<<bullets.size()<<std::endl;
    lastFired += deltaTime;
}

void BulletManager::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }
}
