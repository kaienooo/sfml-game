#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "FrameRate.h"
#include "Map.h"
#include "Menu.h"
#include "Shop.h"
#include "Global.h"

#include <iostream>

int main()
{
    //----------------------------INIT------------------------------------
   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(240);

    std::vector<Map> maps;
    maps.reserve(10);

    maps.push_back(Map());
    maps.push_back(Map());

    FrameRate frameRate;
    Player player;
    Enemy enemy;
    BulletManager bulletManager;
    Menu menu;
    Shop shop;

    menu.Initialize();
    shop.Initialize();
    frameRate.Initialize();
    player.Initialize();
    enemy.Initialize();
    bulletManager.Initialize();

    //----------------------------INIT------------------------------------

    //----------------------------LOAD------------------------------------

    maps[0].Load("assets/maps/Level1_1.aha66");
    maps[1].Load("assets/maps/Level1_2.aha66");

    menu.Load();
    shop.Load();
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

        if (global::gameState == EXIT)
        {
            window.close();
            exit(0);
        }

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

        // MENU

        if (global::gameState == MENU)
        {
            menu.Update(mousepos);
            //----------------------------DRAW----------------------------------------
            window.clear(sf::Color::Black);

            menu.Draw(window);

            window.display();
            //----------------------------DRAW----------------------------------------
        }

        if (global::gameState == SHOP)
        {
            shop.Update(deltaTime,mousepos,player,bulletManager);

            window.clear(sf::Color::Black);

            shop.Draw(window);

            window.display();
        }


        // MENU

        //-------------------------------------PLAYING----------------------------------------

        if (global::gameState == PLAYING)
        {
            maps[0].Update(deltaTime);
            maps[1].Update(deltaTime);

            frameRate.Update(deltaTime);
            player.Update(deltaTime, enemy,bulletManager);
            enemy.Update(deltaTime, player.sprite.getPosition());
            bulletManager.Update(deltaTime, player.sprite, mousepos, enemy);


            //----------------------------DRAW----------------------------------------
            window.clear(sf::Color::Black);
            maps[0].Draw(window);
            maps[1].Draw(window);

            enemy.Draw(window);
            bulletManager.Draw(window);
            player.Draw(window);
            frameRate.Draw(window);


            window.display();
            //----------------------------DRAW----------------------------------------
        }

        //-------------------------------------PLAYING----------------------------------------

  
    }

    return 0;
}