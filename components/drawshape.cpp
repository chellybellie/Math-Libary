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
void drawPlane(const plane & A, unsigned color)
{

	vec2 L = -perp(A.dir);
	vec2 R = perp(A.dir);

	sfw::drawCircle(A.pos.x, A.pos.y, 6, 6, color);
	sfw::drawLine(A.pos.x, A.pos.y, (A.dir.x * 100 + A.pos.x), (A.dir.y * 100 + A.pos.y), color);
	sfw::drawLine(A.pos.x, A.pos.y, (L.x * 100 + A.pos.x), (L.y * 100 + A.pos.y), color);
	sfw::drawLine(A.pos.x, A.pos.y, (R.x * 100 + A.pos.x), (R.y * 100 + A.pos.y), color);

}

void drawHull(const Hull & H, unsigned color)
{
	for (int i = 0; i < H.size; ++i)
	{
		H.vertices[i];
		H.vertices[(i + 1) % H.size];
		sfw::drawLine(H.vertices[i].x, H.vertices[i].y,
					  H.vertices[(i + 1) % H.size].x,
					  H.vertices[(i + 1) % H.size].y, BLACK);
	}
	
}

