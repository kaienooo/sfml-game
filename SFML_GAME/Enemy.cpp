#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
}

void Enemy::Load()
{
    if (texture.loadFromFile("assets/enemy/textures/spritesheet.png"))
    {
        int xIndex = 0;
        int yIndex = 2;

        std::cout << "Enemy sprite loaded succesfully";
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        sprite.setScale(sf::Vector2f(3, 3));
        sprite.setPosition(sf::Vector2f(700, 500));

    }
    else
    {
        std::cout << "Enemy texture failed to load" << std::endl;
    }
}

void Enemy::Update()
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

