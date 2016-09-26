#pragma once

int donothing(int x);

float test_quad(float x);

struct quad_results

{
	float left_root, right_root;
	int roots;
};
quad_results quad(float a, float b, float c);

float lerp(float start, float end, float t);

struct point { float x, y; };
float distance(point p1, point p2);