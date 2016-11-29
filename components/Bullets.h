#pragma once
#include "transform.h"
#include "collider.h"
#include "Ridgedbody.h"
#include "Asteroid.h"
class Bullet
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;
	Asteroid	asteroid;

	float timer;
	bool isAlive;

	Bullet();

	void update(float deltatime, class GameState &gs);
	void draw(const mat3 &camera);
};