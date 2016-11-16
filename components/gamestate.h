#pragma once

#include "Playership.h"
#include "camera.h"
#include "Asteroid.h"
#include "Bullets.h"

class GameState
{


public:

	Playership  player;
	camera		Camera;
	Asteroid	asteroid[5];
	void play();
	void update(float deltatime);
	void draw();

};

