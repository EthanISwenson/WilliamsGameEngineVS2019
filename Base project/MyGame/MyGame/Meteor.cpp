#include "Meteor.h"
#include <time.h>

const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/LaserShark.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);
	float rf = (float)rand() / (float)RAND_MAX;
	//direction = rf > 0.5 ? -1 : 1;
	if (rf > 0.5)
	{
		direction = -1;
	}
	else
	{
		direction = 1;
	}
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	float gameHeight = GAME.getRenderWindow().getSize().y;

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();

		makeDead();
	}
	else if (pos.y > 525 || pos.y < -10)
	{
		direction *= -1;
	}
	
	// straight approach
	//sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));

	// bouncing approach
	sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y - (SPEED * msElapsed) *direction));
	
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}
   	makeDead();

	sf::Vector2f pos = sprite_.getPosition();
	ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(pos.x, pos.y + (sprite_.getGlobalBounds().height / 2)));
	GAME.getCurrentScene().addGameObject(explosion);

	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	scene.increaseScore();
}
