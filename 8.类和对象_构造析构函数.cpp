#include <iostream>
#include <string>
using namespace std;


/*
	构造函数 类名(){}
	没有返回值不写void
	函数名与类名相同
	构造函数可以有参数，可以发生重载
	程序在调用对象时会自动调用，且只会调用一次

	析构函数 ~类名(){}
	没有返回值不写void
	不可以有参数
	程序对象销毁前自动调用，只会调用一次

*/

// class Person
// {
// private:
// 	string m_name;
// 	int age;
// public:
// 	Person()//无参构造函数
// 	{
// 		cout<<"Person无参构造函数调用\n"<<ends;
// 	}
// 	Person(int a)//有参构造函数
// 	{
// 		age=a;
// 		cout<<"Person有参构造函数调用\n"<<ends;
// 	}
// 	~Person()
// 	{
// 		cout<<"Person析构函数调用\n"<<ends;
// 	}
// 	Person(const Person &p)//拷贝构造
// 	{
// 		age=p.age;
// 		cout<<"Person拷贝构造函数调用\n"<<ends;
// 	}
// 	void get_age();
// };

// void Person::get_age()
// {
// 	cout<<age<<"\n"<<ends;
// }

// int main()
// {	
// 	Person A;
// 	Person B(10);
// 	Person C(B);
// 	B.get_age();
// 	C.get_age();


// 	Person p1=Person(10);
// 	Person(10);//匿名对象 当前行执行结束后，立即回收  不能利用构造拷贝初始化匿名对象


// 	Person p2=10;
// 	Person P3=p2;
// 	return 0;
// }




// class Person
// {
// private:
// 	string m_name;
// 	int m_age;

// public:
// 	Person()
// 	{
// 		cout<<"Person构造函数\n"<<ends;
// 	}

// 	Person(int age)
// 	{
// 		m_age=age;
// 		cout<<"Person有参构造函数\n"<<ends;
// 	}

// 	Person(const Person &p)
// 	{
// 		m_age=p.m_age;
// 		cout<<"Person拷贝构造函数\n"<<ends;
// 	}

// 	~Person()
// 	{
// 		cout<<"Person析构函数\n"<<ends;
// 	}
// };

// void test1(Person p)
// {

// }

// Person test2()
// {
// 	Person p4;
// 	return p4;
// }

// //拷贝构造函数调用时机
// int main()
// {
// 	Person p1;
// 	Person p2(10);
// 	Person p3(p2);

// 	test1(p1);//值传递的方式给函数参数传值  调用拷贝构造函数
// 	cout <<"-----------------------\n"<<ends;

// 	//值方式返回局部变量 调用拷贝构造函数
// 	Person p4=test2(); 
// 	cout <<"-----------------------\n"<<ends;
// 	return 0;
// }



/*
浅拷贝：简单的赋值操作
深拷贝：在堆区重新申请空间，进行拷贝操作
*/

class Person
{
public:
	string m_name;
	int* m_age;


	Person()
	{
		cout<<"Person构造函数\n"<<ends;
	}

	Person(int age)
	{
		m_age=new int(age);
		cout<<"Person有参构造函数\n"<<ends;
	}

	Person(const Person &p)
	{
		m_age=new int(*p.m_age);
		cout<<"Person拷贝构造函数\n"<<ends;
	}

	~Person()
	{
		if(m_age!=NULL)
		{
			delete m_age;
			m_age=NULL;
		}
		cout<<"Person析构函数\n"<<ends;
	}
};

int main()
{
	Person A(10);
	Person B(A);
	cout <<*A.m_age<<endl;
	cout <<*B.m_age<<endl;
	return 0;
}
