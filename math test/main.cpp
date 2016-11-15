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
	vec2 I = vec2{ 1,1 };
	vec2 Ref = vec2{ 1,-1 };
	vec2 xaxis = vec2{ 1,0 };

	assert((projection(I, xaxis) == xaxis));


	assert((Reflection(-I, xaxis) == Ref));


	return 0;

}