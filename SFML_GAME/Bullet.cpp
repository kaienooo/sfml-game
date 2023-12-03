#include "Bullet.h"
#include <iostream>
#include "include/constants.h"
#include "Math.h"

void Bullet::Initialize(sf::Texture& texture, sf::Sprite& player, sf::RenderWindow& window)
{
    sf::Vector2f mousePos = (sf::Vector2f)(sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(0, 38));

    sf::FloatRect playerRect = player.getGlobalBounds();
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.1f, 0.1f));
    sprite.setPosition(playerRect.getPosition() + (playerRect.getSize() / 2.0f));

    sf::Vector2f target = mousePos - sprite.getPosition();
    sprite.setPosition(sprite.getPosition() - sprite.getGlobalBounds().getSize() / 2.0f);
    velocity = target * (float)(speed / sqrt(pow(target.x, 2) + pow(target.y, 2)));

    boundingRectangle = sf::FloatRect(sprite.getPosition(), sprite.getGlobalBounds().getSize());
}

void Bullet::Load()
{
}

int Bullet::Update(float& deltaTime, Enemy& skeleton)
{
    sprite.setPosition(sprite.getPosition() + velocity * deltaTime);
    boundingRectangle.left = sprite.getPosition().x;
    boundingRectangle.top = sprite.getPosition().y;
    if (Math::CheckRectCollision(boundingRectangle, skeleton.boundingRectangle.getGlobalBounds()))
    {
        skeleton.health -= 5;
        return 1;
    }
    return 0;
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
