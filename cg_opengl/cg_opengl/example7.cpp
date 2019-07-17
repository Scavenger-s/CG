#include"cg_math.h"
#include<stdlib.h>
void init_light(void)

{

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat mat_shininess[] = { 50.0 };

	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

	float Light_Model_Ambient[4] = { 0.2 , 0.2 , 0.2 , 1.0 }; 

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient); 
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display_teapot(void)

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static float theta = 0;
	static float a = 0;
	static GLfloat light_position[] = { 1.0,a,1.0,0 };
	glLoadIdentity();
	glRotatef(theta,0,1,0);
	glutSolidTeapot(0.7);
	theta += 0.05f;
	a += 0.005;
	glutSwapBuffers();
}
void display_sphere(void)

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static float theta = 0;
	static float a = 0;
	glLoadIdentity(); 
	 static GLfloat light_position[] = { 1.0,a,1.0,0 };
	 glPushMatrix();
	glRotatef(theta,0,1,0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glutSolidSphere (1.0, 20, 16);
	glPopMatrix();
	theta += 0.01f;
	if (a > 1.0)
		a = 0;
	else
		a += 0.01;
	glutSwapBuffers();

}

void reshape_light(int w, int h)

{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h)

		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w,

			1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);

	else

		glOrtho(-1.5*(GLfloat)w / (GLfloat)h,

			1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}
void Textexample_light()

{
	int argc = 0;
	const char* c[] = { "CG" };
	char **argv;
	argv = const_cast<char**>(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init_light();
	//²èºø
	glutDisplayFunc(display_teapot);
	glutIdleFunc(display_teapot);
	//Çò
	/*glutDisplayFunc(display_sphere);
	glutIdleFunc(display_sphere);*/
	glutReshapeFunc(reshape_light);
	
	
	glutMainLoop();
}
void TextExample()
{
	Textexample_light();
}