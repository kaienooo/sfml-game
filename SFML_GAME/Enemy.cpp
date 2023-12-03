#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(2);
    boundingRectangle.setOutlineColor(sf::Color::Red);
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
        boundingRectangle.setSize(sf::Vector2f(width * sprite.getScale().x, height * sprite.getScale().y));
        sprite.setPosition(sf::Vector2f(700, 500));

    }
    else
    {
        std::cout << "Enemy texture failed to load" << std::endl;
    }
}

void Enemy::Update()
{
    boundingRectangle.setPosition(sprite.getPosition());
    if (health <= 0)
    {
        sprite.setScale(0, 0);
        boundingRectangle.setScale(0, 0);
    }
        
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(boundingRectangle);
    window.draw(sprite);
}

