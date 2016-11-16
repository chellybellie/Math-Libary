#include "Collider.h"
#include "drawshape.h"
#include <cmath>
#include <cassert>


Collider::Collider(const vec2 * verts, int size)
{
	// create the hull!
	hull[0] = Hull(verts, size);
	hsize = 1;

	// create the box!
	float minx = INFINITY;
	float maxx = -INFINITY;
	float miny = INFINITY;
	float maxy = -INFINITY;

	for (int i = 0; i < size; ++i)
	{
		if (verts[i].x < minx)
		{
			minx = verts[i].x;
		}
		if (verts[i].x > maxx)
		{
			maxx = verts[i].x;
		}
		if (verts[i].y < miny)
		{
			miny = verts[i].y;
		}
		if (verts[i].y > maxy)
		{
			maxy = verts[i].y;
		}
	}

	vec2 min = { minx,miny };
	vec2 max = { maxx,maxy };
	box.pos = (min + max) / 2;
	box.he =  (min - max) / 2;
}

Collider::Collider(const Hull hulls[], int a_hsize)
{
	// create the box!

	float minx = INFINITY;
	float maxx = -INFINITY;
	float miny = INFINITY;
	float maxy = -INFINITY;

	hsize = a_hsize;

	for (int j = 0; j < a_hsize; ++j)
	{
		hull[j] = hulls[j];
		const Hull& currentHull = hulls[j];
		const vec2* currentVerts = currentHull.vertices;

		for (int i = 0; i < currentHull.size; ++i)
		{
			if (currentVerts[i].x < minx)
			{
				minx = currentVerts[i].x;
			}
			if (currentVerts[i].x > maxx)
			{
				maxx = currentVerts[i].x;
			}
			if (currentVerts[i].y < miny)
			{
				miny = currentVerts[i].y;
			}
			if (currentVerts[i].y > maxy)
			{
				maxy = currentVerts[i].y;
			}
		}
	}

	vec2 min = { minx,miny };
	vec2 max = { maxx,maxy };
	box.pos = (min + max) / 2;
	box.he = (min - max) / 2;
}

void Collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();

	drawAABB(glob  * box, 0x888888ff); /// DRAWS COLLIDER RECONIGTION BOX
	for(int i = 0; i < hsize; ++i)
		drawHull(glob * hull[i], 0x888888ff);
}

Collider::Collider()
{
}

CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
	const Transform &BT, const Collider &BC)
{
	CollisionData retval;
	
	retval = boxCollision(AT.getGlobalTransform()* AC.box,
						  BT.getGlobalTransform()* BC.box);


	// if the boxes are in collision, the hulls might be... :D
	if (retval.penetrationDepth >= 0)
	{
		// todo: this is not great. could be done better!
		retval = CollisionData();
		retval.penetrationDepth = -INFINITY;

 		for(int i = 0; i < AC.hsize; ++i)
			for(int j = 0; j < BC.hsize; ++j)
			{
				CollisionData temp = HullCollision(AT.getGlobalTransform() * AC.hull[i],
												   BT.getGlobalTransform() * BC.hull[j]);

				if (temp.penetrationDepth > retval.penetrationDepth)
				{			
					retval = temp;
				}
			}
	}
	return retval;

}

CollisionData StaticResolution(Transform & AT, Rigidbody &AR, const Collider & AC, 
						 const Transform & BT, const Collider & BC,
						 float Bounce)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);

	
		if (results.penetrationDepth >= 0)
			{
				vec2 MTV = results.penetrationDepth * results.collisionNormal;
				AT.m_position -= MTV;

				AR.velocity = Reflection(AR.velocity , results.collisionNormal) * Bounce;
	}
	return CollisionData();
}

CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC, 
						        Transform & BT, Rigidbody & BR, const Collider & BC,
								float Bounce)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);



	if (results.penetrationDepth >= 0)
	{
		////////////CORRETION FOR COLLISION/////////////
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(AR.mass * AR.velocity) + 0.0000001f;
		float bm = magnitude(BR.mass * BR.velocity) + 0.0000001f;
		float cm = am + bm;

		AT.m_position -= MTV * ( 1- am / cm);
		BT.m_position += MTV * (1 - bm / cm);

		//////////RESOLUTION////////////

		vec2 a = AR.velocity; // VELOCITY FOR A
		float p = AR.mass;    // MASS FOR A
		vec2 X;               // FINAL VELOCITY FOR A

		vec2 b = AR.velocity; // VELOCITY FOR B
		float q = AR.mass;    // MASS FOR B
		vec2 Y;               // FINAL VELOCITY FOR B

		float E = Bounce;
		/////SOLVING EQUATION////////
		X = (a*p + b*q + -E*(a-b)*q) / (q+p);

		Y = E*(a - b) + X;

		AR.velocity = X;
		BR.velocity = Y;
	}
	
	return results;
}
