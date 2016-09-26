#include "Test.h"
#include <cmath>

int donothing(int x)
{
	return x*x + 2*x + 5;
}

float test_quad(float x)
{
	return x*x + 2 *x - 7;
}

quad_results quad(float a, float b, float c)
{
	quad_results retval;

	 retval.left_root =  (b*-1 + sqrt(b*b - 4 * a*c) / (2 * a));
	 retval.right_root = (b*-1 - sqrt(b*b - 4 * a*c) / (2 * a));
	 float d = b*b - 4 * a*c;

	 if (d < 0)
	 {
		 retval.roots = 0;
	 }
	 else if (d == 0.0f)
	 {
		 retval.roots = 1;
	 }
	 else 
	 {
		 retval.roots = 2;
	 }

	return retval;
}

float lerp(float start, float end, float t)
{
	return start + t*(end - start);
	
}
//struct point { float x, y; };

float distance(point p1, point p2)
{
	return (sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.x - p1.y)*(p2.y - p1.y)));
}
float INNER(inner P1, inner q1)
{
	return (P1.x*q1.x) + (P1.y*q1.y) + (P1.z*q1.z);
}

float Point(Plane plane, Xoint point)
{
	return ((plane.a * point.x) + (plane.b * point.y) + (plane.c * point.z) + plane.d) / sqrt((plane.a*plane.a) + (plane.b * plane.b) + (plane.c*plane.c));
}

