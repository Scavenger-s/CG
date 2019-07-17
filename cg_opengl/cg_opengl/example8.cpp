#include"cg_math.h"
GLfloat x = 0.0;

GLfloat y = 0.0;

GLfloat sizei = 50.0;

GLsizei wh = 500, ww = 500;

void drawSquare(GLint x, GLint y) {

	y = wh - y;

	glBegin(GL_POLYGON);
	glVertex3f(x + sizei, y + sizei, 0);
	glVertex3f(x - sizei, y + sizei, 0);
	glVertex3f(x - sizei, y - sizei, 0);
	glVertex3f(x + sizei, y - sizei, 0);
	glEnd();
}

void mydisplay()

{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	drawSquare(x, y);

	glutSwapBuffers();

	glutPostRedisplay();

}

void init()

{

	glClearColor(0.0, 0.0, 0.0, 1.0);

}

void myreshape(GLint w, GLint h) {

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	ww = w;

	wh = h;

}

void mymouse(GLint button, GLint state, GLint wx, GLint wy)

{

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)

		exit(0);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

	{

		x = wx;

		y = wy;

	}

}

void Textexample_interactive()

{
	int argc = 0;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("double");
	init();
	glutDisplayFunc(mydisplay);
	glutReshapeFunc(myreshape);
	glutMouseFunc(mymouse);
	glutMainLoop();
}
//void TextExample()
//{
//	Textexample_interactive();
//}