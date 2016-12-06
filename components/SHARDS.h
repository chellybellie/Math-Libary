#pragma once

#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceship.h"



class Shard
{

public:
	Transform  transform;
	Collider   collider;
	Rigidbody  rigidbody;
	


	Shard();

	bool isAlive;
	int health;
	
	void update(float deltatime, class GameState &gs);
	void draw(const mat3 &camera);
};

