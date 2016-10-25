#pragma once
#include "vec-2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	float mass, drag, angularDrag;

	vec2 impulse, force;
	vec2 velocity;			   // represents the change in position
	vec2 acceleration;		   // represents the change in velocity



	
	float torque;
	float angularVelocity;     //represents the change in rotation
	float angularAcceleration; //represets the change in ang velocity

	void addForce(const vec2 &a_force);
	void addImpulde(const vec2 &a_impulse);
	void addTorque(float a_torque);

	void integrate(Transform &trans, float deltaTime);  // performs integration :)
	void debugDraw(const mat3& T, const Transform &trans);
};