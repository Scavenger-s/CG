#pragma once
#include"inline.h"
template<typename T>
//二维画图函数
void DrawPolygon2D(vec3<T> *point, int nvertex, int mode)
{
	glBegin(mode);
	for (int i = 0; i < nvertex; i++)
	{
		glVertex2f(point[i].X, point[i].Y);
	}
	glEnd();
}
//三维画图函数
template<typename T>
void DrawPolygon3D(vec3<T> *point, int nvertex, int mode)
{
	glBegin(mode);
		for (int i = 0; i < nvertex; i++) {
			glVertex3f(point[i].X,point[i].Y,point[i].Z);
			/*cout << point[i].X << std::setw(10) << point[i].Y << std::setw(10) << point[i].Z;*/
		}
	glEnd();
}
//三维上色
template<typename T>
inline void DrawColor(vec3<T> color)
{
	glColor3f(color.X,color.Y,color.Z);
}
//顶点转化类函数
template<typename T1, typename T2>
void TranslatePoint2D(vec3<T1>*point,Mat3<T2> m, int nvertex)
{
	float temp;
	for (int k = 0; k < nvertex; k++)
	{
		temp = m.M[0][0] * point[k].X + m.M[0][1] * point[k].Y + m.M[0][2];
		//cout << "m.M[1][0] * point[2].X + m.M[1][1] * point[2].Y + m.M[1][2]=" << m.M[1][0] * point[2].X + m.M[1][1] * point[2].Y + m.M[1][2] << endl;
		point[k].Y = m.M[1][0] * point[k].X + m.M[1][1] * point[k].Y + m.M[1][2];
		point[k].X = temp;
		//cout << "x["<<k<<"]=" << point[k].X << " y["<<k<<"]=" << point[k].Y << endl;
	}
}
template<typename T,typename T1>
void TranslatePoint3D(vec3<T>*point, Mat4<T1> m, int nvertex) {
	float temp1, temp2;
	for (int k = 0; k < nvertex; k++)
	{
		temp1 = m.M[0][0] * point[k].X + m.M[0][1] * point[k].Y + m.M[0][2] * point[k].Z + m.M[0][3];
		temp2 = m.M[1][0] * point[k].X + m.M[1][1] * point[k].Y + m.M[1][2] * point[k].Z + m.M[1][3];
		point[k].Z = m.M[2][0] * point[k].X + m.M[2][1] * point[k].Y + m.M[2][2] * point[k].Z + m.M[2][3];
		point[k].X = temp1;
		point[k].Y = temp2;
	}
}
//求二维中心点函数
template<typename T>
T GetCenterPoint2D(T*point, int nvertex)
{
	float xsum = 0.0, ysum = 0.0;
	for (int k = 0; k < nvertex; k++)
	{
		xsum += point[k].X;
		ysum += point[k].Y;
	}
	T centerpoint;
	centerpoint.X = float(xsum) / float(nvertex);
	centerpoint.Y = float(ysum) / float(nvertex);
	return centerpoint;
}
//求三维中心点函数
template<typename T>
T GetCenterPoint3D(T*point, int nvertex)
{
	float xsum = 0.0, ysum = 0.0, zsum = 0.0;
	for (int k = 0; k < nvertex; k++)
	{
		xsum += point[k].X;
		ysum += point[k].Y;
		zsum += point[k].Z;
	}
	T centerpoint;
	centerpoint.X = float(xsum) / float(nvertex);
	centerpoint.Y = float(ysum) / float(nvertex);
	centerpoint.Z = float(zsum) / float(nvertex);
	return centerpoint;
}
//求x的最大值
template<typename T>
float Max_x(T*point, int npoints)
{
	float max_x = point[0].X;
	for (int i = 1; i < npoints; i++)
		if (max_x< point[i].X)
			max_x = point[i].X;
	return max_x;
}
//求y的最大值
template<typename T>
float Max_y(T*point, int npoints)
{
	float max_y = point[0].Y;
	for (int i = 1; i < npoints; i++)
		if (max_y< point[i].Y)
			max_y = point[i].Y;
	return max_y;
}
//求z的最大值
template<typename T>
float Max_z(T*point, int npoints)
{
	float max_z = point[0].Z;
	for (int i = 1; i < npoints; i++)
		if (max_z< point[i].Z)
			max_z = point[i].Z;
	return max_z;
}
template<typename T,typename T1>
void colorvertex(vec3<T>color, vec3<T1> vertex) {
	glColor3f(color.X, color.Y, color.Z);
	glVertex3f(vertex.X, vertex.Y, vertex.Z);
}