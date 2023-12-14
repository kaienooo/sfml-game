#include "Enemy.h"
#include <iostream>

Enemy::Enemy() :
    health(100), width(64),height(64)
{
}

void Enemy::ChangeHealth(int hp) 
{
    health += hp;
    healthText.setString("Skeleton health is " + std::to_string(health));
}

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

    if (font.loadFromFile("assets/fonts/Arial.ttf"))
    {
        std::cout << "Arial.ttf loaded successfully" << std::endl;
        healthText.setFont(font);
        healthText.setString("Skeleton health is " + std::to_string(health));
    }
    else
    {
        std::cout << "Arial.ttf loading unsuccessul" << std::endl;
    }
}

void Enemy::Update()
{
    if (health > 0)
    {
        boundingRectangle.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition());    
    }
}

void Enemy::Draw(sf::RenderWindow& window)
{
    if (health > 0)
    { 
        window.draw(boundingRectangle);
        window.draw(sprite);
        window.draw(healthText);
    }
}

