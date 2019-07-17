#include"cg_math.h"
void createquare()
{
vec3f vertices[8] = { {1,1,-1},
                      {-1,1,-1},
                      {-1,1,1},
                      {1,1,1},
                      {1,-1,1},
                      {-1,-1,1},
                      {-1,-1,-1},
                      {1,-1,-1} };
vec3f color[4] = { { 1,0,0 },
	               { 0,1,0 } ,
	               { 0,0,1 },
	               { 0.5,0.5,0.5 } };


	glBegin(GL_QUADS);
	//0123
	colorvertex(color[0], vertices[0]);
	colorvertex(color[1], vertices[1]);
	colorvertex(color[2], vertices[2]);
	colorvertex(color[3], vertices[3]);
	//2345
	colorvertex(color[0], vertices[2]);
	colorvertex(color[1], vertices[3]);
	colorvertex(color[2], vertices[4]);
	colorvertex(color[3], vertices[5]);
	//1256
	colorvertex(color[0], vertices[1]);
	colorvertex(color[1], vertices[2]);
	colorvertex(color[2], vertices[5]);
	colorvertex(color[3], vertices[6]);
	//1076
	colorvertex(color[3], vertices[1]);
	colorvertex(color[1], vertices[0]);
	colorvertex(color[2], vertices[7]);
	colorvertex(color[0], vertices[6]);
	//5476
	colorvertex(color[0], vertices[5]);
	colorvertex(color[1], vertices[4]);
	colorvertex(color[2], vertices[7]);
	colorvertex(color[3], vertices[6]);
	//0347
	colorvertex(color[3], vertices[0]);
	colorvertex(color[2], vertices[3]);
	colorvertex(color[1], vertices[4]);
	colorvertex(color[0], vertices[7]);
	glEnd();
}
void display1()
{
	static float rtti = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(0.35,0.35,0.35);
	glRotated(rtti,0,1,0);
	createquare();
	rtti += 0.008f;
	glutSwapBuffers();

}
void Initwindow()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void reshape1(int width, int height)
{
	glViewport(0, 0, 600, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.1, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void TextExample8()
{
	int argc = 0;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("example8");
	Initwindow();
	glutDisplayFunc(display1);
	glutReshapeFunc(reshape1);
	glutIdleFunc(display1);
	glutMainLoop();
}
//void TextExample()
//{
//	TextExample8();
//}