#pragma once

#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceship.h"
#include "Asteroid.h"


class Shard
{

public:
	Transform  transform;
	Collider   collider;
	Rigidbody  rigidbody;
	Asteroid   asteroid;


	Shard();


	void update(float deltatime, class GameState &gs);
	void draw(const mat3 &camera);
};