#pragma once

template <class T>
class vec2
{
public:
	T X, Y;
	vec2() :X(0), Y(0) {}
	vec2(T x, T y) :X(x), Y(y) {}
};

