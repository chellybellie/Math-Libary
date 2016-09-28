#pragma once
#include "vec-2.h"


class Transform
{
public:
	vec2 position;
	vec2 scale;
	float facing;

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();

};