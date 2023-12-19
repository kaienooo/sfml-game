#include "Shop.h"
#include <iostream>
#include "Global.h"

void Shop::Initialize()
{
    buttons.reserve(10);
}

void Shop::Load()
{
    if (font.loadFromFile("assets/fonts/Arial.ttf"))
    {
        std::cout << "Arial.ttf loaded successfully" << std::endl;

        mainText.setFont(font);
        moneyText.setFont(font);
        statText.setFont(font);
        mainText.setString("Sklep $$$");
        mainText.setScale(4, 4);
        mainText.setPosition(sf::Vector2f(700, 100));
        moneyText.setPosition(sf::Vector2f(1000, 400));
        statText.setPosition(sf::Vector2f(1000, 740));
    }
    else
    {
        std::cout << "Arial.ttf loading unsuccessul" << std::endl;
    }

    buttons.push_back(Button("Menu", sf::Vector2f(100, 50), sf::Vector2f(600, 500), font));

    buttons.push_back(Button("+1 dmg 100g", sf::Vector2f(300, 50), sf::Vector2f(1000, 500), font));
    buttons.push_back(Button("-2% cd 100g", sf::Vector2f(300, 50), sf::Vector2f(1000, 570), font));
    buttons.push_back(Button("3% ms 100g", sf::Vector2f(300, 50), sf::Vector2f(1000, 640), font));
}

void Shop::Update(double& deltaTime,sf::Vector2i mousePos,Player& player, BulletManager& bManager)
{

    moneyText.setString("Zloto: " + std::to_string(player.money));

    statText.setString("dmg: " + std::to_string(global::damage)
        + "\ncd: " + std::to_string(bManager.cooldown)
        + "ms\nms: " + std::to_string(player.speed));
    lastBought += deltaTime;
    if (lastBought > 50)
    {
        lastBought = 0;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            for (int i = 0; i < buttons.size(); i++)
            {
                if (buttons[i].shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                {
                    switch (i)
                    {
                    case 0:
                        global::gameState = MENU;
                        break;
                    case 1:
                        if (player.money >= 100)
                        {
                            global::damage += 1;
                            player.money -= 100;
                        }
                        break;
                    case 2:
                        if (player.money >= 100)
                        {
                            bManager.cooldown *= 0.98;
                            player.money -= 100;
                        }
                        break;
                    case 3:
                        if (player.money >= 100)
                        {
                            player.speed *= 1.03f;
                            player.money -= 100;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
        {
            std::string kod;
            std::cin >> kod;

            if (kod[0] == 'm')
            {
                std::string value = "";
                int i = 1;
                while (i < kod.length())
                {
                    value += kod[i];
                    i++;
                }
                player.money += std::stoi(value);
            }
        }
    }

    
}

void Shop::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < buttons.size(); i++)
    {
        buttons[i].Draw(window);
    }
    window.draw(mainText);
    window.draw(moneyText);
    window.draw(statText);
}
