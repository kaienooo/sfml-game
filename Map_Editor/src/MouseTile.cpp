#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile()
{
}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load(const Grid& grid)
{
	tileSheet.loadFromFile("assets/tileset/tileset.png");
	tile.setTexture(tileSheet);
	tile.setScale(sf::Vector2f(grid.scale,grid.scale));
	
}

void MouseTile::Update(double& deltaTime, const sf::Vector2i& mousePos, const Grid& grid, MapExporter& mapexporter, sf::RenderWindow& window)
{

	time = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sf::Sprite textSprite;
		textSprite.setTexture(tileSheet);
		textSprite.setScale(window.getSize().x / tileSheet.getSize().x, window.getSize().y / tileSheet.getSize().y);

		while (1)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				sf::Vector2i mousepos = sf::Mouse::getPosition(window);

				sf::Vector2i cellsInTexture = sf::Vector2i(tileSheet.getSize().x / grid.cellSize.x,
					tileSheet.getSize().y / grid.cellSize.y);

				float sprScaleX = textSprite.getScale().x;
				float sprScaleY = textSprite.getScale().y;

				int x = mousepos.x / (grid.cellSize.x * (int)sprScaleX);
				int y = mousepos.y / (grid.cellSize.y * (int)sprScaleY);

				selectedTile = x + y * cellsInTexture.x;
				break;
			}
			window.clear(sf::Color::Black);
			window.draw(textSprite);
			window.display();
		}
		/*
		int tx = tileSheet.getSize().x / grid.cellSize.x;
		int ty = tileSheet.getSize().y / grid.cellSize.y;
		std::cin >> selectedTile;
		tile.setTextureRect(sf::IntRect(selectedTile % tx * grid.cellSize.x,
			selectedTile / ty * grid.cellSize.y,
			grid.cellSize.x, grid.cellSize.y));
		*/
	}
	else
	{

		int tx = tileSheet.getSize().x / grid.cellSize.x;
		int ty = tileSheet.getSize().y / grid.cellSize.y;

		tile.setTextureRect(sf::IntRect(
			(selectedTile % tx) * grid.cellSize.x,
			(selectedTile / tx) * grid.cellSize.y,
			grid.cellSize.x, grid.cellSize.y));

		int gridVarX = grid.cellSize.x * grid.scale;
		int gridVarY = grid.cellSize.y * grid.scale;

		int mouseVarX = mousePos.x - grid.position.x;
		int mouseVarY = mousePos.y - grid.position.y;

		int index = mouseVarX / gridVarX + mouseVarY / gridVarY * grid.totalCells.x;

		sf::Vector2f pos;

		if (mousePos.x < grid.position.x || mousePos.x > grid.position.x + grid.cellSize.x * grid.totalCells.x * grid.scale ||
			mousePos.y < grid.position.y || mousePos.y > grid.position.y + grid.cellSize.y * grid.totalCells.y * grid.scale)
		{
			pos = sf::Vector2f(mousePos);
		}
		else
		{
			pos = sf::Vector2f(mouseVarX / gridVarX * gridVarX + grid.position.x, mouseVarY / gridVarY * gridVarY + grid.position.y);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				mapexporter.Update(selectedTile, index);
			}
		}

		tile.setPosition(pos);
	}

}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(tile);
}
