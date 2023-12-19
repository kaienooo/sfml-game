#include "Player.h"
#include "include/constants.h"
#include <iostream>
#include "Math.h"
#include "Global.h"

void Player::Initialize()
{
    moveCycle[0] = 0;
    moveCycle[1] = 0;

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(2);
    boundingRectangle.setOutlineColor(sf::Color::Transparent);
    //asdasdasdasdasda
}

void Player::Load()
{
    if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
    {
        std::cout << "Player sprite loaded succesfully";
        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(2, 2));
        sprite.setPosition(1000, 500);
        boundingRectangle.setSize(sf::Vector2f(width * sprite.getScale().x - 60, height * sprite.getScale().y - 30));
    }
    else
    {
        std::cout << "Player texture failed to load" << std::endl;
    }

    if (font.loadFromFile("assets/fonts/Arial.ttf"))
    {
        std::cout << "Arial.ttf loaded successfully" << std::endl;
        scoreText.setFont(font);
        scoreText.setString("Wynik: " + std::to_string(score));
        moneyText.setFont(font);
        moneyText.setString("Zloto: " + std::to_string(money));

        scoreText.setPosition(sf::Vector2f(0, 1020));
        moneyText.setPosition(sf::Vector2f(0, 1050));
    }
    else
    {
        std::cout << "Arial.ttf loading unsuccessul" << std::endl;
    }
}

void Player::Update(double& deltaTime,Enemy& skeleton,BulletManager& bManager)
{
    sf::Vector2f position = sprite.getPosition();

    moving = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position = position + sf::Vector2f(0, -speed) * (float)deltaTime;
        if (moveCycle[1] != 0) {
            moveCycle[1] = 0;
        }
        moving = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position = position + sf::Vector2f(0, speed) * (float)deltaTime;
        if (moveCycle[1] != 2) {                           
            moveCycle[1] = 2;
        } 
        moving = 1;
    }                                                      
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))       
    {                                                      
        position = position + sf::Vector2f(-speed, 0) * (float)deltaTime;
        if (moveCycle[1] != 1) {                           
            moveCycle[1] = 1;
        }  
        moving = 1;
    }                                                      
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))       
    {                                                      
        position = position + sf::Vector2f(speed, 0) * (float)deltaTime;
        if (moveCycle[1] != 3) {
            moveCycle[1] = 3;
        }
        moving = 1;
    }


    sprite.setPosition(position);
    boundingRectangle.setPosition(position + sf::Vector2f(30,25));
    sprite.setTextureRect(sf::IntRect(moveCycle[0] * (int)width, moveCycle[1] * (int)height, (int)width, (int)height));

    animationDelta += deltaTime;

    if (animationDelta > 100 && moving)
    {
        moveCycle[0] = (moveCycle[0] + 1) % 9;
        animationDelta = 0;
    }

    

    if (skeleton.collect_gold)
    {
        money += 20;
        score += 20;
        skeleton.collect_gold = false;

        scoreText.setString("Wynik: " + std::to_string(score));
        moneyText.setString("Zloto: " + std::to_string(money));
    }

    if (skeleton.moving)
    {
        if (Math::CheckRectCollision(boundingRectangle.getGlobalBounds(), skeleton.boundingRectangle.getGlobalBounds()))
        {
            score = 0;

            sprite.setPosition(1000, 500);

            skeleton.speed = MOV_SPEED * 1.03f;
            skeleton.maxHealth = 100;
            skeleton.Initialize();

            bManager.bullets.clear();
            
            global::gameState = MENU;
        }
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
    window.draw(moneyText);
    window.draw(scoreText);
}
