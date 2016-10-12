#include "vec-3.h"
#include "matrix3.h"
#include "flops.h"
#include <cmath>

mat3 mat3identity()
{
	return mat3{ 1,0,0,
				 0,1,0,
				 0,0,1 };
}

mat3 transpose(const mat3 & idx)
{
	mat3 temp;

	temp.m[0] = idx.m[0];
	temp.m[1] = idx.m[3];
	temp.m[2] = idx.m[6];
	temp.m[3] = idx.m[1];
	temp.m[4] = idx.m[4];
	temp.m[5] = idx.m[7];
	temp.m[6] = idx.m[2];
	temp.m[7] = idx.m[5];
	temp.m[8] = idx.m[8];

	return temp;
}

bool operator==(const mat3 & m1, const mat3 & m2)
{
	return  fequals(m1.m[0], m2.m[0]) &&
			fequals(m1.m[1], m2.m[1]) &&
			fequals(m1.m[2], m2.m[2]) &&
			fequals(m1.m[3], m2.m[3]) &&
			fequals(m1.m[4], m2.m[4]) &&
			fequals(m1.m[5], m2.m[5]) &&
			fequals(m1.m[6], m2.m[6]) &&
			fequals(m1.m[7], m2.m[7]) &&
			fequals(m1.m[8], m2.m[8]);
}
bool operator!=(const mat3 & m1, const mat3 & m2)
{
	return  !fequals(m1.m[0], m2.m[0]) ||
			!fequals(m1.m[1], m2.m[1]) ||
			!fequals(m1.m[2], m2.m[2]) ||
			!fequals(m1.m[3], m2.m[3]) ||
			!fequals(m1.m[4], m2.m[4]) ||
			!fequals(m1.m[5], m2.m[5]) ||
			!fequals(m1.m[6], m2.m[6]) ||
			!fequals(m1.m[7], m2.m[7]) ||
			!fequals(m1.m[8], m2.m[8]);
}
mat3 operator+(mat3 m1, const mat3 & m2)
{
	return mat3{ m1.m[0] + m2.m[0], m1.m[1] + m2.m[1],
		m1.m[2] + m2.m[2], m1.m[3] + m2.m[3], m1.m[4] + m2.m[4],
		m1.m[5] + m2.m[5], m1.m[6] + m2.m[6], m1.m[7] + m2.m [7],
		m1.m[8] + m2.m[8]};
}
mat3 operator-(mat3 m1, const mat3 & m2)
{
	return mat3{ m1.m[0] - m2.m[0], m1.m[1] - m2.m[1],
		m1.m[2] - m2.m[2], m1.m[3] - m2.m[3], m1.m[4] - m2.m[4],
		m1.m[5] - m2.m[5], m1.m[6] - m2.m[6], m1.m[7] - m2.m[7],
		m1.m[8] - m2.m[8] };
}

mat3 operator-(mat3 & mm1)
{
	return mat3{ -mm1.m[0], -mm1.m[1], -mm1.m[2], -mm1.m[3],
				 -mm1.m[4], -mm1.m[5], -mm1.m[6], -mm1.m[7],
				 -mm1.m[8]};
}
mat3 operator*(const mat3 & m1, float m2)
{
	return mat3{ m1.m[0] * m2, m1.m[1] * m2, m1.m[2] * m2, m1.m[3] * m2,
				 m1.m[4] * m2, m1.m[5] * m2, m1.m[6] * m2, m1.m[7] * m2,
				 m1.m[8] *m2};
}
mat3 operator*(float m1, const mat3 &m2)
{
	return mat3{ m2.m[0] * m1, m2.m[1] * m1, m2.m[2] * m1, m2.m[3] * m1,
		m2.m[4] * m1, m2.m[5] * m1, m2.m[6] * m1, m2.m[7] * m1,
		m2.m[8] * m1 };
}
mat3 operator*(mat3 &A, const mat3 &B)
{
	return mat3{((A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2])),
				((A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[7] * B.m[2])),
				((A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2])),

				((A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5])),
				((A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5])),
				((A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5])),

				((A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8])),				
				((A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8])),
				((A.m[2] * B.m[6]) + (A.m[5] * B.m[7]) + (A.m[8] * B.m[8]))};
}
vec3 operator*(const mat3 & A, const vec3 & B)
{
	return vec3{
		((A.m[0] * B.x) + (A.m[3] * B.y) + (A.m[6] * B.z)),
		((A.m[1] * B.x) + (A.m[4] * B.y) + (A.m[7] * B.z)),
		((A.m[2] * B.x) + (A.m[5] * B.y) + (A.m[8] * B.z))};
}

mat3 inverse(const mat3 &D)
{
	return (1 / (determinat(D)) * transpose(D));
}

float determinat(const mat3 &D)
{
	return float((D.m[0] * D.m[4] * D.m[1]) + (D.m[3] * D.m[7] * D.m[2]) +
		  (D.m[6] * D.m[4] * D.m[8]) - (D.m[6] * D.m[4] * D.m[2]) -
		  (D.m[3] * D.m[1] * D.m[5]) - (D.m[0] * D.m[7] * D.m[5]));

}
mat3 scale(float w, float h)
{
	
	return mat3{ w,0,0,
				 0,h,0,
				 0,0,1};
}
mat3 translate(float x, float y)
{
	return mat3{ 0,0,x,
				 0,0,y,
				 0,0,1};
}
mat3 rotation(float a)
{
	return mat3{  cos(a), sin(a), 0,
				 -sin(a), cos(a), 0,
				  0     , 0     , 1};
}
vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}
vec3 &mat3::operator[](unsigned idx)
{
	return c[idx];
}