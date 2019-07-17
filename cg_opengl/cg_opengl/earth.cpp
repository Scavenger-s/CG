#include"cg_math.h"
float fEarth = 2.0f; //地球绕太阳的旋转角度
float fMoon = 24.0f; //月球绕地球的旋转角度
void Init_earth()

{
	glEnable(GL_DEPTH_TEST); //启用深度测试
	glClearColor(0.0f, 0.0f, 0.0f, 0.8f); //背景为黑色
}

void Reshape_earth(int w, int h)

{
	if (0 == h)
		h = 1;

	glViewport(0, 0, w, h); //设置视区尺寸

	glMatrixMode(GL_PROJECTION); //指定当前操作投影矩阵堆栈

	glLoadIdentity(); //重置投影矩阵

					  //指定透视投影的观察空间

	gluPerspective(45.0f, (float)w / (float)h, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}

void Display_earth(void)

{

	//清除颜色和深度缓冲区

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //指定当前操作模型视图矩阵堆栈

	glLoadIdentity(); //重置模型视图矩阵

	glTranslatef(0.0f, 0.0f, -500.0f); //将图形沿z轴负向移动

	glColor3f(1.0f, 0.0f, 0.0f); //画太阳

	glutSolidSphere(50.0f, 20, 20);

	glColor3f(0.0f, 0.0f, 1.0f);

	glRotatef(23.27, 0.0, 0.0, 1.0); //地球与太阳的黄赤交角

	glRotatef(fEarth, 0.0f, 1.0f, 0.0f);

	glTranslatef(200.0f, 0.0f, 0.0f);

	glutSolidSphere(20.0f, 20, 20); //画地球

	glPopMatrix();

	glPopMatrix();

	glRotatef(6.0f, 1.0f, 1.0f, 1.0f);

	glRotatef(fMoon, 0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);

	glTranslatef(30.0f, 0.0f, 0.0f);

	glutSolidSphere(5.0f, 20, 20); //画月球

	glLoadIdentity();

	glFlush();

	glutSwapBuffers();

}

void myIdle(void) //在空闲时调用，达到动画效果

{

	fEarth += 0.013f; //增加旋转步长，产生动画效果

	if (fEarth > 360.0f)

		fEarth = 2.0f;

	fMoon += 0.024f;

	if (fMoon > 360.0f)

		fMoon = 24.0f;

	Display_earth();

}

void Textexample_earth()

{
	int argc = 0;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 400);
	glutCreateWindow("太阳系动画");
	glutReshapeFunc(Reshape_earth);
	glutDisplayFunc(Display_earth);
	glutIdleFunc(&myIdle);
	Init_earth();
	glutMainLoop();
}
void TextExample()
{
	Textexample_earth();
}