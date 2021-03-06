#include "Ridgedbody.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstdio>
Rigidbody::Rigidbody()
{
	mass = 1;
	drag = .5f;
	angularDrag = 1.f;

	force = vec2{ 0,0 };	
	impulse = vec2{ 0,0 };
	acceleration = vec2 { 0,0 };
	velocity = vec2 {0,0};
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
	torque = 0;


}


vec2 Rigidbody::randDir()
{
	return normal(vec2{ rand11(), rand11() });
}

float Rigidbody::rand11()
{
	return 1 - 2 * rand() / (float) RAND_MAX;
}

float Rigidbody::mag()
{
	return  magnitude(velocity);
}

void Rigidbody::addForce(const vec2 &a_force)
		{force += a_force; }
void Rigidbody::addImpulde(const vec2 &a_impulse)
		{impulse += a_impulse; }
void Rigidbody::addTorque(float a_torque)
		{torque += a_torque; }



void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	acceleration      = force / mass;
	velocity         += acceleration * deltaTime + impulse / mass;
	trans.m_position += velocity * deltaTime;
	force = impulse = { 0,0 };

	//Dampening force
	force = -velocity * drag;

	angularAcceleration  = torque / mass;
	angularVelocity     += angularAcceleration * deltaTime;
	trans.m_facing      += angularVelocity     * deltaTime;

	torque = 0;
	
	torque = -angularVelocity  * angularDrag;
}

void Rigidbody::debugDraw(const mat3& T, const Transform & trans)
{


	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	vec2 v = p  + velocity;
	vec2 a = acceleration + p;

	sfw::drawLine(p.x, p.y, a.x, a.y, RED);
	
}





