#include "Asteroid.h"
#include "SHARDS.h"
#include "gamestate.h"



/////////////ASTEROID CORE///////////
Asteroid::Asteroid()
{
	isAlive = true;

	health = 100;

	vec2 hullVrts2[] = { { 0,1 },{ 0,5 },{ -2,-1 } }; // LEFT-CROWN

	vec2 hullVrts5[] = { { 0,1 },{ 2,-1 },{ 0,-4 } }; // right-bottom-TRI

	vec2 hullVrts6[] = { { 0,1 },{ -2,-1 },{ 2,-1 } }; // MID-TRI-COMMANDER-HALL-:P

	vec2 hullVrts7[] = { { 0,-1 },{ -2,-1 },{ 0,-4 } }; //lefT-bottom-TRI

	vec2 hullVrts8[] = { { 0,1 },{ 2,-1 },{ 0,5 } }; // RIGHT-CROWN


	Hull hull[5];

	hull[0] = Hull(hullVrts2, 3);	
	hull[1] = Hull(hullVrts5, 3);
	hull[2] = Hull(hullVrts6, 3);
	hull[3] = Hull(hullVrts7, 3);
	hull[4] = Hull(hullVrts8, 3);


	collider = Collider(hull, 5);

	transform.m_scale = { 40, 40 };
	rigidbody.mass = 999;

	
}

void Asteroid::update(float deltatime, GameState & gs)
{
	if (!isAlive) return;
	if (health < 0)
	{
		isAlive = false;
		for(int i = 0; i < 5; ++i)
		{
			gs.shards[i].collider = Collider(collider.hull[i].vertices, collider.hull[i].size);
			gs.shards[i].transform = transform;		
			gs.shards[i].rigidbody.addImpulde(rigidbody.randDir() * 10);
			gs.shards[i].isAlive = true;
		}
	}
	//rigidbody.integrate(transform, deltatime);
}

void Asteroid::draw(const mat3 & camera)
{
	if (!isAlive) return;
		transform.debugDraw(camera);
		rigidbody.debugDraw(camera, transform);
		collider.DebugDraw(camera, transform);//// hull drawer
}
