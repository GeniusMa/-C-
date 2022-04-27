#include "include/circle_point.h"
//三大特性：封装，继承和多态

// const double PI=3.14;

// class circle//设计一个类
// {
// 	// 访问权限，属性，行为
// public:

// 	int m_R;

// 	double calculate()
// 	{
// 		return 2*PI*m_R;
// 	}
// };

// int main()
// {
// 	circle c1;//实例化:通过一个类创建一个对象
// 	c1.m_R=10;
// 	cout<<c1.calculate()<<ends;
// 	return 0;
// }

/*
struct和class区别
struct 默认权限是public
class默认权限是private
*/
// struct C1
// {
// 	int m_A;
// };

// class C2
// {
// 	int m_A;
// };

// int main()
// {
// 	C1 c1;
// 	c1.m_A=10;
// 	cout<<c1.m_A<<ends;
// 	return 0;
// }

// class Person{
// private:
// 	string m_name;
// 	int m_age=0;
// public:
// 	void set_name(string name)
// 	{
// 		m_name=name;
// 	}
// 	string get_name()
// 	{
// 		return m_name;
// 	}
// 	int get_age()
// 	{
// 		return m_age;
// 	}
// 	void set_age(int age)
// 	{
// 		if(age>=0&&age<=150)
// 		{
// 			m_age=age;
// 		}
// 		else
// 		{
// 			cout<<"输入有误\n"<<ends;
// 		}
// 	}
// };

// int main()
// {
// 	Person A;
// 	A.set_name("赵天睿");
// 	cout<<A.get_name()<<"\n"<<ends;
// 	A.set_age(18);
// 	cout<<A.get_age()<<"\n"<<ends;
// 	return 0;
// }



/*立方体类*/

// class cube
// {
// private:
// 	double m_H;
// 	double m_W;
// 	double m_L;
// public:
// 	double get_volume()
// 	{
// 		return m_L*m_H*m_W;
// 	}

// 	void set_volume(double H,double L,double W)
// 	{
// 		m_L=L;
// 		m_W=W;
// 		m_H=H;
// 	}

// 	double get_L()
// 	{
// 		return m_L;
// 	}

// 	double get_W()
// 	{
// 		return m_W;
// 	}

// 	double get_H()
// 	{
// 		return m_H;
// 	}

// 	bool is_same_byclass(cube &B)
// 	{
// 		if(m_L==B.get_L() && m_H==B.get_H() && m_W==B.get_W())return true;
// 		else
// 			return 0;
// 	}
// };



// int main()
// {
// 	cube A;
// 	A.set_volume(2,2,2);
// 	cout<<A.get_volume()<<"\n"<<ends;
// 	cube B;
// 	B.set_volume(2,2,3);
// 	cout<<B.get_volume()<<"\n"<<ends;
// 	if(A.is_same_byclass(B)==true)
// 	{
// 		cout<<"两立方体相等\n"<<ends;
// 	}
// 	else
// 	{
// 		cout<<"不相等\n"<<ends;
// 	}
// 	return 0;
// }





/*点圆关系*/
// class Circle
// {
// private:
// 	int circle_center_x=0;
// 	int circle_center_y=0;
// 	double circle_radius=1;
// public:
// 	void set_radius(int d)
// 	{
// 		circle_radius=d;
// 	}

// 	double get_distance(int x,int y)
// 	{
// 		return sqrt(pow((circle_center_x-x),2)+pow((circle_center_y-y),2));
// 	}
// };



// class Point
// {
// private:
// 	int point_x;
// 	int point_y;
// public:
// 	void set_point_coordinates(int x,int y)
// 	{
// 		point_x=x;
// 		point_y=y;
// 	}
// 	int* get_point_coordinates()
// 	{
// 		static int arr[2]={point_x,point_y};
// 		return arr;
// 	}
// };

int main()
{
	Circle A;
	Point B;
	int arr[2];
	int circle_radius;
	cout<<"请输入圆的半径\n"<<ends;
	cin>>circle_radius;
	A.set_radius(circle_radius);
	cout<<"请输入点的坐标\n"<<ends;
	for(int i=0;i<2;i++)
	{
		cin>>arr[i];
	}
	B.set_point_coordinates(arr[0],arr[1]);
	int*p=B.get_point_coordinates();
	double distance=A.get_distance(*p,*(p+1));
	cout<<"距离为："<<distance<<"\n"<<ends;
	if(distance>circle_radius)
	{
		cout<<"点在圆外\n"<<ends;;
	}
	else if(distance==circle_radius)
	{
		cout<<"点在圆上\n"<<ends;
	}
	else
	{
		cout<<"点在圆内\n"<<ends;
	}
	return 0;
}

void Circle::set_radius(int d)//Circle作用域下的成员函数
{
	circle_radius=d;
}

double Circle::get_distance(int x,int y)
{
	return sqrt(pow((circle_center_x-x),2)+pow((circle_center_y-y),2));
}

void Point::set_point_coordinates(int x,int y)
{
	point_x=x;
	point_y=y;
}
int* Point::get_point_coordinates()
{
	static int arr[2]={point_x,point_y};
	return arr;
}