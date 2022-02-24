#include "Ship.h"
#include "SFML/Graphics.hpp"

using namespace std;






void Ship::updateShip(float deltaTime)
{
	// movement up,down,left,right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		mRect.move(sf::Vector2f(0.0f, -10.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		mRect.move(sf::Vector2f(0.0f, 10.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		mRect.move(sf::Vector2f(-10.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		mRect.move(sf::Vector2f(10.0f, 0.0f));
	}

	//collision with wall
	if (mRect.getPosition().x > 768 - mRect.getSize().x) {
		mRect.setPosition(sf::Vector2f(768 - mRect.getSize().x, mRect.getPosition().y));
	}

	if (mRect.getPosition().x < 0 ) {
		mRect.setPosition(sf::Vector2f(0 , mRect.getPosition().y));
	}

	if (mRect.getPosition().y < 0) {
		mRect.setPosition(sf::Vector2f (mRect.getPosition().x, 0 ));
	}

	if (mRect.getPosition().y > 1024 - mRect.getSize().y) {
		mRect.setPosition(sf::Vector2f(mRect.getPosition().x, 1024 - mRect.getSize().y));
	}
}

