#pragma once
#include <cstring>
#include <cmath>

#include "vec2.h"

#define		TO_RAD(x)	(double)x*3.14/180

template <typename T>
class mat2
{
public:
	T m[3][3];
	mat2();
	mat2<T> operator *(mat2<T> M);
	vec2<T> operator *(vec2<T> V);
	mat2<T> friend translator(T x, T y);
	friend mat2<T> rotator(T t);
	friend mat2<T> reflector(bool X);
};

template <typename T>
mat2<T> translator(T x, T y)
{
	mat2<T> M;
	M.m[0][2] = x;
	M.m[1][2] = y;
	return M;
}

template <typename T>
mat2<T> rotator(T t)
{
	mat2<T> M;
	M.m[0][0] = (T)cos(TO_RAD(t));
	M.m[1][0] = (T)sin(TO_RAD(t));
	M.m[1][1] = M.m[0][0];
	M.m[0][1] = -M.m[1][0];
	return M;
}

template <typename T>
mat2<T> reflector(bool X)
{
	mat2<T> M;
	if (X) M.m[0][0] = -1;
	else M.m[1][1] = -1;
	return M;
}

template <typename T>
mat2<T>::mat2()
{
	memset(m, 0, sizeof(m));
	m[0][0] = m[1][1] = m[2][2] = 1;
}



template <typename T>
mat2<T> mat2<T>::operator *(mat2<T> M)
{
	mat2<T> res;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			res.m[i][j] = 0;
			for (int k = 0; k < 3; k++)
				res.m[i][j] += m[i][k] * M.m[k][j];
		}
	return res;
}

template <typename T>
vec2<T> mat2<T>::operator *(vec2<T> V)
{
	vec2<T> res;
	T a[3] = { V.X, V.Y, 1 };
	for (int i = 0; i < 3; i++)
	{
		res.X += m[0][i] * a[i];
		res.Y += m[1][i] * a[i];
	}
	return res;
}