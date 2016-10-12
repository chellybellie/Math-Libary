#pragma once
#include "vec-2.h"
#include "vec-3.h"
union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);


};
mat3 mat3identity();
mat3 transpose(const mat3 & m1);

bool operator==(const mat3 &m1, const mat3 &m2);
bool operator!=(const mat3 &m1, const mat3 &m2);
mat3 operator+(mat3 m1, const mat3 &m2);
mat3 operator-(mat3 m1, const mat3 &m2);
mat3 operator -(mat3 &mm1);

mat3 operator*(const mat3 &m1, float m2);
mat3 operator*(float m1, const mat3 &m2);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &B);
mat3 inverse(const mat3 &D);
float determinat(const mat3 &D);

mat3 scale(float w, float h);
mat3 translate(float x, float y);
mat3 rotation(float a);