#include "Map.h"
#include <iostream>

Map::Map() :
    tileWidth(16), tileHeight(16), totalTiles(0), totalTilesX(0), totalTilesY(0), mapWidth(3), mapHeight(2), tiles(nullptr)
{
}

Map::~Map() 
{
}

void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("assets/world/prison/tileset.png"))
    {

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];


        for (int y = 0; y < totalTilesY; y++)
        {
            for (int x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;

                tiles[i].position = sf::Vector2f(x * tileWidth, y * tileHeight);
                tiles[i].id = i;
            }
        }
    }
    else
    {
        std::cout << "Prison tileset failed to load" << std::endl;
    }

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            int i = x + y * mapWidth;
            int index = mapNumbers[i];

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(sf::Vector2i(tiles[index].position) , sf::Vector2i(tileWidth,tileHeight)));
            mapSprites[i].setScale(5, 5);
            mapSprites[i].setPosition(sf::Vector2f(
                x * tileWidth * mapSprites[i].getScale().x,
                y * tileHeight * mapSprites[i].getScale().y));
        }
    }
}

void Map::Update(double& deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < mapSize; i++)
    {
        window.draw(mapSprites[i]);
    }
}
