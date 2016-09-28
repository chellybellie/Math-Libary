#include "transform.h"
#include "sfwdraw.h"

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
		sfw::drawCircle(position.x, position.y, 12);

		vec2 dirEnd = position + getDirection()*12;
		vec2 upEnd = position - perp(getDirection()) * 12;

		sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);
		sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);

}
