#include <iostream>
#include <string>
using namespace std;

// int main()
// {
// 	// 引用：给一个变量起别名
// 	int a=10;
// 	int &b=a;
// 	b=20;
// 	cout<<a<<"\n"<<ends;
// 	//引用必须初始化，初始化后就不可以更改引用

// 	return 0;
// }

// void func1(int&a,int&b)//引用传参
// {
// 	int temp=a;
// 	a=b;
// 	b=temp;
// }

// int main()
// {
// 	int a=10,b=20;
// 	func1(a,b);
// 	cout <<"a="<<a<<"\t"<<"b="<<b<<"\n"<<ends;
// 	return 0;
// }

//函数调用作为左值

// int& test1()
// {
// 	static int a=10;//全局区
// 	return a;//返回静态变量引用，不会被回收
// }

// int main()
// {
// 	int &ret=test1();
// 	cout<<ret<<"\n"<<ends;
// 	cout<<ret<<"\n"<<ends;
// 	test1()=1000;
// 	cout<<ret<<"\n"<<ends;
// 	cout<<ret<<"\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	//int& ret=a == int* const ref =&a
// 	int a=10;
// 	int&ret=a;
// 	ref=20;//自动转换为 *ref=20;
// 	return 0;
// }




// int func2(int a,int b=20)//默认形参 无传入就默认，有就用传入参数,从有默认参数位置往后都必须有默认参数
// {
// 	return a+b;
// }
// int main()
// {
// 	cout<<func2(10)<<"\n"<<ends;
// 	cout<<func2(10,30)<<"\n"<<ends;
// 	return 0;
// }
// //声明和实现只有一个有一个默认参数

// void func3(int a,int =10)//占位参数   
// {
// 	cout<<"this is a function"<<ends;
// }

// int main()
// {
// 	func3(10);

// 	return 0;
// }




//函数重载(同一作用域下同名函数参数类型不同，个数不同，顺序不同)tips:返回值不能作为函数重载的条

// void func()
// {
// 	cout<<"func的调用"<<"\n"<<ends;
// }

// void func(int a)
// {
// 	cout<<"func(int a)的调用!"<<"\n"<<ends;
// }

// void func(double a)
// {
// 	cout<<"func(double a)的调用!"<<"\n"<<ends;
// }

// void func(double a,int b)
// {
// 	cout<<"func(1)的调用!"<<"\n"<<ends;
// }

// void func(int a,double b)
// {
// 	cout<<"func(2)的调用!"<<"\n"<<ends;
// }

// int main()
// {	
// 	func();
// 	func(1);
// 	func(3.14);
// 	func(3.14,1);
// 	func(1,3.14);
// 	return 0;
// }

//函数重载注意事项
//1.引用作为重载的条件
void func(int &a)//int &a=10 不合法
{
	cout<<"func:int &a\n"<<ends;
}

void func(const int &a)//const int &a=10 合法
{
	cout<<"func:const int &a\n"<<ends;
}

//2.函数重载碰到默认参数
void func2(int a,int b=10)
{
	cout<<"func2:int a\n"<<ends;
}

void func2(int a)
{
	cout<<"func2:int a\n"<<ends;
}

int main()
{
	int a=10;
	func(a);
	const int b=10;
	func(b);
	func(10);

	func2(10,20);//合法
	//func2(10);//不合法
	return 0;
}