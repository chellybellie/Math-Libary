#include "Spaceship.h"
#include "sfwdraw.h"

Spaceshiplocomotion::Spaceshiplocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.f;
	breakPower = 5.f;
	stopAction = 0.0f;
	turn = 4.f;


	speed = 900.0f;
	maxSpeed = 1000.f;

}

void Spaceshiplocomotion::doThrust(float value)
		{vertThrust += value;}
void Spaceshiplocomotion::doTurn(float value)
		{horzThrust += value;}
void Spaceshiplocomotion::doStop(float value)
		{stopAction += value;}



void Spaceshiplocomotion::update(const Transform &trans, Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turn * horzThrust);

	//float currentSpeed = magnitude(rigidbody.velocity);
	
	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	vertThrust = 0;
	horzThrust = 0;
	stopAction = 0;
}