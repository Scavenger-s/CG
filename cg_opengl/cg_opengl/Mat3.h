#pragma once
#include"inline.h"
#include"vec2.h"
template<typename T>
class Mat3
{
public:
	Mat3();
	Mat3(T a, T b, T c,
		 T d, T e, T f,
		 T g, T h, T i);
	Mat3<T> operator +(Mat3 c);//¾ØÕó¼Ó·¨
	Mat3<T> operator *(T c);//¾ØÕóÊı³Ë
	Mat3<T> operator *(Mat3 c);//¾ØÕó³Ë·¨
	void setdata(T data[3][3]);//¾ØÕó¸³Öµ
	static  Mat3<T> transtlate2D(Mat3<T>m, T tx, T ty);//Æ½ÒÆ¾ØÕó
	void scale2D(GLfloat sx, GLfloat sy, vec2<T> friendPt);//¾ØÕóÉìËõ±ä»»
	static  Mat3<T> rotate2D(const Mat3<T>m, vec2<T> pivotpt, float theta);//Ğı×ª±ä»»
	void SetMat3Identity(Mat3<T> a);//ÖØÖÃ¾ØÕó
	void Mat3PreMultiply(Mat3<T> m1, Mat3<T> m2);
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
inline Mat3<T>::Mat3(T a, T b, T c, T d, T e, T f, T g, T h, T i)
{
	M[0][0] = a; M[0][1] = b; M[0][2] = c;
	M[1][0] = d; M[1][1] = e; M[1][2] = f;
	M[2][0] = g; M[2][1] = h; M[2][2] = i;
}
template<typename T>
Mat3<T> Mat3<T>::operator*(Mat3 c)
{
	Mat3<T> temp;
	for (int i = 0; i<3; i++)//ĞĞ
		for (int j = 0; j < 3; j++)//ÁĞ
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
			if (m % 3 == 0 && m != 0)
				cout << endl;
			cout << M[i][j] << " ";
			m++;
		}
}
template<typename T>
Mat3<T> Mat3<T>::transtlate2D(const Mat3<T>m, T tx, T ty)
{
	Mat3<T> mattrans;
	mattrans.M[0][2] = tx;
	mattrans.M[1][2] = ty;
	return mattrans * m;
}
template<typename T>
void Mat3<T>::scale2D(GLfloat sx, GLfloat sy, vec2<T> friendPt)
{
	M[0][0] = sx;
	M[0][2] = (1 - sx)*friendPt.X;
	M[1][1] = sy;
	M[1][2] = (1 - sy)*friendPt.Y;
}
template<typename T>
Mat3<T> Mat3<T>::rotate2D(const Mat3<T>m, vec2<T> pivotpt, float theta)
{
	theta =ToDegree(theta);
	//cout << "theta=" << theta << endl;
	Mat3<T> temp;
	temp.M[0][0] = cos(theta);
	temp.M[0][1] = -sin(theta);
	temp.M[0][2] = pivotpt.X*(1 - cos(theta)) + pivotpt.Y*sin(theta);
	temp.M[1][0] = sin(theta);
	temp.M[1][1] = cos(theta);
	temp.M[1][2] = pivotpt.Y*(1 - cos(theta)) - pivotpt.X*sin(theta);
	return temp * m;
}
template<typename T>
inline void Mat3<T>::SetMat3Identity(Mat3<T> a)
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = (i == j);
}
template<typename T>
inline void Mat3<T>::Mat3PreMultiply(Mat3<T> m1, Mat3<T> m2)
{
	Mat3<T> temp;
	temp = m1 * m2;
	m2 = temp;
}