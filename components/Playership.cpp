#include "Playership.h"
#include "gamestate.h"
#include <iostream>



Playership::Playership()
{
	vec2 hullVrts1[] = { { 0,8.5 },{ -1,1 },{ 1,1 } }; // NOSE-TRI

	vec2 hullVrts2[] = { { -1,1 },{ -3,2 },{ -2,-1 } }; // LEFT-CROWN

	vec2 hullVrts3[] = { { -2,-1 },{ -4.5,-1 },{ -3,2 } }; // LEFT-UPPER-WING

	vec2 hullVrts4[] = { { -2,-1 },{ -2,-6 },{ -4.5,-1 } }; // LEFT-LOWER-WING

	vec2 hullVrts5[] = { { -1,1 },{ -2,-1 },{ 0,-0.5 } }; // LEFT-MID-TRI

	vec2 hullVrts6[] = { { -1,1 },{ 1,1 },{ 0,-.5 } }; // MID-TRI-COMMANDER-HALL-:P

	vec2 hullVrts7[] = { { 1,1 },{ 2,-1 },{ 0,-.5 } }; // RIGHT-MID-TRI

	vec2 hullVrts8[] = { { 1,1 },{ 2,-1 },{ 3,2 } }; // RIGHT-CROWN

	vec2 hullVrts9[] = { { 2,-1 },{ 3,2 },{ 4.5,-1 } }; // RIGHT-UPPER-WING

	vec2 hullVrts10[] = { { 2,-1 },{ 2,-6 },{ 4.5,-1 } }; // RIGHT-LOWER-WING
	
	Hull hull[10];
	         
	hull[0] = Hull(hullVrts1,  3);
	hull[1] = Hull(hullVrts2,  3);
	hull[2] = Hull(hullVrts3,  3);
	hull[3] = Hull(hullVrts4,  3);
	hull[4] = Hull(hullVrts5,  3);
	hull[5] = Hull(hullVrts6,  3);
	hull[6] = Hull(hullVrts7,  3);
	hull[7] = Hull(hullVrts8,  3);
	hull[8] = Hull(hullVrts9,  3);
	hull[9] = Hull(hullVrts10, 3);

	
	health = 100;
	collider = Collider(hull, 10);

	transform.m_scale = { 20, 20 };

}

void Playership::drawHealth()
{
// TODO//
}
void Playership::update(float deltaTime, GameState & gs)
{
	ctrl.update(loco);
	loco.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);

	// shooting delay
	bullerTimer -= deltaTime;

	if (sfw::getKey('1') && bullerTimer <= 0.0f )
	{
		int bulletID = -1;

		// find a bullet to use
		for (int i = 0; i < BULLET_COUNT; ++i)
		{
			if (!bullets[i].isAlive)
			{
				bulletID = i;
				break;
			}
		}

		if (bulletID != -1)
		{
			Bullet& myBullet = bullets[bulletID];

			// reset the bullet
			myBullet.isAlive = true;
			myBullet.timer = 5.f;
			myBullet.transform.m_position = transform.m_position;
			myBullet.transform.m_facing = transform.m_facing;

			myBullet.rigidbody.velocity = vec2{ 0,0 };

			myBullet.rigidbody.addImpulde(transform.getUp() * 10000.f);

			bullerTimer = .3f;
		}
	}

	for (int i = 0; i < BULLET_COUNT; ++i)
		bullets[i].update(deltaTime, gs);

}

void Playership::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	drawship.draw(camera, transform);
	//collider.DebugDraw(camera, transform); // SHOWS THE HULL[] ( COLLIER OUTLINE) 
	rigidbody.debugDraw(camera, transform);

	for (int i = 0; i < BULLET_COUNT; ++i)
		bullets[i].draw(camera);
}


