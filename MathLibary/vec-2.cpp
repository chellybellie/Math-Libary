#include "vec-2.h"
#include "flops.h"
#include <cmath>

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}
vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x * rhs.x, lhs.y * rhs.y };
}

vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x / rhs.x, lhs.y / rhs.y };
}


vec2 operator*(const vec2 & rhs, float lhs)
{
	return  vec2{ rhs.x *lhs, rhs.y * lhs };
}

vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}

vec2 operator/(float lhs, const vec2 & rhs)
{
	return vec2{ rhs.x / lhs, rhs.y / lhs };
}
 

vec2 operator-(const vec2 & v)
{
	return vec2{ -v.x , -v.y };
}


vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}
vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs * rhs ;
}

vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs / rhs;
}


bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator!=(const vec2 &lhs, const vec2 &rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}

float magnitude(const vec2 & v)
{
	return (sqrt((v.x*v.x) + (v.y * v.y)));
}

vec2 normal(const vec2 & v)
{
	return (v / (magnitude(v)));
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
    return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
    return acos(dot(normal(rhs), normal(lhs)));
}

vec2 perp(const vec2 & v)
{
    return vec2{v.y, -v.x};
}

float angle(const vec2 & v)
{
    return atan2f(v.y,v.x);
}
vec2 fromangle(float a)
{
	return vec2{ cos(a), sin(a) };
}
vec2 lerp( vec2 &start, vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);
	return retval;

}
vec2 quadBezier(vec2 &start, vec2 &mid, vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = quadBezier(start.x, mid.x, end.x, alpha);
	retval.y = quadBezier(start.y, mid.y, end.y, alpha);
	return retval;
}
vec2 hermitspline(vec2 &start, vec2 &end, vec2 &s_tan, vec2 &e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	vec2 point = h00 * start + h10 * s_tan + h01 * end + h11 * e_tan;

	return point;
}
vec2 cardinalSpline(vec2 &start, vec2 &mid, vec2 &end, vec2 &tightness, float alpha)
{
	vec2 tang0 = (mid - start) * tightness;
	vec2 tang1 = (end - mid) * tightness;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	vec2 point = h00 * start + h10 * tang0 + h01 * mid + h11 * tang1;
	return point;
}
vec2 catRomSpline(vec2 &start, vec2 &mid, vec2 &end, float alpha)
{
	vec2 tang0 = (mid - start) * .5;
	vec2 tang1 = (end - mid) * .5;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	vec2 point = h00 * start + h10 * tang0 + h01 * mid + h11 * tang1;
	return point;
}

