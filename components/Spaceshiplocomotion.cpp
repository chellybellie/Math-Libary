#include "Spaceship.h"
#include "sfwdraw.h"
#include "Ridgedbody.h"
Spaceshiplocomotion::Spaceshiplocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.f;
	turn = 0.f;
	speed = 90.0f;
	maxSpeed = 1000.f;

}
void Spaceshiplocomotion::doThrust(float value)
{
	vertThrust = value;

}
void Spaceshiplocomotion::doTurn(float value)
{
	horzThrust = value;
	
}

void Spaceshiplocomotion::update(Rigidbody &rigidbody, float deltaTime)
{
	rigidbody.velocity.x += horzThrust * speed;
	rigidbody.velocity.y += vertThrust * speed;
	rigidbody.angularVelocity += turn;

	vertThrust = 0.0f;
	horzThrust = 0.0f;
	turn = 0.0f;

	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);
		rigidbody.velocity = dir * maxSpeed;
	}
}