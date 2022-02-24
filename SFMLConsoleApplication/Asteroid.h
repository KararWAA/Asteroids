#pragma once
#include "SFML/Graphics.hpp"

class Asteroid
{
public:

	sf::Vector2f getPosition();
	sf::RectangleShape mRect;
	sf::Texture texture;

	void updateAsteroid(float deltaTime);

private:


};

