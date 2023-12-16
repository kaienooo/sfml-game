#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"
#include "MapExporter.h"
#include <Vector>

int currentLayer = 0;

int main()
{
    //----------------------------INIT------------------------------------

    sf::Texture texture;

    texture.loadFromFile("assets/tileset/tileset.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "My window", sf::Style::None, settings);
    window.setFramerateLimit(240);

    Grid grid(sf::Vector2f(20, 20), sf::Vector2i(30, 17), sf::Vector2i(16, 16), 2, 3);
    MouseTile mouseTile;

    MapExporter mapExporter1(grid.totalCells, grid.cellSize, grid.scale);
    MapExporter mapExporter2(grid.totalCells, grid.cellSize, grid.scale);
 


    grid.Initialize();
    mouseTile.Initialize();

    int tx = texture.getSize().x / grid.cellSize.x;
    int ty = texture.getSize().y / grid.cellSize.y;

    //----------------------------INIT------------------------------------
    
    //----------------------------LOAD------------------------------------

    //mapLoader.Save("level1.aha66");
    grid.Load();
    mouseTile.Load(grid);

    //----------------------------LOAD------------------------------------

    sf::Clock clock;
    sf::Uint8 clockCycle = 0;

    while (window.isOpen())
    {
        
        

        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0f;
        //----------------------------UPDATE----------------------------------------

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                
                
                mapExporter1.Export("Level1_1.aha66",0);
                mapExporter2.Export("Level1_2.aha66",1);
                
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
            {
                currentLayer = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
            {
                currentLayer = 1;
            }
        }

        sf::Vector2i mousepos = sf::Mouse::getPosition(window);

        grid.Update(deltaTime);
        if (currentLayer == 0)
        {
            mouseTile.Update(deltaTime, mousepos, grid, mapExporter1, window);
        }
        else if(currentLayer == 1)
        {
            mouseTile.Update(deltaTime, mousepos, grid, mapExporter2, window);
        }
        


        //----------------------------UPDATE--------------------------------------


        //----------------------------DRAW----------------------------------------

        //if (clockCycle % 30 == 0)
        //{
        window.clear(sf::Color::Black);
        for (int y = 0; y < grid.totalCells.y; y++)
        {
            for (int x = 0; x < grid.totalCells.x; x++)
            {
                int i = x + y * grid.totalCells.x;


                sprite.setTextureRect(sf::IntRect(
                    (mapExporter1.cells[i] % tx) * grid.cellSize.x,
                    (mapExporter1.cells[i] / tx) * grid.cellSize.y,
                    grid.cellSize.x, grid.cellSize.y));


                sprite.setPosition(sf::Vector2f(x * grid.cellSize.x * grid.scale, y * grid.cellSize.y * grid.scale) + grid.position);
                sprite.setScale(grid.scale, grid.scale);
                window.draw(sprite);
            }
        }
        
        for (int y = 0; y < grid.totalCells.y; y++)
        {
            for (int x = 0; x < grid.totalCells.x; x++)
            {
                int i = x + y * grid.totalCells.x;


                sprite.setTextureRect(sf::IntRect(
                    (mapExporter2.cells[i] % tx) * grid.cellSize.x,
                    (mapExporter2.cells[i] / tx) * grid.cellSize.y,
                    grid.cellSize.x, grid.cellSize.y));


                sprite.setPosition(sf::Vector2f(x * grid.cellSize.x * grid.scale, y * grid.cellSize.y * grid.scale) + grid.position);
                sprite.setScale(grid.scale, grid.scale);
                window.draw(sprite);
            }
        }
        
        grid.Draw(window);
        mouseTile.Draw(window);
        window.display();
        //}

        clockCycle++;
        //----------------------------DRAW----------------------------------------
    }

    

    return 0;
}