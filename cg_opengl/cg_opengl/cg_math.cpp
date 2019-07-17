#ifndef _CG_MATH_CPP_
#define _CG_MATH_CPP_
#include<iostream>
#include<cmath>
#include<GL/glut.h>
using namespace std;
#define PI  3.1415926
void DrawCircle(float r, float x0, float y0);
template<typename T>
class vec2
{
public:

	vec2();
	vec2(T x);
	vec2(T x, T y);
	vec2<T> operator +(vec2 c);//��ά�����ӷ�
	vec2<T> operator -(vec2 c);//��ά��������
	vec2<T> operator *(T k);//��ά������������
	void display();//��ʾ����
	T length();//ģ��
	T X, Y;
};
template<typename T>
vec2<T>::vec2()
{
	X = 0;
	Y = 0;
}
template<typename T>
vec2<T>::vec2(T x)
{
	X = x;
	Y = 0;
}
template<typename T>
vec2<T>::vec2(T x, T y)
{
	X = x;
	Y = y;
}
template<typename T>
vec2<T> vec2<T>::operator +(vec2 c)
{
	vec2<T> temp;
	temp.X = X + c.X;
	temp.Y = Y + c.Y;
	return temp;
}
template<typename T>
vec2<T> vec2<T>::operator -(vec2 c)
{
	vec2<T> temp;
	temp.X = X - c.X;
	temp.Y = Y - c.Y;
	return temp;
}
template<typename T>
vec2<T> vec2<T>::operator *(T k)
{
	vec2<T> temp;
	temp.X = X * k;
	temp.Y = Y * k;
	return temp;
}
template<typename T>
T vec2<T>::length()
{
	return (sqrt(X*X + Y * Y));
}
template<typename T>
void vec2<T>::display()
{
	cout << "X=" << X << "  " << "Y=" << Y << endl;
}
template<typename T>
class vec3
{
public:

	vec3();
	vec3(T x);
	vec3(T x, T y);
	vec3(T x, T y, T z);
	vec3<T> operator +(vec3 c);//��ά�����ӷ�
	vec3<T> operator -(vec3 c);//��ά�����
	vec3<T> operator *(T k);//��ά������������
	void display();
	T length();//ģ��
public:
	T X, Y, Z;
};
template<typename T>
vec3<T>::vec3()
{
	X = 0;
	Y = 0;
	Z = 0;
}
template<typename T>
vec3<T>::vec3(T x)
{
	X = x;
	Y = 0;
	Z = 0;
}
template<typename T>
vec3<T>::vec3(T x, T y)
{
	X = x;
	Y = y;
	Z = 0;
}
template<typename T>
vec3<T>::vec3(T x, T y, T z)
{
	X = x;
	Y = y;
	Z = z;
}
template<typename T>
vec3<T> vec3<T>::operator +(vec3 c)
{
	vec3<T> temp;
	temp.X = X + c.X;
	temp.Y = Y + c.Y;
	temp.Z = Z + c.Z;
	return temp;
}
template<typename T>
vec3<T> vec3<T>::operator -(vec3 c)
{
	vec3<T> temp;
	temp.X = X - c.X;
	temp.Y = Y - c.Y;
	temp.Z = Z - c.Z;
	return temp;
}
template<typename T>
vec3<T> vec3<T>::operator *(T k)
{
	vec3<T> temp;
	temp.X = X * k;
	temp.Y = Y * k;
	temp.Z = Z * k;
	return temp;
}
template<typename T>
T vec3<T>::length()
{
	return (sqrt(X*X + Y * Y + Z * Z));
}
template<typename T>
void vec3<T>::display()
{
	cout << "X=" << X << "  " << "Y=" << Y << "  " << "Z=" << Z << endl;
}
//���������
typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;
typedef vec3<int> vec3i;
typedef vec3<float> vec3f;
typedef vec3<double> vec3d; typedef vec2<int> vec2i;
/**************************************************************
***************************************************************/
template<typename T>
class Mat3
{
public:
	Mat3();
	Mat3<T> operator +(Mat3 c);//����ӷ�
	Mat3<T> operator *(T c);//��������
	Mat3<T> operator *(Mat3 c);//����˷�
	void setdata(T data[3][3]);//����ֵ
	void transtlate2D(T tx, T ty);//ƽ�ƾ���
	void scale2D(GLfloat sx, GLfloat sy, vec2f friendPt);//���������任
	void rotate2D(vec2f pivotpt, float theta);//��ת�任
	void display();
public:
	T M[3][3];
};
template<typename T>
Mat3<T>::Mat3()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			M[i][j] = (i == j);//i=0 j=0 
}
template<typename T>
Mat3<T> Mat3<T>::operator*(Mat3 c)
{
	Mat3<T> temp;
	for (int i = 0; i<3; i++)//��
		for (int j = 0; j < 3; j++)//��
		{
			temp.M[i][j] = M[i][0] * c.M[0][j] + M[i][1] * c.M[1][j] + M[i][2] * c.M[2][j];
		}
	return temp;
}
template<typename T>
Mat3<T> Mat3<T>::operator+(Mat3 c)
{
	Mat3<T> temp;
	for (int i = 0; i<3; i++)
		for (int j = 0; j < 3; j++)
		{
			temp.M[i][j] = M[i][j] + c.M[i][j];
		}
	return temp;
}
template<typename T>
Mat3<T> Mat3<T>::operator*(T c)
{
	Mat3<T> temp;
	for (int i = 0; i<3; i++)
		for (int j = 0; j < 3; j++)
		{
			temp.M[i][j] = M[i][j] * c;
		}
	return temp;
}
template<typename T>
void Mat3<T>::setdata(T data[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			M[i][j] = data[i][j];
}
template<typename T>
void Mat3<T>::display()
{
	int m = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (m % 3 == 0)
				cout << endl;
			cout << M[i][j] << " ";
			m++;
		}
}
template<typename T>
void Mat3<T>::transtlate2D(T tx, T ty)
{
	M[0][2] = tx;
	M[1][2] = ty;
}
template<typename T>
void Mat3<T>::scale2D(GLfloat sx, GLfloat sy, vec2f friendPt)
{
	M[0][0] = sx;
	M[0][2] = (1 - sx)*friendPt.X;
	M[1][1] = sy;
	M[1][2] = (1 - sy)*friendPt.Y;
}
template<typename T>
void Mat3<T>::rotate2D(vec2f pivotpt, float theta)
{
	M[0][0] = cos(theta);
	M[0][1] = -sin(theta);
	M[0][2] = pivotpt.X*(1 - cos(theta)) + pivotpt.Y*sin(theta);
	M[1][0] = sin(theta);
	M[1][1] = cos(theta);
	M[1][2] = pivotpt.Y*(1 - cos(theta)) - pivotpt.X*sin(theta);
}
//�����
typedef Mat3<int> Mat3i;
typedef Mat3<float> Mat3f;
typedef Mat3<double> Mat3d;
template<typename T>
void DrawPolygon2D(int nvertex, T*point)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < nvertex; i++)
	{
		glVertex2f(point[i].X, point[i].Y);
	}
	glEnd();
}
//ֱ�߻�ͼ����,size:ֱ�ߴ�ϸ��point����������
template<typename T>
void DrawLine(T*point)
{
	//glPointSize(size);
	glBegin(GL_LINES);
	glVertex2f(point[0].X, point[0].Y);
	glVertex2f(point[1].X, point[1].Y);
	glEnd();
}
//����ת���ຯ��
template<typename T1, typename T2>
void translatepoint(int nvertex, T1*point, T2 m)
{
	for (int k = 0; k < nvertex; k++)
	{
		point[k].X = m.M[0][0] * point[k].X + m.M[0][1] * point[k].Y + m.M[0][2] * 1;
		point[k].Y = m.M[1][0] * point[k].X + m.M[1][1] * point[k].Y + m.M[1][2] * 1;
		cout << "x=" << point[k].X << " y=" << point[k].Y << endl;
	}
}
/***************************************
int main()
{
Mat3f p;
p.display();
//��ά�������
/***************************
vec2f intop(3,4.0);
cout<<"|intop(3,4.0)|=";
cout << intop.length() << endl;
vec2f m = intop*3;
cout << endl;
intop.display();
m.display();
cout << endl;
//cout << "|intop|=" << intop.length() << endl;
//m.display();
//��ά�������
vec3f p(3.0,6.7,8);
//cout << "|p|=" << p.length() << endl;
vec3f s=p*6;
//s.display();
//a.display();
float data[3][3] = { {1,0,0},
{0,1,0},
{0,0,1} };
float data2[3][3] = { {1,1,1},
{0,0,1},
{1,0,0} };
Mat3<float> ppp,kkk,mmm;
ppp.setdata(data);
kkk.setdata(data2);
ppp.display();
cout << endl;
//float theta = (60.0/360)*2*PI;//�Ƕ�
//��ת����
//ppp.rotate2D(intop,theta);
//�����任����
//ppp.scale2D(2.0f,3.0f,intop);
//ƽ�Ʋ���
//ppp.transtlate2D(5.5,6.8);
//ppp.display();
//cout << endl;
//kkk.setdata(data2);
//����˷�����
//mmm = ppp * kkk;
//mmm.display();
//ppp.display();
***********************************
return 0;
}***********
int main()
{
	//Mat3f p;
	//p.display();
	int m = 0;
	float a[3][3] = { {1,2} };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (m % 3 == 0)
				cout << endl;
			cout << a[i][j] << "��";
			m++;
		}
	while (1);
}*************************/
#endif