#include "transform.h"
#include "sfwdraw.h"
#include "drawshape.h"
#include "shapes.h"


Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
	m_parent = nullptr;
}
vec2 Transform::getUp() const
	{ return -perp(getDirection()); }

vec2 Transform::getDirection() const
	{ return fromangle(m_facing); }

void Transform::setDirection(const vec2 & dir)
	{ m_facing = angle(dir); }

vec2 Transform::getGlobalPosition() const
	{ return getGlobalTransform()[2].xy; }

// first column of global Transform
vec2 Transform::getGlobalright() const
	{ return getGlobalTransform()[0].xy; }


vec2 Transform::getGloablUp() const
	{ return getGlobalTransform()[1].xy; }

float Transform::getGlobalAngle() const
	{ return angle(getGlobalright()); }


mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getlocaltransform();

	else
		return m_parent->getGlobalTransform() * getlocaltransform();
}


mat3 Transform::getlocaltransform() const
{
	mat3 T = translate(m_position.x, m_position.y);

	mat3 S = scale(m_scale.x, m_scale.y);

	mat3 R = rotation(m_facing);


	return T * R * S;
	
}


void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getGlobalTransform();

	vec3 pos = L[2];

	vec3 right = L * vec3{ 5, 0, 1 };
	vec3 up    = L * vec3{ 0, 5, 1 };


	vec3 sgp = m_parent ? (T * m_parent->getGlobalTransform())[2] : pos;

}