#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "FrameRate.h"
#include "Map.h"

#include <iostream>

int main()
{
    //----------------------------INIT------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "My window", sf::Style::Default, settings);
    window.setFramerateLimit(240);

    std::vector<Map> maps;
    maps.reserve(10);

    maps.push_back(Map());
    maps.push_back(Map());

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

    maps[0].Load("assets/maps/Level1_1.aha66");
    maps[1].Load("assets/maps/Level1_2.aha66");

    frameRate.Load();
    enemy.Load();
    player.Load();
    bulletManager.Load();
    //mapLoader.Save("level1.aha66");

    //----------------------------LOAD------------------------------------

    sf::Clock clock;
    sf::Uint8 clockCycle = 0;

    while (window.isOpen())
    {
        std::vector<sf::CircleShape> kropki;
        kropki.reserve(100);



        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds()/1000.0f;
        //----------------------------UPDATE----------------------------------------

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2i mousepos = sf::Mouse::getPosition(window);

        maps[0].Update(deltaTime);
        maps[1].Update(deltaTime);

        frameRate.Update(deltaTime);
        player.Update(deltaTime,enemy);
        enemy.Update();
        bulletManager.Update(deltaTime,player.sprite,mousepos,enemy);

        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        //if (clockCycle % 30 == 0)
        //{
            window.clear(sf::Color::Black);
            maps[0].Draw(window);
            maps[1].Draw(window);

            enemy.Draw(window);
            enemy.Draw(window);
            bulletManager.Draw(window);
            player.Draw(window);
            frameRate.Draw(window);


            window.display();
        //}

        
        
        clockCycle++;
        //----------------------------DRAW----------------------------------------
    }

    return 0;
}