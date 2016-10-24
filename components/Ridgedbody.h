#pragma once
#include "vec-2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	vec2 velocity;
	vec2 acceleration;	
	vec2 impulse;
	vec2 force;

	float angularVelocity;
	float mass;
	float drag;
	float angularDrag;
	float torque;
	float angularAcceleration;
	void addForce(const vec2 &a_force);
	void addImpulde(const vec2 &a_impulse);
	void addTorque(float a_torque);

	void integrate(Transform &trans, float deltaTime);
	void debugDraw(const mat3& T, const Transform &trans);
};