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

CollisionData planeBoxCollision(const plane & P, const AABB & B)
{
	CollisionData retval;
	
	vec2 Bc = { B.min().x, B.min().y};
	vec2 Ba = { B.min().x, B.max().y};
	vec2 Bd = { B.max().x, B.min().y};
	vec2 Bb = { B.max().x, B.max().y};

	float fBa = dot(P.dir, Ba);
	float fBb = dot(P.dir, Bb);
	float fBc = dot(P.dir, Bc);
	float fBd = dot(P.dir, Bd);

	float PMAX = dot(P.dir, P.pos);

	float FTR = dot(P.dir, Ba);
	float FTL = dot(P.dir, Bb);
	float FBR = dot(P.dir, Bc);
	float FBL = dot(P.dir, Bd);

	float AMin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float AMax = fmaxf(fmaxf(FTR, FTL), fmaxf(FBR, FBL));

	retval.penetrationDepth = PMAX - AMin;
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionDataSwept SweptPlaneBoxCollision(const plane & P, const AABB & B, const vec2 & vB)
{
	CollisionDataSwept retval;

	vec2 TR = { B.max().x, B.max().y };
	vec2 TL = { B.min().x, B.max().y };
	vec2 BR = { B.max().x, B.min().y };
	vec2 BL = { B.min().x, B.min().y };

	float PMAX = dot(P.dir, P.pos);

	float velB = dot(P.dir, vB);

	float FTR = dot(P.dir, TR);
	float FTL = dot(P.dir, TL);
	float FBR = dot(P.dir, BR);
	float FBL = dot(P.dir, BL);

	float AMin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float AMax = fmaxf(fmaxf(FTR, FTL), fmaxf(FBR, FBL));

	retval.entryTime = (AMin - PMAX) / (0 - velB);
	retval.exitTime = (AMax - PMAX) / (0 - velB);


	
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionData HullCollision(const Hull &A, const Hull &B)
{
	 CollisionData retval;

	 retval.penetrationDepth = INFINITY;
	 /////A HULL //////


	 for (int j = 0; j < A.size; ++j)
	{
		 float aAmax = INT_MIN;
		 float aAmin = INT_MAX;
		 float aBmax = INT_MIN;
		 float aBmin = INT_MAX;

		for (int i = 0; i < A.size; ++i)
		{
			float proj = dot(A.vertices[i], A.normals[j]);
			aAmin = fminf(aAmin, proj);
			aAmax = fmaxf(aAmax, proj);
		}

		for (int i = 0; i < B.size; ++i)
		{
			float proj = dot(B.vertices[i], A.normals[j]);
			aBmin = fminf(aBmin, proj);
			aBmax = fmaxf(aBmax, proj);
		}

		float aDr = aAmax - aBmin;
		float aDl = aBmax - aAmin;
		float aPD = fminf(aDr, aDl);
		float acopy = copysignf(1, aDl - aDr);

		if(aPD < retval.penetrationDepth)
		{
			retval.penetrationDepth = aPD;
			retval.collisionNormal = acopy * A.normals[j];
		}
	}

	 /////B HULL //////

	 for (int j = 0; j < B.size; ++j)
	 {
		 float aAmax = INT_MIN;
		 float aAmin = INT_MAX;
		 float aBmax = INT_MIN;
		 float aBmin = INT_MAX;

		 for (int i = 0; i < A.size; ++i)
		 {
			 float proj = dot(A.vertices[i], B.normals[j]);
			 aAmin = fminf(aAmin, proj);
			 aAmax = fmaxf(aAmax, proj);
		 }

		 for (int i = 0; i < B.size; ++i)
		 {
			 float proj = dot(B.vertices[i], B.normals[j]);
			 aBmin = fminf(aBmin, proj);
			 aBmax = fmaxf(aBmax, proj);
		 }

		 float aDr = aAmax - aBmin;
		 float aDl = aBmax - aAmin;
		 float aPD = fminf(aDr, aDl);
		 float acopy = copysignf(1, aDl - aDr);

		 if (aPD < retval.penetrationDepth)
		 {
			 retval.penetrationDepth = aPD;
			 retval.collisionNormal = acopy * B.normals[j];
		 }
	 }
return retval;
}


