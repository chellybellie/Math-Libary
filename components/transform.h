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

	vec2 getUp() const;
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);
	void transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0 );

	void debugDraw();

};