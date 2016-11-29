#pragma once

#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceshipcontroller.h"
#include "Spaceship.h"
#include "SpaceshipRenderer.h"
#include "Bullets.h"
#include "Ultimate wepon.h"

class Playership
{
	

public:

	
	Transform			 transform;
	Collider			 collider;
	Rigidbody			 rigidbody;
	SpaceshipController  ctrl;
	Spaceshiplocomotion  loco;
	SpaceshipRenderer    drawship;
	Ultimate			 ultimate;

	const static int BULLET_COUNT = 25;
	Bullet bullets[BULLET_COUNT];

	float bullerTimer = 0;
	float UltimateTimer = 0;

	int health = 100;
	Playership();

	void spawnBullet(const Transform &trans);
	void spawnUltimate(const Transform &trans);

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
	void drawHealth();
};