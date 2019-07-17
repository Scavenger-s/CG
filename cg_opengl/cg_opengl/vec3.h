#pragma once
#include"inline.h"
#include"Mat3.h"
template<typename T>
class vec3
{
public:
	vec3();
	vec3(T x);
	vec3(T x, T y);
	vec3(T x, T y, T z);
	//三维向量加法
	vec3<T> operator +(vec3 c);
	//三维向量减法
	vec3<T> operator -(vec3 c);
	//三维向量数乘运算
	vec3<T> operator *(T k);
	//三维向量*三维矩阵
	vec3<T> operator *(Mat3<T> c);
	void display();
	//三维向量单位化
	static vec3<T> Normalize3D(vec3<T> point);
	//向量叉乘
	static vec3<T> multiply(const vec3<T> a, const vec3<T> b);
	//向量的点乘
	static float Dot(const vec3<T> a,const vec3<T> b);
	//模长
	float length();
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
vec3<T> vec3<T>::Normalize3D(vec3<T> point)
{
	float len = point.length();
	point.X = point.X / len;
	point.Y = point.Y / len;
	point.Z = point.Z / len;
	return point;
}
template<typename T>
inline vec3<T> vec3<T>::multiply(const vec3<T> a, const vec3<T> b)
{
	vec3<T> temp;
	temp.X = (a.Y*b.Z - b.Y*a.Z);
	temp.Y = (b.X*a.Z - a.X*b.Z);
	temp.Z = (a.X*b.Y - b.X*a.Y);
	return temp;
}
template<typename T>
inline float vec3<T>::Dot(const vec3<T> a, const vec3<T> b)
{
	float temp = a.X*b.X + a.Y*b.Y + a.Z*b.Z;
	return temp;
}
template<typename T>
float vec3<T>::length()
{
	return (sqrt(X*X + Y * Y + Z * Z));
}
template<typename T>
inline vec3<T> vec3<T>::operator*(Mat3<T> c)
{
	vec3<T> temp;
	temp.X = X * c.M[0][0] + Y * c.M[1][0] + Z * c.M[2][0];
	temp.Y = X * c.M[0][1] + Y * c.M[1][1] + Z * c.M[2][1];
	temp.Z = X * c.M[0][2] + Y * c.M[1][2] + Z * c.M[2][2];
	return temp;
}
template<typename T>
void vec3<T>::display()
{
	cout << "X=" << X << "  " << "Y=" << Y << "  " << "Z=" << Z << endl;
}