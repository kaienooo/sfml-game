#pragma once
#include <string>

struct MapData
{
	std::string tilesheet = "";
	std::string name = "";

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleX = 0;
	int scaleY = 0;

	int mapWidth = 0;

	int dataLength;
	int* data = nullptr;
};