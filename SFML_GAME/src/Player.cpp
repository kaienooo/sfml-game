#include "Player.h"
#include "include/constants.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{
    moveCycle[0] = 0;
    moveCycle[1] = 0;

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(2);
    boundingRectangle.setOutlineColor(sf::Color::White);
}

void Player::Load()
{
    if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
    {
        std::cout << "Player sprite loaded succesfully";
        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(2, 2));
        boundingRectangle.setSize(sf::Vector2f(width * sprite.getScale().x, height * sprite.getScale().y));
    }
    else
    {
        std::cout << "Player texture failed to load" << std::endl;
    }
}

void Player::Update(double& deltaTime,Enemy& skeleton)
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
    boundingRectangle.setPosition(position);
    sprite.setTextureRect(sf::IntRect(moveCycle[0] * (int)width, moveCycle[1] * (int)height, (int)width, (int)height));

    animationDelta += deltaTime;

    if (animationDelta > 100 && moving)
    {
        moveCycle[0] = (moveCycle[0] + 1) % 9;
        animationDelta = 0;
    }

    if (Math::CheckRectCollision(sprite.getGlobalBounds(),skeleton.sprite.getGlobalBounds()))
        std::cout<<"COLISION!"<<std::endl;

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}
