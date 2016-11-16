#include "Bullets.h"

Bullet::Bullet()
{
	timer = 0;

	vec2 hullverts[] = { {-.5f,0},{0,1.f},{.5f,0},{0,-1.f} };
	collider = Collider(hullverts, 4);
	transform.m_scale = vec2{ 30,30 };
	rigidbody.mass = 15;
}

void Bullet::update(float deltatime, GameState & gs)
{
	////UPDATE ME/////
	
	if (!isAlive) return;

	rigidbody.integrate(transform, deltatime);

	timer -= deltatime;
	isAlive = timer > 0;
}

void Bullet::draw(const mat3 & camera)
{
	if (!isAlive) return;
	
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform); /// HIDES RED LINE ON BULLETS///
}
