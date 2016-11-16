#pragma once

#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceshipcontroller.h"
#include "Spaceship.h"
#include "SpaceshipRenderer.h"

class Playership
{
	

public:

	
	Transform			 transform;
	Collider			 collider;
	Rigidbody			 rigidbody;
	SpaceshipController  ctrl;
	Spaceshiplocomotion  loco;
	SpaceshipRenderer    drawship;

	int health = 100;
	Playership();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
	void drawHealth();
};