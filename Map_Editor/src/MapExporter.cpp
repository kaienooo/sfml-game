#include "MapExporter.h"
#include <fstream>


MapExporter::MapExporter(const sf::Vector2i& totalcells, const sf::Vector2i& cellsize, const int scale) :
	mapWidth(totalcells.x),
	mapHeight(totalcells.y),
	tileWidth(cellsize.x),
	tileHeight(cellsize.y),
	scaleX(scale),
	scaleY(scale),
	tilesheet("assets/world/prison/tileset.png")

{
	cells = new int[mapWidth * mapHeight];
	for (int i = 0; i < mapHeight * mapWidth; i++)
	{
		cells[i] = 287;
	}
}

MapExporter::~MapExporter()
{
	delete[] cells;
}

MapExporter::MapExporter()
{
}

void MapExporter::Update(int selectedTile, int index)
{
	cells[index] = selectedTile;
}


void MapExporter::Export(std::string name,int layer)
{

	std::ofstream file(name);

	file << "[MAP]" << std::endl;
	file << "tilesheet=" << tilesheet << std::endl;
	file << "name=" << name << " " << layer << std::endl;
	file << "tile-width=" << tileWidth << std::endl;
	file << "tile-height=" << tileHeight << std::endl;
	file << "scale-x=" << scaleX << std::endl;
	file << "scale-y=" << scaleY << std::endl;
	file << "data-x=" << mapWidth << std::endl;
	file << "data-length=" <<  mapHeight * mapWidth << std::endl;
	file << "data=";

	for (int i = 0; i < mapHeight * mapWidth; i++)
	{
		file << cells[i] << ",";
	}

	file.close();
}
