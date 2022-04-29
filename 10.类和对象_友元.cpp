#include <iostream>
#include <string>
using namespace std;

// //全局函数做友元
// class Home
// {
// 	friend void goodfriend(const Home &a);//函数是Home的友元
// public:
// 	string m_sittingroom;
// 	Home(){
// 		m_sittingroom="客厅";
// 		m_bedroom="卧室";
// 	}
// private:
// 	string m_bedroom;
// };

// void goodfriend(const Home &a)
// {
// 	cout<<"访问："<<a.m_sittingroom<<endl;
// 	cout<<"访问："<<a.m_bedroom<<endl;
// }

// int main()
// {
// 	Home A;
// 	goodfriend(A);
// 	return 0;
// }


// //类做友元
// class Home
// {
// 	friend class good_gay;
// public:
// 	string m_sittingroom;
// 	Home(){
// 		m_sittingroom="客厅";
// 		m_bedroom="卧室";
// 	}
// private:
// 	string m_bedroom;
// };

// class good_gay
// {
// public:
// 	void visit();
// 	Home *home;
// 	good_gay();
// };

// void good_gay::visit()
// {
// 	cout<<home->m_sittingroom<<endl;
// 	cout<<home->m_bedroom<<endl;
// }

// good_gay::good_gay()
// {
// 	home=new Home;//home指针指向堆区新建Home
// }

// int main()
// {
// 	good_gay A;
// 	A.visit();
// 	return 0;
// }


//成员函数做友元
class Home;
class good_gay
{
public:
	Home *home;
	good_gay();
	void visit();
};

class Home
{
	friend void good_gay::visit();
public:
	string m_sittingroom;
	Home();
private:
	string m_bedroom;
};

int main()
{
	good_gay A;
	A.visit();
	return 0;
}

void good_gay::visit()
{
	cout<<home->m_sittingroom<<endl;
	cout<<home->m_bedroom<<endl;
}

Home::Home(){
	m_sittingroom="客厅";
	m_bedroom="卧室";
}

good_gay::good_gay()
{
	home=new Home;//home指针指向堆区新建Home
}