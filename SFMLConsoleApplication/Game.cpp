#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(WIDTH, HEIGHT), "title of the game?")
{
	srand(time(NULL));
	mWindow.setFramerateLimit(60);

	//image of ship, size and starting position
	playerShip.texture.loadFromFile("images/ShipSprite.psd");
	playerShip.mRect.setTexture(&playerShip.texture);
	playerShip.mRect.setSize(sf::Vector2f(60.0f, 60.0f));
	playerShip.mRect.setPosition(sf::Vector2f(WIDTH * 0.5f, HEIGHT * 0.5f));


	//image of coin, size and starting position
	coin.texture.loadFromFile("images/CoinSprite.psd");
	coin.mRect.setTexture(&coin.texture);
	coin.mRect.setSize(sf::Vector2f(40.0f, 40.0f));
	coin.mRect.setPosition(sf::Vector2f(rand() % WIDTH, -1000.0));

	//image of asteroid, size and starting position
	this->loadtexture.loadFromFile("images/AsteroidSprite.psd");


	
}

Game::~Game()
{
	for (int i = 0; i < asteroidArray.size(); i++)
	{
		delete this->asteroidArray[i];
	}
}

//skapar ny asteroid på ett slumpmässigt x och y värde
void Game::createAsteroid()
{
	int newPosX = 0;
	int newPosY = 0;

	newPosX = rand() % WIDTH;
	newPosY -= rand() % HEIGHT;
	Asteroid* newAsteroid;
	newAsteroid = new Asteroid;
	newAsteroid->mRect.setTexture(&loadtexture);
	newAsteroid->mRect.setSize(sf::Vector2f(65.0f, 65.0f));
	newAsteroid->mRect.setPosition(sf::Vector2f(newPosX, newPosY));
	asteroidArray.push_back(newAsteroid);
}

//hanterar kollision med asteroider och mynt
void Game::collisions()
{
	for (int i = 0; i < asteroidArray.size(); i++) {
		if (asteroidArray[i]->mRect.getGlobalBounds().intersects(playerShip.mRect.getGlobalBounds())) {
			mWindow.close();
		}
}
	if (coin.mRect.getGlobalBounds().intersects(playerShip.mRect.getGlobalBounds())) {
		coin.mRect.setPosition(sf::Vector2f(rand() % WIDTH, -1000));
	}
}

//run håller i game loopen och i den med hjälp utav deltatime så uppdateras movement, kollar kollisioner, sfml events och ritar ut i skärmen
void Game::run()
{
	//hanterar tiden
	sf::Clock frameClock;
	float deltaTime;
	float timer = 0;
	while (mWindow.isOpen()){

		//ger tiden sedan klockans senaste omstart
		sf::Time elapsedTime = frameClock.getElapsedTime();
		//startar om klockan och lagrar tiden i deltaTime
		float deltaTime = frameClock.restart().asSeconds();

		// anordnar hur stort mellanrum det ska gå mellan nästa "asteroidspawn"
		timer += deltaTime;

		if (timer >= 3) {
			createAsteroid();

			timer = 0;
		}

		processEvents();
		update(deltaTime);
		Draw();

	}
}


//fönsterhantering, ifall du stänger ner, slutar loopen.
void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}


// uppdaterar skeppet
void Game::update(float deltaTime)
{


	playerShip.updateShip(deltaTime);
	if (coin.mRect.getPosition().y > HEIGHT) {
		mWindow.close();
	}
	// uppdaterar myntet
	coin.updateCoin(deltaTime);

	//uppdaterar asteroiderna, när den når slutet av fönstret så ska den få en slumpmässig ny x position över fönstret 
	for (int i = 0; i < asteroidArray.size(); i++) {
		asteroidArray[i]->updateAsteroid(deltaTime);
		if (HEIGHT < asteroidArray[i]->getPosition().y) {
			asteroidArray[i]->mRect.setPosition(sf::Vector2f(rand() % WIDTH,-100));
		}
	}
	//uppdaterar kollisioner
	collisions();

}

void Game::Draw()
{
	mWindow.clear();

	mWindow.draw(playerShip.mRect);
	mWindow.draw(coin.mRect);
	for (int i = 0; i < asteroidArray.size(); i++) {
		mWindow.draw(asteroidArray[i]->mRect);
	}

	mWindow.display();
}


