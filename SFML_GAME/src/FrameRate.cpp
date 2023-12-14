#include "FrameRate.h"
#include <iostream>
#include <string>

FrameRate::FrameRate() :
	timer(0)
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (font.loadFromFile("assets/fonts/Arial.ttf"))
	{
		std::cout << "Arial.ttf loaded successfully" << std::endl;
		text.setFont(font);
	}
	else
	{
		std::cout << "Arial.ttf loading unsuccessul" << std::endl;
	}

}

void FrameRate::Update(double& deltaTime)
{
	if (timer > 100.0f) {
		text.setString("FPS: " + std::to_string((int)(1000 / deltaTime)));
		timer = 0;
	}
	timer += deltaTime;
	
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}
