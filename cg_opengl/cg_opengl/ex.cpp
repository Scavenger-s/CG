#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#define Windowwidth 480.0
#define Windowheight 640.0
#define Windowstart 0.0
#define Windowend 0.0
#define LEFT_EDGE 1
#define RIGHT_EDGE 2
#define TOP_EDGE 8
#define BOTTOM_EDGE 4
struct Rectangle
{
	float xmin, xmax, zmin, zmax;
};
Rectangle rect;
int x0, z0, x1, z1;

void LineGL4(int x0, int z0, int x1, int z1)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(x0, z0);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(x1, z1);
	glEnd();
}

int CompCode4(int x, int z, Rectangle rect)
{
	int code = 0x00;
	if (z < rect.zmin)
		code = code | 4;
	if (z > rect.zmax)
		code = code | 8;
	if (x > rect.xmax)
		code = code | 2;
	if (x < rect.xmin)
		code = code | 1;
	return code;
}

int cohensutherlandlineclip4(Rectangle rect, int &x0, int &z0, int &x1, int&z1)
{
	int accept, done;
	float x, z;
	accept = 0;
	done = 0;

	int code0, code1, codeout;
	code0 = CompCode4(x0, z0, rect);
	code1 = CompCode4(x1, z1, rect);
	do {
		if (!(code0 | code1))
		{
			accept = 1;
			done = 1;
		}
		else if (code0 & code1)
			done = 1;
		else
		{
			if (code0 != 0)
				codeout = code0;
			else
				codeout = code1;

			if (codeout&LEFT_EDGE) {
				z = z0 + (z1 - z0)*(rect.xmin - x0) / (x1 - x0);
				x = (float)rect.xmin;
			}
			else if (codeout&RIGHT_EDGE) {
				z = z0 + (z1 - z0)*(rect.xmax - x0) / (x1 - x0);
				x = (float)rect.xmax;
			}
			else if (codeout&BOTTOM_EDGE) {
				x = x0 + (x1 - x0)*(rect.zmin - z0) / (z1 - z0);
				z = (float)rect.zmin;
			}
			else if (codeout&TOP_EDGE) {
				x = x0 + (x1 - x0)*(rect.zmax - z0) / (z1 - z0);
				z = (float)rect.zmax;
			}

			if (codeout == code0)
			{
				x0 = x; z0 = z;
				code0 = CompCode4(x0, z0, rect);
			}
			else
			{
				x1 = x; z1 = z;
				code1 = CompCode4(x1, z1, rect);
			}
		}
	} while (!done);

	if (accept)
		LineGL4(x0, z0, x1, z1);
	return accept;
}

void init4()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	rect.xmin = 100;
	rect.xmax = 300;
	rect.zmin = 100;
	rect.zmax = 300;

	x0 = 450, z0 = 0, x1 = 0, z1 = 450;
	printf("Press key 'c' to Clip!\nPress key 'r' to Restore!\n");
}

void Reshape4(int w, int h)
{
	glViewport(0, 0, 600, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600, 0.0, 600);
}

void keyboard4(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'c':
		cohensutherlandlineclip4(rect, x0, z0, x1, z1);
		glutPostRedisplay();
		break;
	case 'r':
		init4();
		glutPostRedisplay();
		break;
	case'x':
		exit(0);
		break;
	default:
		break;
	}
}
void renderLab4() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(rect.xmin, rect.zmin, rect.xmax, rect.zmax);

	LineGL4(x0, z0, x1, z1);

	glFlush();
}

int main(int argc,char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Hello Dengqiuye");
	init4();
	glutDisplayFunc(renderLab4);
	glutReshapeFunc(Reshape4);
	glutKeyboardFunc(keyboard4);
	glutMainLoop();
}
