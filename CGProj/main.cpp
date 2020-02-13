#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "Ellipse_.h"
#include "mat2.h"
#include "vec2.h"

#define		TO_RAD(x)	(float)x*3.14/180

using namespace std;

/*
void bressenhamLine(int x1, int y1, int x2, int y2)
{
	int del_x, del_y, sign;
	if(x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	del_x = x2 - x1;
	del_y = y1 <= y2 ? y2 - y1 : y1 - y2;
	sign = y1 <= y2 ? 1 : -1;
	if(del_x > del_y)
	{
		int d = del_x, y = y1;
		for(int x = x1; x <= x2; x++)
		{
			putPixel(x, y);
			if(d < 0)
			{
				y += sign;
				d += 2*(del_x - del_y);
			}
			else
				d -= 2*del_y;
		}
	}
	else
	{
		int d = -del_y, x = x1;
		bool b = sign == 1 ? y1 <= y2 : y1 >= y2;
		for(int y = y1; b; y += sign)
		{
			putPixel(x, y);
			if(d < 0)
			{
				x++;
				d += 2*(del_y - del_x);
			}
			else
				d -= 2*del_x;
			b = sign == 1 ? y <= y2 : y >= y2;
		}
	}
}

void bressenhamArc(int a, int b, int r, int t1, int t2, bool larger)
{
	int d = 1 - r, x = 0, y = r;
	if(t1 > t2)
		swap(t1, t2);
	int t = (t1 + t2)/2;
	int A = t2 - t;
	while(x <= y)
	{
		for(int i = 0; i < 4; i++)
		{
			int m = 1 - 2*((i/2)%2), n = 1 - 2*(i%2);
			bool p, q;
			p = (-r*sin(TO_RAD(A)) <= n*y) && (r*sin(TO_RAD(A)) >= n*y) && (r*cos(TO_RAD(A)) <= m*x) && (r >= m*x);
			q = (-r*sin(TO_RAD(A)) <= n*x) && (r*sin(TO_RAD(A)) >= n*x) && (r*cos(TO_RAD(A)) <= m*y) && (r >= m*y);
			if(p ^ larger) putPixel(a + m*x*cos(TO_RAD(t)) - n*y*sin(TO_RAD(t)), b + m*x*sin(TO_RAD(t)) + n*y*cos(TO_RAD(t)));
			if(q ^ larger) putPixel(a + m*y*cos(TO_RAD(t)) - n*x*sin(TO_RAD(t)), b + m*y*sin(TO_RAD(t)) + n*x*cos(TO_RAD(t)));
		}
		if(d <= 0)
			d += 2*x + 3;
		else
		{
			y = y - 1;
			d += 2*x - 2*y + 5;
		}
		x++;
	}
}
*/

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Ellipse_ E(100, 100, 80, 50, 45);
	E.draw();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Set the window size
	glutInitWindowSize(500, 500);
	//glutInitWindowPosition(100, 100);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Bressenham");
	// Bind the two functions (above) to respond when necessary
	init();
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}