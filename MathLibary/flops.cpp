#include "flops.h"
#include <cmath>

bool fequals(float lhs, float rhs)
{
	if (abs(lhs - rhs) < 0.00001f)
		return true;
	else return false;
}
float deg2rad(float deg)
{
	return deg*3.1415926535  / 180;
}

float rad2deg(float rad)
{
	return rad * 180 / 3.1415926535;
}

float LinearHalf(float x)
{
	return 0.5f*x;
}
float growFast(float x)
{
	return x*x;
}

float growFaster(float x)
{
	return 1 - (1 - x)*(1 - x);
}

float TriBS(float x)
{
	return abs(2 * ((x)-1) + 1);
}
float bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float bounceflip(float x)
{
	return 1 - bounce(x);
}

float parabolaflip(float x)
{
	return -.5*(x - .5)*(x - .5) + .5;
}
float lerp(float start, float end, float alpha)
{
	return (1 - alpha)*start + (alpha)*end;

}
float quadBezier(float start, float mid, float end, float alpha)
{
	float mid1 = lerp(start, mid, alpha);
	float mid2 = lerp(mid, end, alpha);
	return lerp(mid1, mid2, alpha);
}
float hermitspline(float start, float end, float s_tan, float e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	float point = h00 * start + h10 * s_tan + h01 * end + h11 * e_tan;

	return point;
}
float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float tang0 = (mid - start) * tightness;
	float tang1 = (end - mid) * tightness;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	float point = h00 * start + h10 * tang0 + h01 * mid + h11 * tang1;
	return point;
}
float catRomSpline(float start, float mid, float end, float alpha)
{
	float tang0 = (mid - start) * .5;
	float tang1 = (end - mid) * .5;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	float point = h00 * start + h10 * tang0 + h01 * mid + h11 * tang1;
	return point;
}