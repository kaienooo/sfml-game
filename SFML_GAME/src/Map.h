#pragma once
#include "Tile.h"

class Map
{
private:

	sf::Texture tileSheetTexture;
	Tile* tiles;

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;

	int totalTiles;

	static const int mapSize = 6;
	int mapWidth;
	int mapHeight;

	int mapNumbers[mapSize] = {
		120, 121, 122,
		144, 145 ,146
	};

	sf::Sprite mapSprites[mapSize];

public:

	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(double& deltaTime);
	void Draw(sf::RenderWindow& window);
};

