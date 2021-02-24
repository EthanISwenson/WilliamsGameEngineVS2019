#include "MeteorSpawner.h"

// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 1000;

void MeteorSpawner::update(sf::Time& elapsed)
{
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	// If our timer has elapsed, reste it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		// SPawn the meteor off the right side of the screen.
		//We're assuming the meteor isn't more than 100 pixels wide.
		float meteorX = (float)(size.x + 100);

		//Spawn the meteor somwhere along the hieght of window, randomly.
		float meteorY = (float)(rand() % size.y);

		// Create a meteor and add it to the scene
		MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY));
		GAME.getCurrentScene().addGameObject(meteor);
	}
}