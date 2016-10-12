#include <cassert>
#include <iostream>
#include "Test.h"
#include "vec-2.h"
#include "vec-3.h"
#include "flops.h"
#include <cmath>
#include "matrix2.h"
#include "matrix3.h"
int main()
{
	

	//////////////////////VECTOR TESTS//////////////////

	//assert( (vec2{ 0,0 } == vec2{ 0,0 }) );
	//
	//assert((vec2{ 1,1 } + vec2{ -1,0 } == vec2{ 0,1 }));
	//assert((vec2{ 1,1 } - vec2{ 0,0 } == vec2{ 1,1 }));
	//assert((vec2{ 1,1 } * vec2{ 0,0 } == vec2{ 0,0 }));
	//assert((vec2{ 1,1 } / vec2{ 1,1 } == vec2{ 1,1 }));

	//assert(((vec2{ 1,1 } * 1.f) == vec2{ 1, 1 }));
	//assert(((1.f * vec2{ 1,1 }) == vec2{ 1, 1 }));
	//assert(((vec2{ 1,1 } /1.f) == vec2{ 1, 1 }));
	//assert(((1.f / vec2{ 1,1 }) == vec2{ 1, 1 }));

	//
	//assert((-(vec2{ 1 ,1 }) == vec2{ -1, -1 }));
	//assert((vec2{ 0,0 } == vec2{ 0,0 } - vec2{ 0, 0 }));
	//assert((vec2{ 0,0 } == vec2{ 0,0 } + vec2{ 0, 0 }));
	//assert((vec2{ 0,0 } == vec2{ 0,0 } * vec2{ 0, 0 }));
	//assert((vec2{ 1,1 } == vec2{ 1,1 } / vec2{ 1, 1 }));

	//assert((vec2{ 1,1 } == vec2{ 1,1 }));
	//assert((vec2{ 1,1 } != vec2{ 2,2 }));



	//assert(fequals(magnitude(vec2{ 4,0 }) , 4));
	//assert(fequals(magnitude(vec2{ -4,0 }), 4));

	////assert(fequals(normal(vec2{ 4,0 }), 4));

	//assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	//assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));
	////assert(perp)
	//assert((fromangle(0) == vec2{ 1,0 }));
	//assert((cross(vec3{ 1, 0, 0 }, vec3{ 0, 1, 0 }) == vec3{0,0,1}));



	//
	//assert(fequals(1, .9999999f));

	//assert(fequals(lerp(.23, 124, 0), .23));
	//assert(fequals(lerp(0, 1, .5f), .5f));

	//assert(fequals(quadBezier(15, 40, 21, 0), 15));
	//assert(fequals(quadBezier(15, 40, 21, 1), 21));

	//assert(fequals(hermitspline(15, 40, 21, 10, 0), 15));
	//assert(fequals(hermitspline(15, 40, 21, 10, 1), 21));

	//assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	//assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	//assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	//assert(fequals(catRomSpline(15, 40, 21, 1), 21));
	//////////////mat2////////
	mat2 m1 = mat2{ 0,0,0,0 };
	mat2 m2 = mat2identity();
	assert(m1 == m1);
	assert(inverse(m1) == m1);
	assert(transpose(m1) == m1);
	mat3 m3 = mat3{ 0,0,0,0 };
	mat3 m4 = mat3identity();
	assert(inverse(m3)== m3);


	vec3 j = { 2,5,1 };

	/*vec3 r = rotation(deg2rad(90))*j;*/

	assert((scale(5, 1) * j == vec3{ 10, 5,1 }));
	assert((rotation(deg2rad(90))*j == vec3{ -5,2,1 }));
	assert((translate(0, 3)*j == vec3{ 2,8,1 }));

	return 0;

	return 0;

}