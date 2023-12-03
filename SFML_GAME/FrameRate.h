#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text text;
	sf::Font font;

	float timer = 0;
public:
	void Initialize();
	void Load();
	void Update(float& deltaTime);
 	void Draw(sf::RenderWindow& window);
};

