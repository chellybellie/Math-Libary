#include "SHARDS.h"


Shard::Shard()
{	
	vec2 hullVrts1[] = { { -1,0 },{ 0,2 },{ 1,0 },{0,-1 } };
	

	Hull hull[1];
	hull[0] = Hull(hullVrts1, 4);

	collider = Collider(hull, 1);

	transform.m_scale = { 1.f, 1.f };
}

void Shard::update(float deltatime, GameState & gs)
{
	if (asteroid.health <= 0)
	{
		transform.m_position = transform.getGlobalPosition();
		transform.m_scale += asteroid.transform.m_scale;
		transform.m_facing += asteroid.transform.m_facing;
		transform.m_parent = nullptr;
	}
	rigidbody.integrate(transform, deltatime);
}

void Shard::draw(const mat3 & camera) 
{
	transform.debugDraw(camera);
	rigidbody.debugDraw(camera, transform);
	collider.DebugDraw(camera, transform);
}
