#include "Asteroid.h"



sf::Vector2f Asteroid::getPosition()
{
	return mRect.getPosition();
}

void Asteroid::updateAsteroid(float deltaTime)
{
	mRect.move(sf::Vector2f(0.0f, 3.0f));

	

}



