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
	//mat2 m1 = mat2{ 0,0,0,0 };
	//mat2 m2 = mat2identity();
	//assert(m1 == m1);
	//assert(inverse(m2) == m2);
	//assert(transpose(m1) == m1);
	//mat3 m3 = mat3{ 1, 2, 3, 4, 5, 6, 7, 0, 9 };
	//mat3 m4 = mat3identity();
	//assert(inverse(m3)*m3 == m4);


	//vec3 j = { 2,5,1 };
	//vec3 s = scale(5, 1) *j;
	//vec3 r = rotation(deg2rad(90))*j;

	//assert((scale(5, 1) * j == vec3{ 10, 5,1 }));
	//assert((rotation(deg2rad(90))*j == vec3{ -5,2,1 }));
	//assert((translate(0, 3)*j == vec3{ 2,8,1 }));
	//
	////vec3 result = rotation(deg2rad(-90)) * translate(10, 0) * rotation(deg2rad(45)) * translate(4,0) * rotation(deg2rad(45)) * translate(6,4)  * translate(-6,0) * vec3 { 0, 0, 1 };
	//assert((rotation(deg2rad(-90)) * translate(10, 0) * rotation(deg2rad(45)) * translate(4, 0) * rotation(deg2rad(45)) * translate(6, 4)  * translate(-6, 0) * vec3 { 0, 0, 1 } == vec3{ 2*sqrtf(2),-6-2*sqrtf(2),1 }));







	//Circle c = { 0,0,5 };

	//assert((translate(4, 0) * c == Circle{ 4,0,5 }));



	//assert((rotation(45) * c == Circle{ 0,0,5 }));



	//AABB testA = {1, 2,  3, 4};
	//assert((testA.min() == vec2{ -2,-2 }));
	//assert((testA.max() == vec2{ 4,6 }));

	//////////////collision tests/////////////////
	assert(colllisionDetection1D(0, 2, 1, 3).result == true);
	assert(colllisionDetection1D(0, 2, 1, 3).penetrationDepth == 1);

















	return 0;

	return 0;

}