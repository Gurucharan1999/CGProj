#pragma once
#include <cstring>
#include <cmath>

#include "vec2.h"

#define		TO_RAD(x)	(double)x*3.14/180

template <typename T>
class mat2
{
	T m[3][3];
public:
	mat2();
	mat2 operator *(mat2 M);
	vec2<T> operator *(vec2<T> V);
};

template <typename T> mat2<T> translator(T x, T y);
template <typename T> mat2<T> rotator(T t);
template <typename T> mat2<T> reflector(bool X);