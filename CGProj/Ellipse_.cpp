#include "Ellipse_.h"

void Ellipse_::draw()
{
	int a = P.X, b = P.Y;
	int d = b * (b - a * a), x = 0, y = b;
	mat2<float> R = rotator(A), T = translator((float)C.X, (float)C.Y);
	while (b * b * x <= a * a * y)
	{
		for (int i = 0; i < 4; i++)
		{
			vec2<float> V((1 - 2 * ((i / 2) % 2)) * x, (1 - 2 * (i % 2)) * y);
			V = T * R * V;
			putPixel((int)V.X, (int)V.Y);
		}
		if (d <= 0)
			d += b * b * (2 * x + 3);
		else
		{
			y = y - 1;
			d += b * b * (2 * x + 3) - 2 * a * a * (y - 1);
		}
		x++;
	}
	d = a * (a - b * b);
	x = a;
	y = 0;
	while (b * b * x > a* a* y)
	{
		for (int i = 0; i < 4; i++)
		{
			vec2<float> V((1 - 2 * ((i / 2) % 2)) * x, (1 - 2 * (i % 2)) * y);
			V = T * R * V;
			putPixel((int)V.X, (int)V.Y);
		}
		if (d <= 0)
			d += a * a * (2 * y + 3);
		else
		{
			x = x - 1;
			d += a * a * (2 * y + 3) - 2 * b * b * (x - 1);
		}
		y++;
	}
}