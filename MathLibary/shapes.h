#pragma once
#include "matrix3.h"

struct Circle
{
	vec2  pos;
	float rad;
};
Circle operator*(const mat3 &T, const Circle &C);
bool operator ==(const Circle &A, const Circle &B);

struct AABB
{
	vec2 pos, he;
	

	vec2 min() const;
	vec2 max() const;
	
};


AABB operator*(const mat3 &T, const AABB &B);
//Plane operator*(const mat3 &T, const Plane &C);
//Ray operator*(const mat3 &T, const Ray &C);
//Hull operator*(const mat3 &T, const Hull &C);