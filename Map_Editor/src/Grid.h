#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
public:
	sf::RectangleShape* hLine;
	sf::RectangleShape* vLine;

	sf::Vector2i cellSize;

	sf::Vector2f position;

	int lineThickness;
	int scale;

	sf::Vector2i totalCells;

public:

	Grid(const sf::Vector2f& position, const sf::Vector2i& totalcells, const sf::Vector2i& cellsize, const int linethickness, const int scale);
	~Grid();

	void Initialize();
	void Load();
	void Update(double& deltaTime);
	void Draw(sf::RenderWindow& window);
};

