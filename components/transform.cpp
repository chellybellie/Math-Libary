#include "transform.h"
#include "sfwdraw.h"

Transform::Transform()
{
	position.x = 0;
	position.y = 0;

	scale.x = 28;
	scale.y = 8;

	facing = 80;
}

Transform::Transform(float x, float y): Transform()
{
	position.x = x;
	position.y = y;
}
vec2 Transform::getUp() const
{
	return -perp(getDirection());
}
vec2 Transform::getDirection() const
{
	return fromangle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = ::angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 20, 20,BLACK);
	sfw::drawCircle(position.x, position.y, 8, 8, RED);
	vec2 dirEnd = position + getDirection() * scale.x * 4;
	vec2 upEnd = position - perp(getDirection()) * scale.y * 4;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, BLUE);
	//sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);

}