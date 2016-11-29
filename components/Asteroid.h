#pragma once
#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceship.h"

class Asteroid
{

public:
	Transform  transform;
	Collider   collider;
	Rigidbody  rigidbody;


	Asteroid();
	

	void update(float deltatime, class GameState &gs);
	void draw(const mat3 &camera);
};