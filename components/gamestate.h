#pragma once

#include "Playership.h"
#include "camera.h"
#include "Asteroid.h"
#include "Bullets.h"
#include "spaceship Child.h"


class GameState
{


public:

	Playership  player;
	camera		Camera;
	Asteroid	asteroid;
	ShipChild	shipchild[5];

	void play();
	void update(float deltatime);
	void draw();

};

