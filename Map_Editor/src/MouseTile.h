#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>
#include "MapExporter.h"

class MouseTile
{
private:

	sf::Texture tileSheet;
	sf::Sprite tile;

	double time = 0;

public:
	int selectedTile = 12;

public:

	MouseTile();
	~MouseTile();

	void Initialize();
	void Load(const Grid& grid);
	void Update(double& deltaTime, const sf::Vector2i& mousePos, const Grid& grid, MapExporter& mapexporter, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
};

