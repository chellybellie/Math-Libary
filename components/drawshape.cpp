#include "drawshape.h"
#include "sfwdraw.h"
void drawcircle(const Circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12, color);
}

void drawAABB(const AABB &B, unsigned color)
{
	sfw::drawLine(B.min().x, B.min().y, B.max().x, B.min().y, color);
	sfw::drawLine(B.min().x, B.min().y, B.min().x, B.max().y, color);
	sfw::drawLine(B.max().x, B.max().y, B.max().x, B.min().y, color);
	sfw::drawLine(B.max().x, B.max().y, B.min().x, B.max().y, color);
}
