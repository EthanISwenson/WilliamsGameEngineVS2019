#pragma once

#include "Engine/GameEngine.h"
#include "Meteor.h"

class MeteorSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

Typedef std::shared_ptr<MeteorSpawner>MeteorSpawnerPtr;