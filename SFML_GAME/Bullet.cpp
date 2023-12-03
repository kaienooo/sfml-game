#include "Bullet.h"
#include <iostream>
#include "include/constants.h"

void Bullet::Initialize(sf::Texture& texture, sf::Sprite& player, sf::RenderWindow& window)
{
    sf::Vector2f mousePos = (sf::Vector2f)(sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(0, 38));

    sf::FloatRect playerRect = player.getGlobalBounds();
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.1f, 0.1f));
    sprite.setPosition(playerRect.getPosition() + (playerRect.getSize() / 2.0f));

    sf::Vector2f target = mousePos - sprite.getPosition();
    sprite.setPosition(sprite.getPosition() - sprite.getGlobalBounds().getSize() / 2.0f);
    velocity = target * (float)(STEP_SIZE / sqrt(pow(target.x, 2) + pow(target.y, 2)));
}

void Bullet::Load()
{
}

void Bullet::Update()
{
    sprite.setPosition(sprite.getPosition() + velocity);
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
