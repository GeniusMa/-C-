#include <iostream>
#include <string>
using namespace std; 

// int main()
// {
// 	printf("Hello World!\n");
// 	cout<<"Hello C!"<<ends;//cout=C out  C输出
// 	return 0;
// }

// #define const_num 10

// int main()
// {
// 	for(int a=5;a<=10;a++)
// 	{
// 		cout<<"a="<<a<<"\n"<<ends;	
// 	}
// 	cout<<const_num<<"\n"<<ends;
// 	const int b=20;
// 	cout<<b<<"\n"<<ends;
//  }

//标识符=常量 或 变量
//不可以是关键字
//字母、数字、下划线，开头必须是字母或下划线

// int main()
// {
// 	short a;//-32768~32767
// 	int b;
// 	long c;
// 	long long d;
// 	cout<<sizeof(a)<<"\n"<<ends;
// 	cout<<sizeof(b)<<"\n"<<ends;
// 	cout<<sizeof(c)<<"\n"<<ends;
// 	cout<<sizeof(d)<<"\n"<<ends;
// 	return 0;
// }


/*
folat 4字节 7位有效数字
double 8位 15～16位有效数字
*/
// int main()
// {
// 	float f1=3.14f;
// 	cout << f1 << "\n" <<ends;
// 	double d1=3.14;
// 	cout << d1 << "\n" <<ends;
// }

// int main()//科学计数法
// {
// 	float f2=3e2;//3*10^2
// 	cout<<f2<<ends;
// }

// int main()
// {
// 	char ch='a';
// 	char str[] ="olofmeister";
// 	cout<<"char占字节数"<<sizeof(char)<<"\n"<<ch<<"\n"<<ends;
// 	cout<<"str占字节数"<<sizeof(str)<<"\n"<<str<<"\n"<<ends;
// 	printf("%d\n",(int)ch );
// }

// int main()
// {
// 	cout <<"aaa\thello\n"<<ends;
// 	cout <<"aaaaaa\thello\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	string str2="olofmeister";
// 	cout<<str2<<"\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	int a=3,b=5;
// 	bool flag=a>b;
// 	cout <<flag<<"\n"<<ends;
// 	if(bool(a))
// 	{
// 		printf("真\n");
// 	}
// 	return 0;
// }

int main()
{
	int a=0;
	cout<<"请输入A"<<"\n"<<ends;
	cin>>a;
	cout<<a<<"\n"<<ends;
	return 0;
}