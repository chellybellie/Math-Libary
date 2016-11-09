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
struct plane
{
	vec2 pos, dir;
};
plane  operator*(const mat3 & T, const plane  &C);
bool operator==(const plane &A, const plane &B);
//Ray operator*(const mat3 &T, const Ray &C);

struct Hull 
{

	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;
	Hull(const vec2 *a_vertices, unsigned vsize);
	Hull();
};
Hull operator*(const mat3 &T, const Hull &H);
bool operator==(const Hull &A, const Hull &B);