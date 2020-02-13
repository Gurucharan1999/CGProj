#pragma once
#include <GL\glew.h>

#include "mat2.h"
#include "vec2.h"

extern void putPixel(int x, int y);

class Ellipse_
{
	vec2<int> C, P;
	float A;
public:
	Ellipse_(int x = 0, int y = 0, int a = 100, int b = 50, float th = 0) :C(vec2<int>(x, y)), P(vec2<int>(a, b)), A(th) {}
	void draw();
};

template <typename T> extern mat2<T> translator(T x, T y);
template <typename T> extern mat2<T> rotator(T t);