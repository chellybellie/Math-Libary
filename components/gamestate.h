#pragma once

#include "Playership.h"
#include "camera.h"
#include "Asteroid.h"
#include "Bullets.h"
#include "spaceship Child.h"
#include "SHARDS.h"


class GameState
{


public:

	Playership  player;
	camera		Camera;
	Asteroid	asteroid;
	ShipChild	shipchild[5];

	const static int SHARD_COUNT = 5;
	Shard		shards[SHARD_COUNT];

	void play();
	void update(float deltatime);
	void draw();

};

