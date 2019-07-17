#include"cg_math.h"
//正方体的八个顶点
float rtti = 0;
//vec3d vertices[4] = { { -0.5, (-5 * sqrt(5) / 48), sqrt(3) / 6 },
//                      { 0.5, (-5 * sqrt(5) / 48), sqrt(3) / 6 }, 
//                      { 0, (-5 * sqrt(5) / 48), -sqrt(3) / 3 } ,
//					  { 0, (11 * sqrt(6) / 48), 0 } };

//GLfloat points[5][3] = { {0,1,0},
//                         {-0.5,-0.5,0.5},
//                         {0.5,-0.5,0.5},
//                         {0.5,-0.5,-0.5},
//                         {-0.5,-0.5,-0.5} };
//GLfloat color[4][3] = { {1,0,0},
//                        {0,1,0},
//                        {0,0,1},
//                        {1,1,0} };
//int vertice0[4][3] = { {0,1,2},
//                       {0,2,3},
//                       {0,3,4},
//                       {0,4,1} };
void createcube()
{
	vec3f vertices[8] = { { 1,1,-1 },
                      { -1,1,-1 },
                      { -1,1,1 },
                      { 1,1,1 },
                      { 1,-1,1 },
                      { -1,-1,1 },
                      { -1,-1,-1 },
                      { 1,-1,-1 } };
	vec3f color[4] = { { 1,0,0 },
{ 0,1,0 } ,
{ 0,0,1 },
{ 0.5,0.5,0.5 } };
	glBegin(GL_QUADS);
	//V0123
	colorvertex(color[0], vertices[0]);
	colorvertex(color[1], vertices[1]);
	colorvertex(color[2], vertices[2]);
	colorvertex(color[3], vertices[3]);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glTranslated(0, 0, -1);
	glScalef(0.25, 0.25, 0.25);
	glRotatef(rtti, 0, 1, 0);
	createcube();
	/*glColor3f(0, 0.0f, 1);*/
	/*glutSolidTeapot(1);
	glColor3f(0.5, 0.5, 1);
	glutWireTeapot(1);*/
	glPopMatrix();
	rtti += 0.08f;
	glutSwapBuffers();
}
void InitGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void reshape(int width, int height)
{
	glViewport(0, 0, 600, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.1, 100.0f);*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void TextCreateCube()
{
	int argc = 0;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("example7");
	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
}
void TextExample()
{
	void TextCreateCube();
}