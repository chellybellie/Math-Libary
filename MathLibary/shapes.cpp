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

AABB operator*(const mat3 & T, const AABB & B)
{
	AABB retval = B;
	
	vec3 tC = (T * vec3{ B.min().x, B.min().y, 1 });
	vec3 tA = (T * vec3{ B.min().x, B.max().y, 1 });
	vec3 tD = (T * vec3{ B.max().x, B.min().y, 1 });
	vec3 tB = (T * vec3{ B.max().x, B.max().y, 1 });

	vec3 tp[4];
	tp[0] = T * vec3{ B.min().x, B.min().y}; // c
	tp[1] = T * vec3{ B.min().x, B.max().y}; // a
	tp[2] = T * vec3{ B.max().x, B.min().y}; // d
	tp[3] = T * vec3{ B.max().x, B.max().y}; // b

	vec2 minv = tp[0].xy, maxv = tp[0].xy;
	for (int i = 0; i < 4; ++i)
	{
		if (tp[i].x < minv.x)
		{
			minv.x = tp[i].x;
		}
		if (tp[i].x > maxv.x)
		{
			maxv.x = tp[i].x;
		}
		if (tp[i].y < minv.y)
		{
			minv.y = tp[i].y;
		}
		if (tp[i].y > maxv.y)
		{
			maxv.y = tp[i].y;
		}
	}
	
	float halfX = (maxv.x - minv.x) /2 ;
	float halfY = (maxv.y - minv.y)/2 ;

	retval.he = {halfX, halfY};
	 retval.pos = (T * vec3{ B.pos.x, B.pos.y, 1 }).xy;

	return retval;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

plane operator*(const mat3 & T, const plane & P)
{
	plane retval;
	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;
	retval.dir = normal(T * vec3{ P.dir.x,P.dir.y, 0 }).xy;
	return retval;
}

bool operator==(const plane & A, const plane & B)
{
	return A.pos == B.pos && A.dir == B.dir;
}

Hull operator*(const mat3 &T, const Hull &H)
{
	Hull retval;

	for (int i = 0; i < H.size; ++i)
	{
		retval.vertices[i] = (T * vec3{ H.vertices[i].x, H.vertices[i].y,1 }).xy;
		retval.normals[i] = (T * vec3{ H.normals[i].x, H.normals[i].y,0 }).xy;
	}

	retval.size = H.size;
	return retval;
}
	bool operator==(const Hull & A, const Hull & B)
{
	return B.vertices == A.vertices && A.normals == B.normals;
}

Hull::Hull(const vec2 * a_vertices, unsigned a_size)
{

	size = a_size;
	for (int i = 0; i < a_size; ++i)
	{
		vertices[i] = a_vertices[i];
		normals[i] = -perp(normal(a_vertices[(i + 1) % size] - a_vertices[i]));
	}

}

Hull::Hull()
{
}
