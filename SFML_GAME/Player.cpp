#include "Player.h"
#include "include/constants.h"
#include <iostream>

void Player::Initialize()
{
    moveCycle[0] = 0;
    moveCycle[1] = 0;

}

void Player::Load()
{
    if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
    {
        std::cout << "Player sprite loaded succesfully";
        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(3, 3));
    }
    else
    {
        std::cout << "Player texture failed to load" << std::endl;
    }
}

void Player::Update()
{
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position = position + sf::Vector2f(0, -STEP_SIZE);
        if (moveCycle[1] != 0) {
            moveCycle[1] = 0;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position = position + sf::Vector2f(0, STEP_SIZE);
        if (moveCycle[1] != 2) {
            moveCycle[1] = 2;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position = position + sf::Vector2f(-STEP_SIZE, 0);
        if (moveCycle[1] != 1) {
            moveCycle[1] = 1;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position = position + sf::Vector2f(STEP_SIZE, 0);
        if (moveCycle[1] != 3) {
            moveCycle[1] = 3;
        }
    }

    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(moveCycle[0] * 64, moveCycle[1] * 64, 64, 64));

    moveCycle[0] = (moveCycle[0] + 1) % 9;
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
