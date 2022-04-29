#include <iostream>
#include <string>
using namespace std;

// //加号,左移重载
// class A
// {
// public:
// 	int m_a;
// 	int m_b;
// 	A(int a,int b);
// 	A operator+(A &p);
// 	A operator+(int a);
// };

// ostream& operator<<(ostream &cout,A &a)//只能用全局函数,简化cout<<p
// {
// 	cout<<"m_a="<<a.m_a;
// 	return cout;
// }

// int main()
// {
// 	A a1(10,10);
// 	A a2(20,20);
// 	//A a3=a1.operator+(a2);
// 	A a3=a1+a2;
// 	A a4=a1+10;
// 	cout<<a3.m_a<<endl;
// 	cout<<a4.m_a<<endl;

// 	cout<<a1<<endl;
// 	return 0;
// }

// A::A(int a,int b)
// {
// 	m_a=a;
// 	m_b=b;
// }

// A A::operator+(A &p)
// {
// 	A temp(0,0);
// 	temp.m_a=this->m_a+p.m_a;
// 	temp.m_b=this->m_b+p.m_b;
// 	return temp;
// }

// A A::operator+(int a)
// {
// 	A temp(0,0);
// 	temp.m_a=this->m_a+a;
// 	temp.m_b=this->m_b+a;
// 	return temp;
// }



// //递增重载
// class MyInteger
// {
// 	friend ostream& operator<<(ostream&cout,MyInteger &myint);
// public:
// 	MyInteger();
// 	MyInteger& operator++();//前置递增
// 	MyInteger operator++(int);//后置递增
// private:
// 	int m_Num;
// };

// ostream& operator<<(ostream &cout,MyInteger& myint)
// {
// 	cout<<myint.m_Num;
// 	return cout;
// }

// int main()
// {
// 	MyInteger myint,temp;
// 	cout<<++(++myint)<<endl;
// 	cout<<myint<<endl;
// 	temp=myint++;
// 	cout<<temp<<endl;
// 	cout<<myint<<endl;
// 	return 0;
// }

// MyInteger::MyInteger()
// {
// 	m_Num=0;
// }

// MyInteger& MyInteger::operator++()
// {
// 	m_Num++;
// 	return *this;
// }

// MyInteger MyInteger::operator++(int)
// {
// 	MyInteger temp=*this;
// 	m_Num++;
// 	return temp;
// }


//赋值运算符
class Person
{
public:
	Person(int age);
	~Person();
	int* m_age;
	Person& operator=(Person &p);
};

int main()
{
	Person A(18);
	Person B(20);
	Person C(30);
	// B=A;
	// *A.m_age=16;//系统提供默认为浅拷贝
	C=B=A;
	*A.m_age=16;
	cout<<*B.m_age<<endl;
	cout<<*C.m_age<<endl;
	return 0;
}

Person::Person(int age)
{
	m_age=new int(age);
}

Person::~Person()
{
	if(m_age!=NULL)
	{
		delete m_age;
		m_age=NULL;
	}	
}

Person& Person::operator=(Person &p)
{
	if(this->m_age!=NULL)
	{
		delete m_age;
		m_age=NULL;
	}
	this->m_age=new int(*p.m_age);
	return *this;
}