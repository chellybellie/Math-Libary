#pragma once
#include "Ridgedbody.h"
class Spaceshiplocomotion
{
	
	float vertThrust; 
	float horzThrust;

	float turn;

	float maxSpeed;
	float speed;
public:
	void doThrust(float value);
	void doTurn(float value);
	Spaceshiplocomotion();
	void update(Rigidbody &rigidbody, float deltaTime);


};