#include "SpaceshipRenderer.h"
#include "sfwdraw.h"

SpaceshipRenderer::SpaceshipRenderer()
{
	color = BLUE;

}
void SpaceshipRenderer::draw(const mat3 & T, const Transform & ship)
{
	mat3 glob = T * ship.getGlobalTransform();

	vec3 nose = glob * vec3{ 0,  2, 1 };
	vec3 L = glob * vec3{ -2,-2, 1 };
	vec3 R = glob * vec3{ -1, -2, 1 };
	vec3 R1 = glob * vec3{ -3,1, 1 };
	vec3 R2 = glob * vec3{ -3,-1, 1 };
	vec3 R2 = glob * vec3{ -3,-1, 1 };


	//sfw::drawLine(L.x, L.y, nose.x, nose.y, color);
	sfw::drawLine(nose.x, nose.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, R1.x, R1.y, color);
	sfw::drawLine(R1.x, R1.y, R2.x, R2.y, GREEN);
	//sfw::drawLine(R2.x, R2.y, L.x, L.y, WHITE);
}
