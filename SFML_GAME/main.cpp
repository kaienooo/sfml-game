#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "FrameRate.h"

#include <iostream>
#include <sstream>

int main()
{
    //----------------------------INIT------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window", sf::Style::Default, settings);
    window.setFramerateLimit(240);

    FrameRate frameRate;
    Player player;
    Enemy enemy;
    BulletManager bulletManager;

    frameRate.Initialize();
    player.Initialize();
    enemy.Initialize();
    bulletManager.Initialize();

    //----------------------------INIT------------------------------------

    //----------------------------LOAD------------------------------------

    frameRate.Load();
    enemy.Load();
    player.Load();
    bulletManager.Load();

    //----------------------------LOAD------------------------------------

    sf::Clock clock;
    sf::Uint8 clockCycle = 0;

    while (window.isOpen())
    {

        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMicroseconds()/1000.0f;
        //----------------------------UPDATE----------------------------------------

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        frameRate.Update(deltaTime);
        player.Update(deltaTime,enemy);
        enemy.Update();
        bulletManager.Update(deltaTime,player.sprite, window,enemy);

        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        //if (clockCycle % 4 == 0)
        {
            window.clear(sf::Color::Black);

            enemy.Draw(window);
            bulletManager.Draw(window);
            player.Draw(window);
            frameRate.Draw(window);


            window.display();
        }

        
        
        clockCycle++;
        //----------------------------DRAW----------------------------------------
    }

    return 0;
}