#include "Circle_.h"

void putPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void Circle_::draw()
{
	int d = 1 - R, x = 0, y = R;
	while (x <= y)
	{
		for (int i = 0; i < 4; i++)
		{
			putPixel(C.X + (1 - 2 * ((i / 2) % 2)) * x, C.Y + (1 - 2 * (i % 2)) * y);
			putPixel(C.X + (1 - 2 * ((i / 2) % 2)) * y, C.Y + (1 - 2 * (i % 2)) * x);
		}
		if (d <= 0)
			d += 2 * x + 3;
		else
		{
			y = y - 1;
			d += 2 * x - 2 * y + 5;
		}
		x++;
	}
}