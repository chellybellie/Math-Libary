#include "Collider.h"
#include "drawshape.h"
#include <cmath>


Collider::Collider(const vec2 * verts, int size)
			: hull(verts,size)
{

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

void Collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();

	//drawAABB(glob  * box, 0x888888ff);
	drawHull(glob * hull, 0x888888ff);
}

CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
	const Transform &BT, const Collider &BC)
{
	CollisionData retval;
	
	retval = boxCollision(AT.getGlobalTransform()* AC.box,
						  BT.getGlobalTransform()* BC.box);


	if (retval.penetrationDepth >= 0)
	{
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
			                   BT.getGlobalTransform() * BC.hull);
		/*
		for(int i = 0; i < AC.hsize; ++i)
			for(int j = 0; j < BC.hsize; ++j)
			{

			CollisionData temp = HullCollision(AT.getGlobalTransform() * AC.hull,
											   BT.getGlobalTransform() * BC.hull);

			if(temp.penetrationDepth < retval.penetrationDepth)
				retval = temp;
			}

		*/
	}
	return retval;

}

CollisionData StaticResolution(Transform & AT, Rigidbody &AR, const Collider & AC, 
						 const Transform & BT, const Collider & BC,
						 float Bounce = 1)
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
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		AT.m_position -= MTV / 2;
		BT.m_position += MTV / 2;

		vec2 Av = AR.velocity;
		float Am = AR.mass;
	
		vec2 Bv = AR.velocity;
		float Bm = AR.mass;
		vec2 X;
		vec2 Y;

		X = (Av * Am + Bv * Bm + (-Bounce*(Av - Bv))
					 * Bm) / (Bm + Am);

		Y = Bounce * (Av - Bv) + (Av * Am + Bv * Bm 
				  + (-Bounce * (Av - Bv)) * Bm) / (Bm - Am);
		AR.velocity = X;
		BR.velocity = Y;
	}
	
	return results;
}
