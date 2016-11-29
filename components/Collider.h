#pragma once

#include "shapes.h"
#include "transform.h"
#include "collsion.h"
#include "Ridgedbody.h"

class Collider
{
public:
	AABB box;
	Hull hull[5];
	int hsize;
	
	Collider();

	// Construct a collider with one hull.
	Collider(const vec2 *verts, int size);

	// Construct a collider with multiple hulls.
	Collider(const Hull hulls[], int a_hsize);

	void DebugDraw(const mat3 &T, const Transform & trans);
};

CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
	const Transform &BT, const Collider &BC);

CollisionData StaticResolution(Transform &AT, Rigidbody &AR, const Collider &AC,
					     const Transform &BT, const Collider &BC,
					     float Bounce = 5);

CollisionData DynamicResolution(Transform &AT, Rigidbody & AR, const Collider &AC,
								Transform &BT, Rigidbody & BR,const Collider &BC,
								float Bounce = 5);