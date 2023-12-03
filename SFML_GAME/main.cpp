#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

int main()
{
    //----------------------------INIT------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window", sf::Style::Default, settings);

    Player player;
    Enemy enemy;
    BulletManager bulletManager;

    player.Initialize();
    enemy.Initialize();
    bulletManager.Initialize();

    //----------------------------INIT------------------------------------

    //----------------------------LOAD------------------------------------

    enemy.Load();
    player.Load();
    bulletManager.Load();

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
        }

        player.Update();
        enemy.Update();
        bulletManager.Update(player.sprite, window);

        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        window.clear(sf::Color::Black);

        enemy.Draw(window);
        bulletManager.Draw(window);
        player.Draw(window);
        

        window.display();

        //----------------------------DRAW----------------------------------------

    }

    return 0;
}