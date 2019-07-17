#include"cg_math.h"
//#include<gl/glut.h>
#define Windowwidth 480.0
#define Windowheight 640.0
#define Windowstart 0.0
#define Windowend 0.0
#define LEFT_EDGE 1
#define RIGHT_EDGE 2
#define TOP_EDGE 8
#define BOTTOM_EDGE 4
int x00, y00, x11, y11;
//结构体
typedef struct
{
	float xmin, ymin, xmax, ymax;
}Rectangle;
Rectangle rect;
int CompCode(int x,int y, Rectangle rect)
{
	int code = 0x00;
	if (y < rect.ymin)
		//4=0100；0000|0100
		code = code | 4;
	if (y > rect.ymax)
		//8=1000
		code = code | 8;
	if (x < rect.xmin)
		//1=0001
		code = code | 1;
	if (x > rect.xmax)
		//2=0010
		code = code | 2;
	return code;
}
//引用传参类似指针
int Lineclip(Rectangle rect,int &x0,int &y0,int &x1,int &y1)
{
	int accept=0; 
	int done=0;
	float x, y;
	int code0, code1, codeout;
	code0 = CompCode(x0,y0,rect);
	code1= CompCode(x1, y1, rect);
	do
	{
		//直线两点都在矩形内
		if (!(code0 | code1))
		{
			accept = 1;
			done = 1;
		}
		//两点在矩形外
		else if (code0&code1)
			done = 1;
		//一点在，一点不在矩形内
		else
		{
			//起点不在矩形内，code2在
			if (code0 != 0)
				codeout = code0;
			//终点不在矩形内
			else
				codeout = code1;
			//codeout=(矩形外的点)
			//codeout在矩形左边
			if (codeout&LEFT_EDGE)
			{
				y = y0 + (y1 - y0)*(rect.xmin - x0) / (x1 - x0);
				x = (float)rect.xmin;
			}
			else if (codeout&RIGHT_EDGE)
			{
				y = y0 + (y1 - y0)*(rect.xmax - x0) / (x1 - x0);
				x = (float)rect.xmax;
			}
			else if (codeout&BOTTOM_EDGE)
			{
				x = x0 + (x1 - x0)*(rect.ymin - y0) / (y1 - y0);
				y = (float)rect.ymin;
			}
			else if (codeout&TOP_EDGE)
			{
				x = x0 + (x1 - x0)*(rect.ymax - y0) / (y1 - y0);
				y = (float)rect.ymax;
			}
			//起点在矩形外
			if (codeout == code0) {
				x0 = x;
				y0 = y;
				code0 = CompCode(x0, y0, rect);
			}
			else {
				x1 = x;
				y1 = y;
				code1 = CompCode(x1, y1, rect);
			}
		}
	} while(!done);
	if (accept) {
		vec2i point[2] = { {x0,y0},{x1,y1} };
		glColor3f( 0.0,0, 1.0);
		/*DrawLine(point);*/
		/*glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f); glVertex2f(x0, y0);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(x1, y1);
		glEnd();*/
		//DrawCircle(5,0,0);
		cout << "Drawline函数调用" << endl;
	}
	return accept;
}
void init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glShadeModel(GL_FLAT);
	rect.xmin = rect.ymin = 100;
	rect.xmax = rect.ymax = 300;
	x00 = 450;
	y00 = 0;
	x11 = 0;
	y11 = 450;
}
void winReshapeFunc(int w, int h)
{
	glViewport(0, 0,  (GLsizei)w, (GLsizei)h);	
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)w,0,(GLdouble)h);
}
void keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'c':
	case 'C':

		Lineclip(rect, x00, y00, x11, y11);
		glutPostRedisplay();
		break;
	case 'r':
	case 'R':
		init();
		glutPostRedisplay();
		break;
	case 'X':
	case 'x':
		exit(0);
		break;
	default:
		break;
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,0.0,1.0);
	////长方形左下右上点坐标
	vec2i point[2] = { {100,100},{300,300} };
	glRectf(point[0].X,point[0].Y,point[1].X,point[1].Y);
	////////线的颜色
	glColor3f(1.0f,0.0f,0.0f);
	//两顶点坐标
	vec2i point11[2] = { { 450,0 },{ 0,450 } };
	//画线函数
	//DrawLine(point11);
	glFlush();
}
void Textexmple4()
{
	int argc = 1;
	// const char *转换为 char**
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("h");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFunc);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}