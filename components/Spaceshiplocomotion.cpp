#include "Spaceship.h"
#include "sfwdraw.h"
#include "Ridgedbody.h"
Spaceshiplocomotion::Spaceshiplocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.f;
	breakPower = 5.f;
	turn = 4.f;
	speed = 90.0f;
	maxSpeed = 1000.f;

}
void Spaceshiplocomotion::doThrust(float value)
{
	vertThrust += value;
}
void Spaceshiplocomotion::doTurn(float value)
{
	horzThrust += value;
}

void Spaceshiplocomotion::doStop(float value)
{
	stopAction += value;
}

void Spaceshiplocomotion::update(const Transform &trans, Rigidbody &rigidbody, float deltaTime)
{
	rigidbody.addForce(trans.getDirection() * speed * vertThrust);
	rigidbody.addTorque(turn * horzThrust);

	float currentSpeed = magnitude(rigidbody.velocity);
	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);

	vertThrust = horzThrust = stopAction = 0;
}