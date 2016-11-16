#pragma once

#include "Playership.h"
#include "camera.h"
#include "Asteroid.h"

class GameState
{


public:

	Playership  player;
	camera		Camera;
	Asteroid	asteroid[2];
	void play();
	void update(float deltatime);
	void draw();

};

/*
	INIT
	- Called once at application start.
	- used for loading resources like textures
	PLAY
	- called one we transition into an application state.
	-used to reset the logic of the state ( ie. new game).
	EXIT
	- called one
	TERM 
	- called one at application shutdown
	-used to free resources (like textures)
	STEP





*/