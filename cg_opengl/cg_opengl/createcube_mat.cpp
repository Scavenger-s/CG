#include"cg_math.h"
float angle11 = 0;
//正方体的八个顶点
void createcube(vec3f*vertices) {
	//四个顶点颜色
	vec3f color[4] = { { 1,0,0 },
	{ 0,1,0 } ,
	{ 0,0,1 },
	{ 0.5,0.5,0.5 } };
	glBegin(GL_QUADS);
	//v0123
	colorvertex(color[0], vertices[0]);
	colorvertex(color[1], vertices[1]);
	colorvertex(color[2], vertices[2]);
	colorvertex(color[3], vertices[3]);
	//v1256
	colorvertex(color[0], vertices[1]);
	colorvertex(color[1], vertices[2]);
	colorvertex(color[2], vertices[5]);
	colorvertex(color[3], vertices[6]);

}
void display() {
	//正方体的八个顶点
	vec3f vertices[8] = { { 1,1,-1 },
	{ -1,1,-1 },
	{ -1,1,1 },
	{ 1,1,1 },
	{ 1,-1,1 },
	{ -1,-1,1 },
	{ -1,-1,-1 },
	{ 1,-1,-1 } };
	vec3f temp_vertices0[8], temp_vertices1[8], temp_vertices2[8], temp_vertices3[8];
	//为临时数组赋值
	for (int i = 0; i < 8; i++) {
		temp_vertices0[i] = temp_vertices1[i] = temp_vertices2[i] = temp_vertices3[i] = vertices[i];
	}
	Mat4f n;
	n = Mat4f::scale3D(n, 0.5, 0.5, 0.5);
	n = n * Mat4f::rotate3DY(n,angle11);
	n = n * Mat4f::Orthox(0,600,600,0,0,600);
	TranslatePoint3D(temp_vertices0,n,8);
	createcube(temp_vertices0);
	glutSwapBuffers();
}
void InitGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void reshape(int width, int height)
{
	glViewport(0, 0, 600, 600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void TextCreateCubeByMat()
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
//void TextExample() {
//	TextCreateCubeByMat();
//}