#pragma once

#include "Engine/GameEngine.h"

class Laser : public GameObject
{
public:
	//Creates our laser.
	Laser(sf::Vector2f pos);
	//Fnctions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Laser> LaserPtr;