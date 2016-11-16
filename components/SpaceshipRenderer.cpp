#include "SpaceshipRenderer.h"
#include "sfwdraw.h"
#include "drawshape.h"
#include "transform.h"
SpaceshipRenderer::SpaceshipRenderer()
{
	color = BLACK;

}
void SpaceshipRenderer::draw(const mat3 & T, const Transform & ship)
{
	mat3 glob = T * ship.getGlobalTransform();

	vec3 nose = glob * vec3{ 0, 8.5 , 1 };
	vec3 backL = glob * vec3{ 0,-.5, 1 };
	vec3 backR = glob * vec3{ 1,1, 1 };
	vec3 center = glob * vec3{ 0,5, 1 };
	vec3 centerL= glob * vec3{ 0,-.5, 1 };
	vec3 centerR = glob * vec3{ 0,-.5, 1 };


	vec3 R = glob * vec3{ -1, 1, 1 };
	vec3 R1 = glob * vec3{ -3, 2, 1 };
	vec3 R2 = glob * vec3{ -2,-1, 1 };//red
	vec3 R3 = glob * vec3{ -2,-6, 1 };//blue 
	vec3 R4 = glob * vec3{ -4.5,-1, 1 };//green
	vec3 R5 = glob * vec3{ -3,2, 1 };//red

	vec3 L = glob * vec3 { 1, 1, 1 };
	vec3 L1 = glob * vec3{ 3, 2, 1 };
	vec3 L2 = glob * vec3{ 2, -1, 1 };//red
	vec3 L3 = glob * vec3{ 2,-6, 1 };//blue
	vec3 L4 = glob * vec3{ 4.5,-1, 1 };//green
	vec3 L5 = glob * vec3{ 3,2, 1 };//red




	
	sfw::drawLine(nose.x, nose.y, R.x, R.y, color);
	sfw::drawLine(backR.x, backR.y, backL.x, backL.y, RED);
	sfw::drawLine(backL.x, backL.y, R.x, R.y, RED);
	sfw::drawLine(center.x, center.y, backL.x, backL.y, RED);
	sfw::drawLine(centerL.x, centerL.y, L2.x, L2.y, RED);
	sfw::drawLine(centerR.x, centerR.y, R2.x, R2.y, RED);


	sfw::drawLine(R.x, R.y, R1.x, R1.y, BLUE);
	sfw::drawLine(R1.x, R1.y, R2.x, R2.y, GREEN);
	sfw::drawLine(R2.x, R2.y, R3.x, R3.y, RED);
	sfw::drawLine(R3.x, R3.y, R4.x, R4.y, BLACK);
	sfw::drawLine(R4.x, R4.y, R5.x, R5.y, YELLOW);

	sfw::drawLine(nose.x, nose.y, L.x, L.y, color);
	sfw::drawLine(L.x, L.y, L1.x, L1.y, color);
	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, color);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);
	sfw::drawLine(L3.x, L3.y, L4.x, L4.y, color);
	sfw::drawLine(L4.x, L4.y, L5.x, L5.y, color);

	//drawcircle(glob * Circle{ 0,0,5 }, BLACK);
	//drawAABB(glob *  AABB{ 0,0, 10, 10 }, BLACK);
	//drawPlane(glob * plane{ 0,0,0,1 }, CYAN);
}
