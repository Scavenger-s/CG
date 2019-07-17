#pragma once
#include"inline.h"
#include"vec3.h"
template<typename T>
class Mat4
{
public:
	Mat4();
	Mat4(
		const T& a, const T& b, const T& c, const T& d,
		const T& e, const T& f, const T& g, const T& h,
		const T& i, const T& j, const T& k, const T& l,
		const T& m, const T& n, const T& o, const T& p);
	//void SetData(T point[4][4]);
	Mat4<T> operator *(const Mat4<T> c);
	//平移
	static Mat4<T> translate3D(const Mat4<T>m,T tx,T ty,T tz);
	//伸缩变换
	static Mat4<T> scale3D(const Mat4<T>m, T sx, T sy, T sz);
	//绕x轴旋转,theta,角度
	static Mat4<T> rotate3DX(const Mat4<T>m, float (theta));
	//绕y轴旋转,theta,角度
	static Mat4<T> rotate3DY(const Mat4<T>m,float (theta));
	//绕z轴旋转,theta,角度
	static Mat4<T> rotate3DZ(const Mat4<T>m,float (theta));
	//lookat矩阵,eye，视点,target,目标点,up,上向量
	static Mat4<T> LookAt(const vec3<T> eye,const vec3<T>target,const vec3<T>up);
	//正交投影
	static Mat4<T> Orthox(T left, T right, T top, T bottom, T near, T far);
	//透视投影,aspect,宽高比，fov 视角，near,近平面,far,远平面
	static Mat4<T> Perspective(T fov, T aspect, T near, T far);
	//显示函数
	void dispaly();
public:
	T M[4][4];
};

template<typename T>
 Mat4<T>::Mat4()
{
	 for (int i = 0; i < 4; i++)
		 for (int j = 0; j < 4; j++)
			 M[i][j] = (i == j);
}

 template<typename T>
 inline Mat4<T>::Mat4(const T & a, const T & b, const T & c, const T & d, const T & e, const T & f, const T & g, const T & h, const T & i, const T & j, const T & k, const T & l, const T & m, const T & n, const T & o, const T & p)
 {
	 M[0][0] = a; M[0][1] = b; M[0][2] = c; M[0][3] = d;
	 M[1][0] = e; M[1][1] = f; M[1][2] = g; M[1][3] = h;
	 M[2][0] = i; M[2][1] = j; M[2][2] = k; M[2][3] = l;
	 M[3][0] = m; M[3][1] = n; M[3][2] = o; M[3][3] = p;
 }

template<typename T>
inline Mat4<T> Mat4<T>::operator*(const Mat4<T> c)
{
	Mat4<T> temp;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			temp.M[i][j]= M[i][0] * c.M[0][j] + M[i][1] * c.M[1][j] + M[i][2] * c.M[2][j]+M[i][3]*c.M[3][j];
	return temp;
}
template<typename T>
inline Mat4<T> Mat4<T>::translate3D(const Mat4<T>m, T tx, T ty,T tz)
{
	Mat4<T> temp;
	temp.M[0][3] = tx;
	temp.M[1][3] = ty;
	temp.M[2][3] = tz;
	return temp*m;
}
template<typename T>
 Mat4<T> Mat4<T>::scale3D(const Mat4<T>m, T sx, T sy, T sz)
{
	Mat4<T> temp;
	temp.M[0][0] = sx;
	temp.M[1][1] = sy;
	temp.M[2][2] = sz;
	return temp*m;
}
 template<typename T>
 inline Mat4<T> Mat4<T>::rotate3DX(const Mat4<T> m, float (theta))
 {
	 Mat4<T> temp;
	 theta= theta * PI / 180;
	 temp.M[1][1] = cos(theta);
	 temp.M[1][2] = -sin(theta);
	 temp.M[2][1] = sin(theta);
	 temp.M[2][2] = cos(theta);
	 return temp*m;
 }
 template<typename T>
 inline Mat4<T> Mat4<T>::rotate3DY(const Mat4<T> m, float(theta))
 {
	 theta= theta * PI / 180;
	 Mat4<T> temp;
	 temp.M[0][0] = cos(theta);
	 temp.M[0][2] = sin(theta);
	 temp.M[2][0] = -sin(theta);
	 temp.M[2][2] = cos(theta);
	 return temp*m;
 }
 template<typename T>
 inline Mat4<T> Mat4<T>::rotate3DZ(const Mat4<T> m, float(theta))
 {
	 Mat4<T> temp;
	 theta = ToDegree(theta);
	 temp.M[0][0] = cos(theta);
	 temp.M[0][1] = -sin(theta);
	 temp.M[1][0] = sin(theta);	
	 temp.M[1][1] = cos(theta);
	 return temp*m;
 }
 template<typename T>
 inline Mat4<T> Mat4<T>::LookAt(vec3<T> eye,vec3<T> target, vec3<T> up)
 {
	 const vec3<T> n = vec3<T>::Normalize3D((target-eye));
	 const vec3<T> u = vec3<T>::Normalize3D(vec3<T>::multiply(up,n));
	 const vec3<T> v = vec3<T>::multiply(n, u);
	 Mat4<T> vm(
	            u.X,u.Y,u.Z,-vec3<T>::Dot(u,eye),
		        v.X,v.Y,v.Z,-vec3<T>::Dot(v,eye),
		        n.X,n.Y,n.Z,-vec3<T>::Dot(n,eye),
		        0  ,0  ,0  ,1                  );
	 return vm;
 }
 template<typename T>
 inline Mat4<T> Mat4<T>::Orthox(T left, T right, T bottom, T top, T near, T far)
 {  
	 Mat4<T> ortho( 
	               T(2)/(right-left),                0,               0,-((left+right)/(right-left)),
		                           0,T(2)/(top-bottom),               0,-((top+bottom)/(top-bottom)),
					               0,                0,-T(2)/(far-near),       (near+far)/(far-near),
		                           0,                0,               0,                            1);
	 return ortho;
 }
 template<typename T>
 inline Mat4<T> Mat4<T>::Perspective(T fov, T aspect, T near, T far)
 {
	 T theta = tan(ToDegree(fov/2));
	 Mat4<T> perspective(
		                 T(1) / (theta * aspect), T(0), T(0), T(0),
		                 T(0), T(1) / theta, T(0), T(0),
		                 T(0), T(0), -(far + near) / (far - near), -T(2) * near * far / (far - near),
		                 T(0), T(0),  -T(1), T(0));
	 return perspective;
 }
 template<typename T>
void Mat4<T>::dispaly()
{
	int width = 12;
	cout<<"(" << std::setw(width) << M[0][0] <<
		" " << std::setw(width) << M[0][1] <<
		" " << std::setw(width) << M[0][2] <<
		" " << std::setw(width) << M[0][3] << "\n" <<

		" " << std::setw(width) << M[1][0] <<
		" " << std::setw(width) << M[1][1] <<
		" " << std::setw(width) << M[1][2] <<
		" " << std::setw(width) << M[1][3] << "\n" <<

		" " << std::setw(width) << M[2][0] <<
		" " << std::setw(width) << M[2][1] <<
		" " << std::setw(width) << M[2][2] <<
		" " << std::setw(width) << M[2][3] << "\n" <<

		" " << std::setw(width) << M[3][0] <<
		" " << std::setw(width) << M[3][1] <<
		" " << std::setw(width) << M[3][2] <<
		" " << std::setw(width) << M[3][3] << ")\n";
}
