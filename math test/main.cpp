#include <cassert>
#include <iostream>
#include "Test.h"
#include "vec-2.h"
#include "vec-3.h"
#include "flops.h"
#include <cmath>
#include "matrix2.h"
#include "matrix3.h"
#include "shapes.h"
#include "collsion.h"


int main()
{

	vec2 verts[] = { {0,1},{1,1},{1,0},{0,0} };
	vec2 verts2[] = { { -1,-1 },{ -1,1 },{ 0,0 } };

	Hull myHull(verts, 4);
	Hull otherHull(verts2, 3);


	Hull tHull = translate(1, 0) * myHull;

	assert(fequals(HullCollision(myHull, otherHull).penetrationDepth, 0));
	//assert(fequals(HullCollision(myHull, tHull).penetrationDepth, -1));

	return 0;

}