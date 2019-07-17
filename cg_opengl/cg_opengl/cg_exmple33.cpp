#include"cg_math.h"
#define Windowwidth 5.0
#define Windowheight 5.0
#define Windowstart -5.0
#define Windowend -5.0
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
void displayfcn()
{
	glClear(GL_COLOR_BUFFER_BIT);
	vec2f point[3] = { {-2.0f,0.0f},{0.0f,2.0f},{2.0f,0.0f} };
	glColor3f(0.0,1.0,0.0);
	DrawPolygon2D(point,3,GL_POLYGON);
	Mat3f m,n;
	vec2f centerpoint = GetCenterPoint2D(point,3);
	n.transtlate2D(0.0,2.0);
    TranslatePoint2D(point,n,3);
	vec2f centerpoint1 = GetCenterPoint2D(point, 3);
	m.rotate2D(centerpoint1,90);
	TranslatePoint2D(point, m, 3);
	glColor3f(0.0, 1.0, 1.0);
	DrawPolygon2D(point, 3, GL_POLYGON);
	glFlush();
}
void winReshapeFunc(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(Windowstart, Windowwidth, Windowend, Windowheight);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Textexmple333()
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
	glutDisplayFunc(displayfcn);
	glutReshapeFunc(winReshapeFunc);
	glutMainLoop();
}