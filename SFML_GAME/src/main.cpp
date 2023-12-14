#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "FrameRate.h"
#include "Map.h"
#include "MapLoader.h"

#include <iostream>

int main()
{
    //----------------------------INIT------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window", sf::Style::Default, settings);
    window.setFramerateLimit(240);

    Map map;
    FrameRate frameRate;
    Player player;
    Enemy enemy;
    BulletManager bulletManager;

    MapLoader mapLoader;
    mapLoader.Load("assets/maps/level1.aha66");
    
    map.Initialize();
    frameRate.Initialize();
    player.Initialize();
    enemy.Initialize();
    bulletManager.Initialize();

    //----------------------------INIT------------------------------------

    //----------------------------LOAD------------------------------------

    map.Load();
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

        map.Update(deltaTime);
        frameRate.Update(deltaTime);
        player.Update(deltaTime,enemy);
        enemy.Update();
        bulletManager.Update(deltaTime,player.sprite,mousepos,enemy);

        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        //if (clockCycle % 30 == 0)
        //{
            window.clear(sf::Color::Black);
            map.Draw(window);
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