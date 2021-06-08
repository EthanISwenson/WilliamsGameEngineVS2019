#pragma once

#include "Engine/GameEngine.h"
#include "Explosion.h"
#include "GameScene.h"

class Meteor : public GameObject
{
public:
	// Creates our Meteor.
	Meteor(sf::Vector2f pos);

	// Functions overridden from GameObject :
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObjects);
	int direction;
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Meteor>MeteorPtr;