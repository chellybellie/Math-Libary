#include "Bullets.h"

Bullet::Bullet()
{
	timer = 0;

	vec2 hullverts[] = { {-.1f,0},{0,.2f},{.1f,0} };
	collider = Collider(hullverts, 3);
	transform.m_scale = vec2{ 40,40 };
	rigidbody.mass = 15;
}

void Bullet::update(float deltatime, GameState & gs)
{
	timer -= deltatime;
	isAlive = timer > 0;

	if (!isAlive)return;

	rigidbody.integrate(transform, deltatime);

}

void Bullet::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);

}
