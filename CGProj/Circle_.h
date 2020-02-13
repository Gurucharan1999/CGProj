#pragma once
#include <GL\glew.h>

#include "vec2.h"

class Circle_
{
	vec2<int> C;
	int R;
public:
	Circle_(int x, int y, int r) :C(vec2<int>(x, y)), R(r) {}
	void draw();
};