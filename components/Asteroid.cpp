#include "Asteroid.h"

Asteroid::Asteroid()
{
	vec2 hullVrts1[] = { { -1,0 },{ 0,2 },{ 1,0 },{0,-1 } };
	

	Hull hull[1];
	hull[0] = Hull(hullVrts1, 4);

	collider = Collider(hull, 1);

	
	transform.m_scale		= { 1.f, 1.f };
	rigidbody.drag			= 0.0f;
	rigidbody.angularDrag	= 0.0f;
	rigidbody.mass			= 10;
	rigidbody.torque		= 0.0f;

}

void Asteroid::update(float deltatime, GameState & gs)
{
	rigidbody.integrate(transform, deltatime);
}

void Asteroid::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
