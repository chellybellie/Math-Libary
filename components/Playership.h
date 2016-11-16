#pragma once

#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceshipcontroller.h"
#include "Spaceship.h"
#include "SpaceshipRenderer.h"
#include "Bullets.h"

class Playership
{
	

public:

	
	Transform			 transform;
	Collider			 collider;
	Rigidbody			 rigidbody;
	SpaceshipController  ctrl;
	Spaceshiplocomotion  loco;
	SpaceshipRenderer    drawship;

	const static int BULLET_COUNT = 25;
	Bullet bullets[BULLET_COUNT];

	float bullerTimer = 0;

	int health = 100;
	Playership();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
	void drawHealth();
};