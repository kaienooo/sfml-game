#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class MapExporter
{
public:

	std::string tilesheet = "";
	std::string name = "";

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleX = 0;
	int scaleY = 0;

	int mapWidth = 0;
	int mapHeight = 0;
	int* cells = nullptr;

public:
	MapExporter(const sf::Vector2i& totalcells, const sf::Vector2i& cellsize, const int scale);
	~MapExporter();
	MapExporter();

	void Update(int selectedTile, int index);

	void Export(std::string name, int layer);
};

