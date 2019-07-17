#include"cg_math.h"
#define WIDTH 700
#define HEIGHT 700 
#define ColoredVertex(c, v) do{ glColor3fv(c); glVertex3fv(v); }while(0)
GLfloat angle = 0.0f;
void myDisplay(void)
{

	static int list = 0;
	if (list == 0)
	{
		// 如果显示列表不存在，则创建

		GLfloat

			PointA[] = { -0.5, -5 * sqrt(5) / 48, sqrt(3) / 6 },
			PointB[] = { 0.5, -5 * sqrt(5) / 48, sqrt(3) / 6 },
			PointC[] = { 0, -5 * sqrt(5) / 48, -sqrt(3) / 3 },
			PointD[] = { 0, 11 * sqrt(6) / 48, 0 };
		/*GLfloat
		PointA[] = { 0.5f, -sqrt(6.0f)/12, -sqrt(3.0f)/6},
		PointB[] = {-0.5f, -sqrt(6.0f)/12, -sqrt(3.0f)/6},
		PointC[] = { 0.0f, -sqrt(6.0f)/12, sqrt(3.0f)/3},
		PointD[] = { 0.0f, sqrt(6.0f)/4, 0};
		*/
		GLfloat

			ColorR[] = { 1, 0, 0 },
			ColorG[] = { 0, 1, 0 },
			ColorB[] = { 0, 0, 1 },
			ColorY[] = { 1, 1, 0 };

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glBegin(GL_TRIANGLES);
		// 平面ABC 
		ColoredVertex(ColorR, PointA);
		ColoredVertex(ColorG, PointB);
		ColoredVertex(ColorB, PointC);
		// 平面ACD
		ColoredVertex(ColorR, PointA);
		ColoredVertex(ColorB, PointC);
		ColoredVertex(ColorY, PointD);
		// 平面CBD 
		ColoredVertex(ColorB, PointC);
		ColoredVertex(ColorG, PointB);
		ColoredVertex(ColorY, PointD);
		// 平面BAD 
		ColoredVertex(ColorG, PointB);
		ColoredVertex(ColorR, PointA);
		ColoredVertex(ColorY, PointD);
		glEnd();
		glEndList();
		glEnable(GL_DEPTH_TEST);
	/*	glViewport(0, 0, 600, 600);*/

	}

	// 已经创建了显示列表，在每次绘制正四面体时将调用它 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glScaled(1.0,1.0,1.0);
	glRotatef(angle, 0, 1, 0);
	glTranslated(0,-0.15,0);
	glCallList(list);
	
	glPopMatrix();
	angle += 0.015f;
	glutSwapBuffers();
}

void rotate( ) {
	int argc = 0;
	const char* c[] = { "CG" };
		char **argv;
		argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL 窗口");
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);
	glutMainLoop();
}
/*void TextExample()
{
	rotate();
}*/