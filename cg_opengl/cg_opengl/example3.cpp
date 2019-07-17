#include"cg_math.h"
#define Windowwidth 5.0
#define Windowheight 5.0
#define Windowstart -5.0
#define Windowend -5.0
void init()
{
	glClearColor(0.8f, 0.8f, 0.8f, 0.6f);
}
void winReshapeFunc(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(Windowstart, Windowwidth, Windowend, Windowheight);
	glClear(GL_COLOR_BUFFER_BIT);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	vec2f point[3] = { {-1.0f,0.0f},{0.0f,1.0f},{1.0f,0.0f} };
	vec2f center1 = GetCenterPoint2D(point, 3);
	DrawPolygon2D(point,3,GL_POLYGON);
	Mat3f m;
	m= Mat3f::rotate2D(m, center1, 90.0);
	TranslatePoint2D(point, m, 3);
	glColor3f(1.0f,0.3f,0.3f);
	DrawPolygon2D(point, 3, GL_POLYGON);
	Mat3f n;
	n= Mat3f::transtlate2D(n, 0.0, 3.0);
	TranslatePoint2D(point,n,3);
	glColor3f(0.3, 0.5, 0.6f);
	DrawPolygon2D(point, 3, GL_POLYGON);
	vec2f center = GetCenterPoint2D(point,3);
	n = Mat3f::rotate2D(n, center, 30.0);
	TranslatePoint2D(point, n, 3);
	glColor3f(0.4,0.4,0.1);
	DrawPolygon2D(point, 3, GL_POLYGON);
	glFlush();
}
void Textexmple3()
{
	int argc = 1;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("h");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFunc);
	glutMainLoop();
}

