#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "include/gamestates.h"


#define FPS 60
#define UPS 120

#define STEP_SIZE 0.5f

int render();
int updateGame();

int main()
{
    //----------------------------INIT------------------------------------

    std::vector<sf::Sprite> bullets;
    bullets.reserve(30);
    std::vector<sf::Vector2f> bulletVelocity;
    bulletVelocity.reserve(30);


    sf::Vector2f playerPosition = sf::Vector2f(0, 0);

    sf::Uint8 playerMoveCycle[2] = { 0,0 };
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window", sf::Style::Default, settings);


    //sf::RectangleShape button1(sf::Vector2f(100.0f, 100.0f));
    //button1.setFillColor(sf::Color::Yellow);
    //button1.setPosition(sf::Vector2f(800.0f / 2 - button1.getSize().x / 2, 600.0f / 2 - button1.getSize().y / 2));

    //sf::CircleShape octagon(50.0f, 4);
    //octagon.setFillColor(sf::Color::White);
    //octagon.setPosition(sf::Vector2f(200, 200));


    //sf::RectangleShape button2(sf::Vector2f(100.0f, 40.0f));
    //button2.setFillColor(sf::Color::Yellow);
    //button2.setPosition(sf::Vector2f(400.0f / 2 - button2.getSize().x / 2, 200.0f / 2 - button2.getSize().y / 2));

    //----------------------------INIT------------------------------------

    //----------------------------LOAD------------------------------------

    sf::Texture bulletTexture;

    if (bulletTexture.loadFromFile("assets/player/textures/bullet.png"))
    {
        std::cout << "Bullet texture loaded succesfully" << std::endl;
    }
    else
    {
        std::cout << "Bullet texture failed to load" << std::endl;
    }

    sf::Texture enemyTexture;
    sf::Sprite enemySprite;


    if (enemyTexture.loadFromFile("assets/enemy/textures/spritesheet.png"))
    {
        int xIndex = 0;
        int yIndex = 2;

        std::cout << "Enemy sprite loaded succesfully";
        enemySprite.setTexture(enemyTexture);
        enemySprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        enemySprite.setScale(sf::Vector2f(3, 3));
        enemySprite.setPosition(sf::Vector2f(700, 500));

    }
    else
    {
        std::cout << "Enemy texture failed to load" << std::endl;
    }

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
    {
        std::cout << "Player sprite loaded succesfully";
        playerSprite.setTexture(playerTexture);
        playerSprite.setScale(sf::Vector2f(3, 3));
    }
    else
    {
        std::cout << "Player texture failed to load" << std::endl;
    }



    //----------------------------LOAD------------------------------------



    while (window.isOpen())
    {

        //----------------------------UPDATE----------------------------------------

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            /*if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::W:
                        playerMoveCycle[1] = 0;
                        break;
                    case sf::Keyboard::A:
                        playerMoveCycle[1] = 1;
                        break;
                    case sf::Keyboard::S:
                        playerMoveCycle[1] = 2;
                        break;
                    case sf::Keyboard::D:
                        playerMoveCycle[1] = 3;
                        break;
                    default:
                        break;
                }
            }
            */
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Sprite bullet;
            sf::Vector2f mousePos = (sf::Vector2f)(sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(0,38));
            sf::FloatRect playerRect = playerSprite.getGlobalBounds();

            bullet.setTexture(bulletTexture);
            bullet.scale(sf::Vector2f(0.1f, 0.1f));
            bullet.setPosition(playerRect.getPosition() + (playerRect.getSize() / 2.0f));

            sf::FloatRect bulletRect = bullet.getGlobalBounds();

            sf::Vector2f target = mousePos - bullet.getPosition();

            bullet.setPosition(bullet.getPosition() - bulletRect.getSize() / 2.0f);
            sf::Vector2f velocity = target * (float)(STEP_SIZE / sqrt(pow(target.x, 2) + pow(target.y, 2)));

            bulletVelocity.push_back(velocity);
            bullets.push_back(bullet);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            playerPosition = playerPosition + sf::Vector2f(0, -STEP_SIZE);
            if (playerMoveCycle[1] != 0) {
                playerMoveCycle[1] = 0;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            playerPosition = playerPosition + sf::Vector2f(0, STEP_SIZE);
            if (playerMoveCycle[1] != 2) {
                playerMoveCycle[1] = 2;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playerPosition = playerPosition + sf::Vector2f(-STEP_SIZE, 0);
            if (playerMoveCycle[1] != 1) {
                playerMoveCycle[1] = 1;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playerPosition = playerPosition + sf::Vector2f(STEP_SIZE, 0);
            if (playerMoveCycle[1] != 3) {
                playerMoveCycle[1] = 3;
            }
        }
        for (size_t i = 0; i < bullets.size(); i++)
        {
            float x = bullets[i].getPosition().x;
            float y = bullets[i].getPosition().y;

            if (x < -100 or y < -100 or x > 1920 or y > 1080) {
                bullets.erase(bullets.begin() + i);
                bulletVelocity.erase(bulletVelocity.begin() + i);
            }
            else
            {
                bullets[i].setPosition(bullets[i].getPosition() + bulletVelocity[i]);
            }
        }
        //playerPosition = sf::Vector2f(playerPosition.x - (playerMoveCycle[1] == 1) + (playerMoveCycle[1] == 3), playerPosition.y - (playerMoveCycle[1] == 0) + (playerMoveCycle[1] == 2));



        playerSprite.setPosition(playerPosition);
        playerSprite.setTextureRect(sf::IntRect(playerMoveCycle[0] * 64, playerMoveCycle[1] * 64, 64, 64));

        playerMoveCycle[0] = (playerMoveCycle[0] + 1) % 9;
        //playerMoveCycle[1] = (playerMoveCycle[1] + playerMoveCycle[0] / 8) % 4;

        //button1.setFillColor(sf::Color((button1.getFillColor().toInteger() + 100) ));
        //button1.setSize(sf::Vector2f((int)(button1.getSize().x+10.0f)%100,(int)(button1.getSize().y+10.0f)%100));
        //button1.setPosition(sf::Vector2f(800.0f / 2 - button1.getSize().x / 2, 600.0f / 2 - button1.getSize().y / 2));

        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        window.clear(sf::Color::Black);

        //window.draw(button1);
        //window.draw(octagon);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.draw(playerSprite);
        window.draw(enemySprite);

        window.display();

        //for (size_t i = 0; i < 80000000; i++) {
        //   i = i + 1 - 1;
        //}

        //----------------------------DRAW----------------------------------------

    }

    return 0;
}