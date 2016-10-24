#include "PlanetRenderer.h"

#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(const mat3 & T, Transform & PlanetTrans)
{
	mat3 glob = PlanetTrans.getGlobalTransform();

	vec2 pos = glob[2].xy;

	sfw::drawCircle(pos.x, pos.y, size, 12U, color);
}
