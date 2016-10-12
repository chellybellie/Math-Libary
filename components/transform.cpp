#include "transform.h"
#include "sfwdraw.h"

Transform::Transform()
{
	m_position.x = 0;
	m_position.y = 0;

	m_scale.x = 28;
	m_scale.y = 8;

	m_facing = 80;
}

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
}
vec2 Transform::getUp() const
{
	return -perp(getDirection());
}
vec2 Transform::getDirection() const
{
	return fromangle(m_facing);
}

void Transform::setDirection(const vec2 & dir)
{
	m_facing = ::angle(dir);
}

mat3 Transform::getlocaltransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);

	mat3 T = translate(m_position.x, m_position.y);

	mat3 R = rotation(m_facing);


	return T * S * R;
	
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getlocaltransform();

	vec3 pos = L[2];

	vec3 right = L * vec3{ 1,0,1 };
	vec3 up = L * vec3{ 0,1,1 };

	sfw::drawCircle(m_position.x, m_position.y, 20, 20,BLACK);
	sfw::drawLine(m_position.x, m_position.y, right.x, right.y, BLUE);
	sfw::drawLine(m_position.x, m_position.y, up.x, up.y, GREEN);


	vec2 dirEnd = m_position + getDirection() * m_scale.x ;
	vec2 upEnd = m_position - perp(getDirection()) * m_scale.y ;

	sfw::drawLine(m_position.x, m_position.y, dirEnd.x, dirEnd.y, BLUE);
	sfw::drawLine(m_position.x, m_position.y, up.x, upEnd.y, GREEN);

}