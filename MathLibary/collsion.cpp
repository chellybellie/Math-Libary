#include "collsion.h"
#include <cmath>

CollisionDAta1D colllisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	 CollisionDAta1D retval;
	 float Dr = Amax - Bmin;
	 float Dl = Bmax - Amin;
	 retval.penetrationDepth = fminf(Dr , Dl);
	
	 
	 // MAke sure this is 1 or -1
	 retval.collisionNormal = (Amax - Bmin) - (Bmax - Amin);
	 if (Dr >= 1)
	 {
		 retval.result = 1;
	 }
	 if (Dl <= -1)
	 {
		 retval.result = -1;
	 }
	 else
		 retval.result = false;


	 retval.result = retval.penetrationDepth >= 0;
	 retval.MTV    = retval.penetrationDepth * retval.collisionNormal;



	 return retval;
}
