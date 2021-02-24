#pragma once

#include "Engine/GameEngine.h"

class Meteor : public GameObject
{
public:
	// Creates our Meteor.
	Meteor(sf::Vector2f pos);

	// Functions overridden from GameObject :
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Meteor>MeteorPtr;