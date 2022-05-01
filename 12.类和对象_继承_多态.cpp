#include <iostream>
#include <string>
using namespace std;

// class Base_Page
// {
// public:
// 	void same_part()
// 	{
// 		cout<<"公共部分"<<endl;
// 	}
// };

// class A : public Base_Page
// {
// public:
// 	void content()
// 	{
// 		cout<<"A"<<endl;
// 	}
// };

// int main()
// {
// 	A a;
// 	a.same_part	();
// 	a.content();
// 	return 0;
// }


// class father
// {
// public:
// 	int a;
// 	father();
// 	~father();
// protected:
// 	int b;
// private://无论那种继承都不能访问
// 	int c;
// };

// class son:public father
// {
// public:
// 	int d;
// 	son();
// 	~son();
// };

// int main()
// {
// 	son a;
// 	return 0;
// }

// father::father()
// {
// 	cout<<"基类构造"<<endl;
// }

// son::son()
// {
// 	cout<<"子类构造"<<endl;
// }

// father::~father()
// {
// 	cout<<"基类析构"<<endl;
// }

// son::~son()
// {
// 	cout<<"子类析构"<<endl;
// }



// /*同名成员访问*/
// class father
// {
// public:
// 	int a;
// 	void func();
// protected:
// 	int b;
// private://无论那种继承都不能访问
// 	int c;
// };

// class son :public father
// {
// public:
// 	int a;
// 	void func();
// };

// int main()
// {
// 	son A;
// 	A.a=1;
// 	A.father::a=2;
// 	cout<<A.a<<endl;
// 	cout<<A.father::a<<endl;
// 	A.func();
// 	A.father::func();
// 	return 0;
// }

// void father::func()
// {
// 	cout<<"基类成员函数"<<endl;
// }
// void son::func()
// {
// 	cout<<"子类成员函数"<<endl;
// }



// /*多继承*/
// class DingYuan
// {
// public:
// 	int a=0;
// };

// class DongZhuo
// {
// public:
// 	int a=2;
// };

// class LvBu :public DingYuan,public DongZhuo
// {
// public:
// 	int a=3;
// };

// int main()
// {
// 	LvBu a;
// 	cout<<a.a<<endl;
// 	cout<<a.DingYuan::a<<endl;
// 	cout<<a.DongZhuo::a<<endl;
// 	cout<<sizeof(a)<<endl;
// 	return 0;
// }


// class Animal{public: int m_age;};

// class Sheep:virtual public Animal{};//虚继承 相当于共享m_age

// class Tuo:virtual public Animal{};

// class SheepTuo:public Sheep,public Tuo{};

// int main()
// {
// 	SheepTuo st;
// 	st.Sheep::m_age=18;
// 	st.Tuo::m_age=20;
// 	cout<<st.Sheep::m_age<<endl;
// 	cout<<st.Tuo::m_age<<endl;
// 	cout<<st.m_age<<endl;
// 	return 0;
// }




// /*多态*/

// class Animal
// {
// public:
// 	virtual void speak()//虚函数 晚绑定
// 	{
// 		cout<<"动物说话"<<endl;
// 	}
// };

// class Cat:public Animal
// {
// public:
// 	void speak()
// 	{
// 		cout<<"小😺说话"<<endl;
// 	}
// };

// class Dog:public Animal
// {
// public:
// 	void speak()
// 	{
// 		cout<<"小🐶说话"<<endl;
// 	}
// };

// void dospeak(Animal &animal)//基类指针可以直接指向子类对象
// {
// 	animal.speak();
// }

// int main()
// {
// 	Cat cat;
// 	dospeak(cat);
// 	Dog dog;
// 	dospeak(dog);
// }


// class calulator
// {
// public:
// 	int m_num1;
// 	int m_num2;
// 	int get_result(string oper)
// 	{
// 		if(oper=="+")
// 			return m_num2+m_num1;
// 	}
// };

// int main()
// {
// 	calulator a;
// 	a.m_num1=1;
// 	a.m_num2=2;
// 	cout<<a.get_result("+")<<endl;
// 	return 0;
// }

class calulator
{
public:
	virtual int getresult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};

class add:public calulator
{
	int getresult()
	{
		return m_num1+m_num2;
	}
};

class sub:public calulator
{
	int getresult()
	{
		return m_num1-m_num2;
	}
};

class mul:public calulator
{
	int getresult()
	{
		return m_num1*m_num2;
	}
};

int main()
{
	calulator* cal=new add;
	cal->m_num1=1;
	cal->m_num2=2;
	cout<<cal->getresult()<<endl;
	delete cal;//指针仍然是基类指针，只是释放了指针指向的内存
	cal=new mul;
	cal->m_num1=10;
	cal->m_num2=20;
	cout<<cal->getresult()<<endl;
	delete cal;
	return 0;
}