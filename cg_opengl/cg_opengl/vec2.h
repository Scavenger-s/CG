#pragma once
#include"inline.h"
template<typename T>
class vec2
{
public:

	vec2();
	vec2(T x);
	vec2(T x, T y);
	//二维向量加法
	vec2<T> operator +(vec2 c);
	//二维向量减法
	vec2<T> operator -(vec2 c);
	//二维向量数乘运算
	vec2<T> operator *(T k);
	//显示函数
	void display();
	//二维单位化向量
	vec2<T> Normalize2D(vec2<T> point);
	//模长
	float length();
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
//template<typename T>
//float vec2<T>::operator .(vec2<T> c)
//{
//	return X * c.X + Y * c.Y;
//}
template<typename T>
vec2<T> vec2<T>::Normalize2D(vec2<T> point)
{
	float len = point.length();
	point.X = point.X / len;
	point.Y = point.Y / len;
	return point;
}
template<typename T>
float vec2<T>::length()
{
	return (sqrt(X*X + Y * Y));
}
template<typename T>
void vec2<T>::display()
{
	cout << "X=" << X << "  " << "Y=" << Y << endl;
}