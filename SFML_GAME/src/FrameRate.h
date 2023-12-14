#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	double timer;
	sf::Text text;
	sf::Font font;
public:
	FrameRate();

	void Initialize();
	void Load();
	void Update(double& deltaTime);
 	void Draw(sf::RenderWindow& window);
};

