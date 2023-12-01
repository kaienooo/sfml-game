#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/gamestates.h"

#define FPS 60
#define UPS 120

int render();
int updateGame();

int main()
{
    //----------------------------INIT------------------------------------


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window",sf::Style::Default,settings);


    sf::RectangleShape button1(sf::Vector2f(100.0f, 100.0f));
    button1.setFillColor(sf::Color::Yellow);
    button1.setPosition(sf::Vector2f(800.0f / 2 - button1.getSize().x / 2, 600.0f / 2 - button1.getSize().y / 2));

    sf::CircleShape octagon(50.0f, 4);
    octagon.setFillColor(sf::Color::White);
    octagon.setPosition(sf::Vector2f(200, 200));


    sf::RectangleShape button2(sf::Vector2f(100.0f, 40.0f));
    button2.setFillColor(sf::Color::Yellow);
    button2.setPosition(sf::Vector2f(400.0f / 2 - button2.getSize().x / 2, 200.0f / 2 - button2.getSize().y / 2));

    //----------------------------INIt------------------------------------



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
        ;
        button1.setFillColor(sf::Color((button1.getFillColor().toInteger() + 100) % 2147483648));
        //button1.setSize(sf::Vector2f((int)(button1.getSize().x+10.0f)%100,(int)(button1.getSize().y+10.0f)%100));
        //button1.setPosition(sf::Vector2f(800.0f / 2 - button1.getSize().x / 2, 600.0f / 2 - button1.getSize().y / 2));

        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        window.clear(sf::Color::Black);

        window.draw(button1);
        window.draw(octagon);

        window.display();

        //----------------------------DRAW----------------------------------------

    }

    return 0;
}