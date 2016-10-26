#pragma once

struct  CollisionDAta1D
{
	bool result;			// penetrationDepth > 0
	float penetrationDepth; // how much overlap
	float collisionNormal; // -1 or 1
	float MTV;				// penetrationDepth * collisionNormal

};

CollisionDAta1D colllisionDetection1D(float Amin, float Amax, 
									  float Bmin, float Bmax);

