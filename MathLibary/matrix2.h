#pragma once
#include "vec-2.h"

union mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];

	vec2 operator[](unsigned idx) const;
	vec2 &operator[](unsigned idx);

	
};
mat2 mat2identity();
mat2 transpose(const mat2 & m1);

bool operator==(const mat2 &m1, const mat2 &m2);
bool operator!=(const mat2 &m1, const mat2 &m2);
mat2 operator+(mat2 m1, const mat2 &m2);
mat2 operator-(mat2 m1, const mat2 &m2);
mat2 operator -( mat2 &mm1);

mat2 operator*(const mat2 &m1, float m2);
mat2 operator*(float m1, const mat2 &m2);
mat2 operator*( mat2 &A, const mat2 &B);
mat2 operator*( mat2 &A, const vec2 &B);
mat2 inverse(const mat2 &D);
float determinat(const mat2 &D);
