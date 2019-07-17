#include"cg_math.h"
#include <vector>
using namespace std;
struct Point {

	int x, y;

};
Point pt[4], bz[11];
vector<Point> vpt;
bool bDraw;
int nInput;
void CalcBZPoints()
{

	float a0, a1, a2, a3, b0, b1, b2, b3;

	a0 = pt[0].x;

	a1 = -3 * pt[0].x + 3 * pt[1].x;

	a2 = 3 * pt[0].x - 6 * pt[1].x + 3 * pt[2].x;

	a3 = -pt[0].x + 3 * pt[1].x - 3 * pt[2].x + pt[3].x;

	b0 = pt[0].y;

	b1 = -3 * pt[0].y + 3 * pt[1].y;

	b2 = 3 * pt[0].y - 6 * pt[1].y + 3 * pt[2].y;

	b3 = -pt[0].y + 3 * pt[1].y - 3 * pt[2].y + pt[3].y;

	float t = 0;

	float dt = 0.01;

	for (int i = 0; t<1.1; t += 0.1, i++)

	{

		bz[i].x = a0 + a1 * t + a2 * t*t + a3 * t*t*t;

		bz[i].y = b0 + b1 * t + b2 * t*t + b3 * t*t*t;

	}

}

void ControlPoint(vector<Point> vpt)

{

	glPointSize(2);

	for (int i = 0; i<vpt.size(); i++)

	{

		glBegin(GL_POINTS);

		glColor3f(1.0f, 0.0f, 0.0f); glVertex2i(vpt[i].x, vpt[i].y);

		glEnd();

	}

}

void PolylineGL(Point *pt, int num)

{

	glBegin(GL_LINE_STRIP);

	for (int i = 0; i<num; i++)

	{

		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2i(pt[i].x, pt[i].y);

	}

	glEnd();

}

void Display()

{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);

	if (vpt.size() > 0) {

		ControlPoint(vpt);

	}

	if (bDraw)

	{

		PolylineGL(pt, 4);

		CalcBZPoints();

		PolylineGL(bz, 11);

	}

	glFlush();

}

void Init()

{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);

	printf("Please Click left button of mouse to input control point of Bezier Curve!\n");

}

void Reshape(int w, int h)

{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

}

void mouse(int button, int state, int x, int y)

{

	switch (button)

	{

	case GLUT_LEFT_BUTTON:

		if (state == GLUT_DOWN)

		{

			if (nInput == 0)

			{

				pt[0].x = x;

				pt[0].y = 480 - y;

				nInput = 1;

				vpt.clear();

				vpt.push_back(pt[0]);

				bDraw = false;

				glutPostRedisplay();//

			}

			else if (nInput == 1)

			{

				pt[1].x = x;

				pt[1].y = 480 - y;

				vpt.push_back(pt[1]);

				nInput = 2;

				glutPostRedisplay();//

			}

			else if (nInput == 2)

			{

				pt[2].x = x;

				pt[2].y = 480 - y;

				vpt.push_back(pt[2]);

				nInput = 3;

				glutPostRedisplay();//

			}

			else if (nInput == 3)

			{

				pt[3].x = x;

				pt[3].y = 480 - y;

				bDraw = true;

				vpt.push_back(pt[3]);

				nInput = 0;

				glutPostRedisplay();//

			}

		}

		break;

	default:

		break;

	}

}

void Textexample()

{
	int argc = 0;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Hello World!");
	Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
}
//void TextExample()
//{
//	Textexample();
//}