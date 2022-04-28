#include <iostream>
#include <string>
using namespace std;

// class Person 
// {
// public:
// 	int m_a;
// 	int m_b;
// 	int m_c;

// 	// Person(int a,int b,int c)
// 	// {
// 	// 	m_a=a;
// 	// 	m_b=b;
// 	// 	m_c=c;
// 	// }
// 	//初始化列表
// 	Person(int a,int b,int c):m_a(a),m_b(b),m_c(c)
// 	{

// 	}
// };

// int main()
// {
// 	// Person A(1,2,3);
// 	Person B(30 ,20,10);
// 	cout<<B.m_b<<endl;
// 	return 0;
// }



// class phone
// {
// public:
// 	string m_p_name;
// 	phone(string name)
// 	{
// 		m_p_name=name;
// 	}
// };

// class Person
// {
// public:
// 	string m_name;
// 	phone m_phone;

// 	Person(string name,string p_name):m_name(name),m_phone(p_name)
// 	{

// 	}
// };
// //先入后出
// int main()
// {
// 	Person A("张三","华为");
// 	cout <<A.m_name<<"\t"<<A.m_phone.m_p_name<<endl;
// 	return 0;
// }

//static修饰的静态成员函数  可直接  类名::函数 使用
//所有对象共享一个函数
//静态成员函数只能访问static修饰的静态成员变量

//static修饰的静态成员变量 所有对象共享





//this指针
//this指针指向被调用的成员函数所属的对象

// class Person
// {
// public:
// 	Person(int age)
// 	{
// 		this->age=age;
// 	}

// 	Person& Person_add_age(Person& p)
// 	{
// 		this->age=this->age+p.age;
// 		return *this;
// 	}
// 	int age;
// };

// int main()
// {
// 	Person A(18);
// 	Person B(10);
// 	A.Person_add_age(B).Person_add_age(B).Person_add_age(B);
// 	cout <<A.age<<endl;
// 	return 0;
// }






class Person
{
public:
	void showPerson()const//加const修饰本质是修饰this指针，原来是 \
	Person *const this,变为const Person *const this
	{
		this->m_b=100;
	}
	int m_a;
	mutable int m_b;
};

int main()
{
	Person A;
	A.showPerson();

	return 0;
}
