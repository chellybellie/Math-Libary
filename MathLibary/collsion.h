#pragma once
#include "vec-2.h"
#include "shapes.h"

struct  CollisionDAta1D
{
	bool result;			// penetrationDepth > 0
	float penetrationDepth; // how much overlap
	float collisionNormal; // -1 or 1
	float MTV;				// penetrationDepth * collisionNormal

};

CollisionDAta1D colllisionDetection1D(float Amin, float Amax, 
									  float Bmin, float Bmax);

struct  SweptCollisionDAta1D
{
	
	float entryTime, exitTime;
	float collisionNormal;

	bool result() const;

};

SweptCollisionDAta1D sweptDetection1D(float Amin, float Amax, float Avel,
								 float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 mtv() const;
};

CollisionData boxCollision(const AABB &A,
						   const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
								const AABB &B, const vec2 &dB);