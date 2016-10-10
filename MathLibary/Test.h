#pragma once

int donothing(int x);

float test_quad(float x);

struct quad_results

{
	float left_root, right_root;
	int roots;
};
quad_results quad(float a, float b, float c);



struct point { float x, y; };
float distance(point p1, point p2);

struct inner { float x, y, z; };
float INNER(inner P1, inner q1);

struct Plane { float a, b , c , d; };
struct Xoint { float x, y, z; };
float Point(Plane plane, Xoint point);

