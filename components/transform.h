#pragma once
#include "vec-2.h"


class Transform
{
public:
	Transform();
	Transform(float x, float y);
	vec2 position;
	vec2 scale;
	float facing;

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();

};