#include "Menu.h"
#include <iostream>
#include "Global.h"
#include "include/constants.h"

void Menu::Initialize()
{
	buttons.reserve(10);

}

void Menu::Load()
{
    if (font.loadFromFile("assets/fonts/Arial.ttf"))
    {
        std::cout << "Arial.ttf loaded successfully" << std::endl;

        mainText.setFont(font);
        mainText.setString("Szkielety");
        mainText.setScale(4, 4);
        mainText.setPosition(sf::Vector2f(700, 200));
    }
    else
    {
        std::cout << "Arial.ttf loading unsuccessul" << std::endl;
    }

    buttons.push_back(Button("Graj", sf::Vector2f(100, 50), sf::Vector2f(910, 500), font));
    buttons.push_back(Button("Sklep", sf::Vector2f(100, 50), sf::Vector2f(910, 570), font));
    buttons.push_back(Button("Exit", sf::Vector2f(100, 50), sf::Vector2f(910, 640), font));


}

void Menu::Update(sf::Vector2i mousePos)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (int i = 0; i < buttons.size(); i++)
        {
            if (buttons[i].shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
            {
                switch (i)
                {
                case 0:
                    global::gameState = PLAYING;
                    std::cout << "Kliknieto przycisk!" << std::endl;
                    break;
                case 1:
                    global::gameState = SHOP;
                    break;
                case 2:
                    global::gameState = EXIT;
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void Menu::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < buttons.size(); i++)
    {
        buttons[i].Draw(window);
    }
    window.draw(mainText);
}
