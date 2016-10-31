#include "collsion.h"
#include <cmath>

CollisionDAta1D colllisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	 CollisionDAta1D retval;
	 float Dr = Amax - Bmin;
	 float Dl = Bmax - Amin;
	 retval.penetrationDepth = fminf(Dr , Dl);
	
	 
	 // MAke sure this is 1 or -1
	 retval.collisionNormal = copysignf(1, Dl - Dr);
	 


	 retval.result = retval.penetrationDepth >= 0;
	 retval.MTV    = retval.penetrationDepth * retval.collisionNormal;



	 return retval;
}

SweptCollisionDAta1D sweptDetection1D(float Amin, float Amax, float Avel, 
									  float Bmin, float Bmax, float Bvel)
{
	 SweptCollisionDAta1D retval;

	 float Tl = (Amin - Bmax) / (Bvel - Avel);
	 float Tr = (Bmin - Amax) / (Avel - Bvel);

	 retval.exitTime = fmaxf(Tl, Tr);
	 retval.entryTime = fminf(Tl, Tr);

	 retval.collisionNormal = copysignf(1, Tl - Tr);

	 return retval;
}

bool SweptCollisionDAta1D::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}


CollisionData boxCollision(const AABB & A, const AABB & B)
{
	 CollisionData retval;

	 CollisionDAta1D XCD = 
	 colllisionDetection1D(A.min().y, A.max().y,
					   	   B.min().y, B.max().y);
	
	 CollisionDAta1D YCD =

	 colllisionDetection1D(A.min().x, A.max().x,
						   B.min().x, B.max().x);

	 if (XCD.penetrationDepth < YCD.penetrationDepth)
	 {
		 retval.penetrationDepth = XCD.penetrationDepth;
		 retval.collisionNormal = vec2{ 1,0 } *XCD.collisionNormal;
	 }
	 else
	 {
		 retval.penetrationDepth = YCD.penetrationDepth;
		 retval.collisionNormal = vec2{ 1,0 } *YCD.collisionNormal;
	 }

	 return retval;
}


bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}

vec2 CollisionData::mtv() const
{
	return  penetrationDepth * collisionNormal;
}

bool CollisionDataSwept::result() const
{
	return false;
}

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, 
								const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	SweptCollisionDAta1D resX = sweptDetection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max().x, dB.x);

	SweptCollisionDAta1D resY = sweptDetection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max().y, dB.y);



	if (resY.entryTime < resX.entryTime && !isinf(resX.entryTime))
	{
		retval.collisionNormal = vec2{ 1,0 } *resX.collisionNormal;
		retval.entryTime = resX.entryTime;
	}
	else
	{
		retval.collisionNormal = vec2{ 0,1 } *resY.collisionNormal;
		retval.entryTime = resY.entryTime;
	}

	if (resY.exitTime < resX.exitTime || isinf(resX.exitTime))
	{
		retval.exitTime = resY.exitTime;
	}
	else
	{
		retval.exitTime = resX.exitTime;
	}

	 return retval;
}