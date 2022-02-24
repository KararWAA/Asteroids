#pragma once
#include "SFML/Graphics.hpp"
#include "Ship.h"
#include "Coin.h"
#include "Asteroid.h"
#include <vector>
#include <time.h>

#define WIDTH 768
#define HEIGHT 1024

class Game
{
public:
	Game();
	~Game();
	void run();



private:
	void processEvents();
	void update(float deltaTime);
	void Draw();
	void createAsteroid();
	void collisions();
	sf::RenderWindow mWindow;
	sf::Texture loadtexture;


	// Asteroid, coin, ship
	Ship playerShip;
	Coin coin;	
	std::vector<Asteroid*> asteroidArray;
	
	
};

