#include "Ridgedbody.h"
#include "sfwdraw.h"
#include <cstdio>
Rigidbody::Rigidbody()
{
	mass = 1;
	drag = .25;
	force = vec2{ 0,0 };
	acceleration = vec2 { 0,0 };
	impulse = vec2{ 0,0 };
	velocity = vec2 {0,0};
	torque = 0;

	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;

}
void Rigidbody::addForce(const vec2 &a_force)
{	force += a_force;}

void Rigidbody::addImpulde(const vec2 &a_impulse)
{impulse += a_impulse;}

void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
}

void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	acceleration = force / mass;
	velocity += acceleration * deltaTime + impulse / mass;
	trans.m_position = trans.m_position + velocity * deltaTime;
	force = impulse = { 0,0 };

	force = -velocity * drag;

	angularAcceleration = torque / mass;
	angularVelocity  += angularAcceleration * deltaTime;
	trans.m_facing  += angularVelocity * deltaTime;
	torque = 0;

	torque = -angularVelocity  * drag;

}

void Rigidbody::debugDraw(const Transform & trans)
{


	vec2 p = trans.m_position;
	vec2 v = p - -velocity;
	vec2 a = acceleration + v;

	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
	sfw::drawCircle(a.x, a.y,1, 1, MAGENTA);
}
