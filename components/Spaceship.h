#pragma once
#include "Ridgedbody.h"
class Spaceshiplocomotion
{
	
	float vertThrust; 
	float horzThrust;
	float stopAction;

	float turn;

	float breakPower;
	float maxSpeed;
	
public:
	float speed;

	void doThrust(float value);
	void doTurn(float value);
	void doStop(float value);
	Spaceshiplocomotion();
	
	void update(const Transform &trans, Rigidbody &rigidbody, float deltaTime);


};