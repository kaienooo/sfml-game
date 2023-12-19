#include "Enemy.h"
#include <iostream>

Enemy::Enemy() :
    health(100), width(64),height(64)
{
    maxHealth = 100;
}

void Enemy::ChangeHealth(int hp) 
{
    health += hp;
    healthText.setString("    " + std::to_string(health));
}

void Enemy::Initialize()
{
    moveCycle[0] = 0;
    moveCycle[1] = 0;
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(2);
    boundingRectangle.setOutlineColor(sf::Color::Transparent);
    //asdasdasdasdaa
    sprite.setPosition(respawnPattern[currentResp]);
    health = maxHealth;
    healthText.setString("    " + std::to_string(health));
    
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
        sprite.setScale(sf::Vector2f(2, 2));
        boundingRectangle.setSize(sf::Vector2f(width * sprite.getScale().x - 60, height * sprite.getScale().y - 30));
    }
    else
    {
        std::cout << "Enemy texture failed to load" << std::endl;
    }

    if (font.loadFromFile("assets/fonts/Arial.ttf"))
    {
        std::cout << "Arial.ttf loaded successfully" << std::endl;
        healthText.setFont(font);
        healthText.setString("    " + std::to_string(health));
    }
    else
    {
        std::cout << "Arial.ttf loading unsuccessul" << std::endl;
    }
}

void Enemy::Update(double& deltaTime, sf::Vector2f playerPos)
{
    moving = 1;
    if (health > 0 && moving == 1)
    {
        animationDelta += deltaTime;

        if (animationDelta > 100 && moving)
        {
            moveCycle[0] = (moveCycle[0] + 1) % 9;
            animationDelta = 0;
        }


        sf::Vector2f target = playerPos - sprite.getPosition();
        velocity = target * (float)(speed / sqrt(pow(target.x, 2) + pow(target.y, 2)));

        if (abs(velocity.x / velocity.y) > 1)
        {
            if (velocity.x > 0)
                moveCycle[1] = 3;
            else
                moveCycle[1] = 1;
        }
        else if (abs(velocity.y / velocity.x) > 1)
        {
            if (velocity.y > 0)
                moveCycle[1] = 2;
            else
                moveCycle[1] = 0;
        }

        sprite.setTextureRect(sf::IntRect(moveCycle[0] * (int)width, moveCycle[1] * (int)height, (int)width, (int)height));
        sprite.setPosition(sprite.getPosition() + velocity * (float)deltaTime);
        boundingRectangle.setPosition(sprite.getPosition() + sf::Vector2f(30, 25));
        healthText.setPosition(sprite.getPosition());
    }
    else
    {
        collect_gold = true;
        currentResp = (currentResp + 1) % 10;
        maxHealth += 5;
        Initialize();
        speed *= 1.02f;
        healthText.setString("    " + std::to_string(health));
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

