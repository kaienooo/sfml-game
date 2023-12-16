#include "Map.h"
#include <iostream>

Map::Map() :
    totalTiles(0), totalTilesX(0), totalTilesY(0), tiles(nullptr), mapSprites(nullptr)
{
}

Map::~Map() 
{
    delete[] tiles;
    delete[] mapSprites;
}

void Map::Initialize()
{
}

void Map::Load(std::string path)
{
    mapLoader.Load(path, md);

    mapSprites = new sf::Sprite[md.dataLength];

    if (tileSheetTexture.loadFromFile(md.tilesheet))
    {

        totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];


        for (int y = 0; y < totalTilesY; y++)
        {
            for (int x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;

                tiles[i].position = sf::Vector2f(x * md.tileWidth, y * md.tileHeight);
                tiles[i].id = i;
            }
        }
    }
    else
    {
        std::cout << "Prison tileset failed to load" << std::endl;
    }

    for (int y = 0; y < md.dataLength/md.mapWidth; y++)
    {
        for (int x = 0; x < md.mapWidth; x++)
        {
            int i = x + y * md.mapWidth;
            int index = md.data[i];

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(sf::Vector2i(tiles[index].position) , sf::Vector2i(md.tileWidth,md.tileHeight)));
            mapSprites[i].setScale(md.scaleX, md.scaleY);
            mapSprites[i].setPosition(sf::Vector2f(
                x * md.tileWidth  * md.scaleX,
                y * md.tileHeight * md.scaleY));
        }
    }
}

void Map::Update(double& deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < md.dataLength; i++)
    {
        window.draw(mapSprites[i]);
    }
}
