#include "Grid.h"

Grid::Grid(const sf::Vector2f& position, const sf::Vector2i& totalcells, const sf::Vector2i& cellsize, const int linethickness, const int scale) :
	position(position),
	totalCells(totalcells),
	cellSize(cellsize),
	lineThickness(linethickness),
	scale(scale)
{
	hLine = new sf::RectangleShape[totalCells.y + 1];
	vLine = new sf::RectangleShape[totalCells.x + 1];
}

Grid::~Grid()
{
	delete[] hLine;
	delete[] vLine;
}

void Grid::Initialize()
{
	//30x17 map

	int horizontalLineLength = totalCells.x * cellSize.x * scale + lineThickness;
	int verticalLineLength = totalCells.y * cellSize.y * scale;

	for (size_t i = 0; i < totalCells.y + 1; i++)
	{
		
		hLine[i].setSize(sf::Vector2f(horizontalLineLength, lineThickness));
		hLine[i].setPosition(position + sf::Vector2f(0, i * cellSize.y * scale));
		hLine[i].setFillColor(sf::Color(255, 255, 255, 128));
	}

	for (size_t i = 0; i < totalCells.x + 1; i++)
	{
		vLine[i].setSize(sf::Vector2f(lineThickness, verticalLineLength));
		vLine[i].setPosition(position + sf::Vector2f(i * cellSize.x * scale,0));
		vLine[i].setFillColor(sf::Color(255, 255, 255, 128));
	
	}

	/*
	hLine.setSize(sf::Vector2f(horizontalLineLength,lineThickness));
	hLine.setPosition(position);

	vLine.setSize(sf::Vector2f(lineThickness, verticalLineLength));
	vLine.setPosition(position);
	*/
}

void Grid::Load()
{
}

void Grid::Update(double& deltaTime)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	//window.draw(hLine);
	//window.draw(vLine);
	for (size_t i = 0; i < totalCells.y + 1; i++)
	{
		window.draw(hLine[i]);
	}

	for (size_t i = 0; i < totalCells.x + 1; i++)
	{
		window.draw(vLine[i]);
	}
}
