#include"cg_math.h"
class wcPt2D
{
public:
	GLfloat x, y;
	void setCoords(GLfloat xCoord, GLfloat yCoord)
	{
		x = xCoord;
		y = yCoord;
	}
	GLfloat getx()  const { return x; }
	GLfloat gety()  
	{ 
		return y; 
	}
};

inline int Round(const GLfloat a) 
{ 
	return int(a + 0.5); 
}

void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
void lineBres(GLfloat x0, GLfloat y0, GLfloat xEnd, GLfloat yEnd)
{
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	if (x0>xEnd)
	{
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	setPixel(x, y);
	while (x < xEnd)
	{
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}
		setPixel(x, y);
	}
}

GLint clipTest(GLfloat p, GLfloat q, GLfloat *u1, GLfloat *u2)
{
	GLfloat r;
	GLint returnValue = true;
	if (p < 0.0)
	{
		r = q / p;
		if (r > *u2)
			returnValue = false;
		else
			if (r > *u1)
				*u1 = r;
	}
	else
		if (p > 0.0) {
			r = q / p;
			if (r < *u1)
				returnValue = false;
			else if (r < *u2)
				*u2 = r;
		}
		else
			if (q < 0.0)
				returnValue = false;
	return(returnValue);
}
void lineClipLiangBarsk(wcPt2D  winMin, wcPt2D  winMax, wcPt2D p1, wcPt2D p2)
{
	GLfloat u1 = 0.0, u2 = 1.0, dx = p2.getx() - p1.getx(), dy;
	GLfloat x1 = p1.getx();
	float y1 = p1.gety();
	GLfloat x2 = p2.getx();
	float y2 = p2.gety();
	if (clipTest(-dx, p1.getx() - winMin.getx(), &u1, &u2))
		if (clipTest(dx, winMax.getx() - p1.getx(), &u1, &u2))
		{
			dy = p2.gety() - p1.gety();
			if (clipTest(-dy, p1.gety() - winMin.gety(), &u1, &u2))
			{
				if (clipTest(dy, winMax.gety() - p1.gety(), &u1, &u2))
				{
					if (u2 < 1.0)
					{
						p2.setCoords(p1.getx() + u2 * dx, p1.gety() + u2 * dy);
					}
					if (u1 > 0.0)
					{
						p1.setCoords(p1.getx() + u1 * dx, p1.gety() + u1 * dy);
					}
					glColor3f(0.0, 0.0, 0.0);
					lineBres(x1, y1, p1.getx(), p1.gety());
					lineBres(p2.getx(), p2.gety(), x2, y2);
					glColor3f(1.0, 0.0, 0.0);
					lineBres(p1.getx(), p1.gety(), p2.getx(), p2.gety());
				}
			}
			else {
				glColor3f(0.0, 0.0, 0.0);
				lineBres(x1, x2, y1, y2);
			}
		}
}
void displayliangyoudongcaijian()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(100, 100);
	glVertex2i(100, -100);
	glVertex2i(-100, -100);
	glVertex2i(-100, 100);
	glEnd();
	glPointSize(4);
	wcPt2D test1[4] = { { -100.0,-100.0 },{ 100.0,100.0 },{
		-150.0,-200.0 },{ 200.0,120.0 } };
	wcPt2D test2[4] = { { -100.0,-100.0 },{ 100.0,100.0 },{
		-150.0,120.0 },{ 0.0,0.0 } };
	wcPt2D test3[4] = { { -100.0,-100.0 },{ 100.0,100.0 },{
		-150.0,50.0 },{ 150.0,150.0 } };
	wcPt2D test4[4] = { { -100.0,-100.0 },{ 100.0,100.0 },{
		-50.0,0.0 },{ 60.0,50.0 } };
	wcPt2D test5[4] = { { -100.0,-100.0 },{ 100.0,100.0 },{
		-170.0,-200.0 },{ 200.0,-120.0 } };
	lineClipLiangBarsk(test1[0], test1[1], test1[2], test1[3]);
	lineClipLiangBarsk(test2[0], test2[1], test2[2], test2[3]);
	lineClipLiangBarsk(test3[0], test3[1], test3[2], test3[3]);
	lineClipLiangBarsk(test4[0], test4[1], test4[2], test4[3]);
	lineClipLiangBarsk(test5[0], test5[1], test5[2], test5[3]);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);   //初始化GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("梁友栋裁剪算法");
	init();
	glutDisplayFunc(displayliangyoudongcaijian);   //回调函数
	glutMainLoop();    //持续显示，当窗口改变会重新绘制图形
}