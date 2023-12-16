#pragma once
#include "Tile.h"
#include "MapLoader.h"

class Map
{
private:

	sf::Texture tileSheetTexture;
	Tile* tiles;

	MapLoader mapLoader;
	MapData md;

	int totalTilesX;
	int totalTilesY;

	int totalTiles;

	sf::Sprite* mapSprites;

public:

	Map();
	~Map();
	void Initialize();
	void Load(std::string path);
	void Update(double& deltaTime);
	void Draw(sf::RenderWindow& window);
};

