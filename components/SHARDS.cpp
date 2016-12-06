#include "SHARDS.h"
#include <iostream>

Shard::Shard()
{	
	health = 10;
	isAlive = false;
	
}

void Shard::update(float deltatime, GameState & gs)
{
	rigidbody.integrate(transform, deltatime);
}

void Shard::draw(const mat3 & camera) 
{
	transform.debugDraw(camera);
	rigidbody.debugDraw(camera, transform);
	collider.DebugDraw(camera, transform);
}






