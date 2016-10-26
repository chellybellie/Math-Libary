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

	vec3 nose = glob * vec3{ 0,  2, 1 };
	
	vec3 R = glob * vec3{ -1, -2, 1 };
	vec3 R1 = glob * vec3{ -3, 1, 1 };
	vec3 R2 = glob * vec3{ -3,-1, 1 };
	vec3 R3 = glob * vec3{ -4,1, 1 };
	vec3 R4 = glob * vec3{ -3,1, 1 };

	vec3 L = glob * vec3{ 1, -2, 1 };
	vec3 L1 = glob * vec3{ 3, 1, 1 };
	vec3 L2 = glob * vec3{ 3, -1, 1 };
	vec3 L3 = glob * vec3{ 4,1, 1 };
	vec3 L4 = glob * vec3{ 3,1, 1 };


	//sfw::drawLine(L.x, L.y, nose.x, nose.y, color);
	sfw::drawLine(nose.x, nose.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, R1.x, R1.y, color);
	sfw::drawLine(R1.x, R1.y, R2.x, R2.y, color);
	sfw::drawLine(R2.x, R2.y, R3.x, R3.y, GREEN);
	sfw::drawLine(R3.x, R3.y, R4.x, R4.y, color);

	sfw::drawLine(nose.x, nose.y, L.x, L.y, color);
	sfw::drawLine(L.x, L.y, L1.x, L1.y, color);
	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, color);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, GREEN);
	sfw::drawLine(L3.x, L3.y, L4.x, L4.y, color);

	drawcircle(glob * Circle{ 0,0,5 }, BLACK);
	drawAABB(glob *  AABB{ 0,0, 5, 5 }, BLACK);
}
