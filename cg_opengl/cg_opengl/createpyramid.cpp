#include"cg_math.h"
//金字塔的五个顶点
float rtti=0;
int temp=1;


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
//      
void createplane(){

vec3f plane[4] = { { -1.-1,1 },
                   { 1,-1,1},
                   {1,-1,-1},
                   {-1,-1,-1} };
vec3f white[1] = { {1,1,1} };
       glBegin(GL_QUADS);
     colorvertex(white[0], plane[0]);
     colorvertex(white[0], plane[1]);
     colorvertex(white[0], plane[2]);
     colorvertex(white[0], plane[3]);
glEnd();
}
void createpyramid()
{
	
	vec3f vertices[5] = { {0,1,0},
                      {-1,-1,1},
                      {1,-1,1},
                      {1,-1,-1},
                      {-1,-1,-1} };
	vec3f color[4] = { {1,0,0},
				   {0,1,0} ,
                   {0,0,1},
                   {0.5,0.5,0.5} };
	glBegin(GL_TRIANGLES);
	//V012
	colorvertex(color[0],vertices[0]);
	colorvertex(color[1], vertices[1]);
	colorvertex(color[2], vertices[2]);
	//V023
	colorvertex(color[0], vertices[0]);
	colorvertex(color[2], vertices[2]);
	colorvertex(color[1], vertices[3]);
	//V034
	colorvertex(color[0], vertices[0]);
	colorvertex(color[2], vertices[3]);
	colorvertex(color[1], vertices[4]);
	//V041
	colorvertex(color[0], vertices[0]);
	colorvertex(color[2], vertices[4]);
	colorvertex(color[1], vertices[1]);
	glEnd();


	
}
void display()
{
	static float rtti = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();
	glPushMatrix();
	glTranslated(0, 0, -1);
	glScalef(0.25, 0.25, 0.25);
	glRotatef(rtti,0,1,0);
	createpyramid();
	/*glColor3f(0,0.0f,1);
	glutSolidTeapot(1);*/
	/*glColor3f(0.5,0.5,1);
	glutWireTeapot(1);*/
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	/*glTranslated(0.0,0,0.15);*/
	glRotated(30,1,0,0);
	glScaled(0.7,0.7,0.7);
	createplane();
	glPopMatrix();
	rtti += 0.008f;
	glutSwapBuffers();

}
void InitGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}
void reshape(int width,int height)
{
	glViewport(0,0,600,600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f,(GLfloat)width/(GLfloat)height,0.1,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void TextExample7()
{
	int argc=0; 
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(300,200);
	glutCreateWindow("example7");
	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
}
//void TextExample()
//{
//	TextExample7();
//}