#include "matrix2.h"
#include <cmath>
#include "flops.h"



mat2 mat2identity()
{
	return mat2();
}

mat2 transpose(const mat2 & idx)
{
	mat2 retval = idx;


	retval.mm[1][0] = idx.mm[0][1];
	retval.mm[0][1] = idx.mm[1][0];

	return idx;
}

bool operator==(const mat2 & m1, const mat2 & m2)
{
	return  fequals(m1.m[0], m2.m[0]) &&
			fequals(m1.m[1], m2.m[1]) &&
			fequals(m1.m[2], m2.m[2]) &&
			fequals(m1.m[3], m2.m[3]);
}

bool operator!=(const mat2 & m1, const mat2 & m2)
{
	return  !fequals(m1.m[0], m2.m[0]) ||
			!fequals(m1.m[1], m2.m[1]) ||
			!fequals(m1.m[2], m2.m[2]) ||
			!fequals(m1.m[3], m2.m[3]);

}

mat2 operator+(mat2 m1, const mat2 & m2)
{
	return mat2{ m1.m[0] + m2.m[0], m1.m[1] + m2.m[1],
				 m1.m[2] + m2.m[2], m1.m[3] + m2.m[3]};
}

mat2 operator-(mat2 m1, const mat2 & m2)
{
	return mat2{ m1.m[0] - m2.m[0], m1.m[1] - m2.m[1],
		m1.m[2] - m2.m[2], m1.m[3] - m2.m[3] };
}


mat2 operator-(mat2 & mm1)
{
	return mat2{ -mm1.m[0], -mm1.m[1], -mm1.m[2], -mm1.m[3]};
}

mat2 operator*(const mat2 & m1, float m2)
{
	return mat2{ m1.m[0] * m2, m1.m[1] * m2, m1.m[2] * m2, m1.m[3] * m2 };
}

mat2 operator*(float m1, const mat2 & m2)
{
	return mat2{ m2.m[0] * m1, m2.m[1] * m1, m2.m[2] * m1, m2.m[3] * m1 };
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	return mat2
	  { ((A.m[0] * B.m[0]) + (A.m[2] * B.m[1])),
		((A.m[0] * B.m[2]) + (A.m[2] * B.m[3])),
		((A.m[1] * B.m[0]) + (A.m[3] * B.m[2])),
		((A.m[1] * B.m[2]) + (A.m[3] * B.m[3])) };
}


vec2 operator*(const mat2 & A, const vec2 & B)
{
	return vec2{
		((A.m[0] * B.x) + (A.m[1] * B.y)),
		((A.m[2] * B.x) + (A.m[3] * B.y)),
	};
}

mat2 inverse(const mat2 &D)
{
	mat2 temp;
	temp.m[0] = temp.m[3];
	temp.m[1] = -temp.m[1];
	temp.m[2] = -temp.m[2];
	temp.m[3] = temp.m[0];
	return (1 / (determinat(D)) * temp );
}
float determinat(const mat2 &D)
{
	return  (D.m[0] * D.m[3]) - (D.m[1] * D.m[2]);
}
vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}
vec2 &mat2::operator[](unsigned idx)
{
	return c[idx];
}