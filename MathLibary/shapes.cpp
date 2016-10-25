#include "shapes.h"

Circle operator*(const mat3 &T, const Circle &C)
{
	Circle retval;

	float Xrad = magnitude(T * vec3{ C.rad, 0, 0 });
	float Yrad = magnitude(T * vec3{ 0, C.rad, 0 });

	retval.pos = (T * vec3{C.pos.x, C.pos.y, 1}).xy;

	retval.rad = Xrad > Yrad ? Xrad : Yrad;
	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && A.rad == B.rad;
}

AABB operator*(const mat3 & T, const AABB & A)
{
	return AABB();
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}
