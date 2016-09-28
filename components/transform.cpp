#include "transform.h"
#include "sfwdraw.h"

Transform::Transform()
{
	position.x = 0;
	position.y = 0;

	scale.x = 28;
	scale.y = 8;

	facing = 0;
}

Transform::Transform(float x, float y): Transform()
{
	position.x = x;
	position.y = y;
}

vec2 Transform::getDirection()
{
	return fromangle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = ::angle(dir);
}

void Transform::debugDraw()
{
		sfw::drawCircle(position.x, position.y, 20);

		vec2 dirEnd = position + getDirection()*12;
		vec2 upEnd = position - perp(getDirection()) * 12;

		sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);
		sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);

}
