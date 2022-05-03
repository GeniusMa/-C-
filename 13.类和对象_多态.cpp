#include <iostream>
#include <string>
using namespace std;

// class father //抽象类  不允许实例化对象
// {
// public:
// 	int m_a;
// 	int m_b;
// 	virtual void func()=0;//纯虚函数
// };

// class son:public father//子类必须重写纯虚函数
// {
// public:
// 	virtual void func()
// 	{
// 		cout<<"子类成员函数"<<endl;
// 	}
// }; 

// int main()
// {
// 	father* p=new son;
// 	p->func();
// 	return 0;
// }



// class AbstractDrinking
// {
// public:
// 	virtual void Boil()=0;
// 	virtual void Brew()=0;
// 	virtual void Pour()=0;
// 	virtual void Add_else()=0;
// 	void make_drink()
// 	{
// 		Boil();
// 		Brew();
// 		Pour();
// 		Add_else();
// 	}
// };

// class Tea:public AbstractDrinking
// {
// public:
// 	void Boil()
// 	{
// 		cout<<"煮水"<<endl;
// 	}
// 	void Brew()
// 	{
// 		cout<<"冲泡茶叶"<<endl;
// 	}
// 	void Pour()
// 	{
// 		cout<<"倒入杯中"<<endl;
// 	}
// 	void Add_else()
// 	{
// 		cout<<"加入枸杞"<<endl;
// 	}
// };

// int main()
// {
// 	AbstractDrinking* p=new Tea;
// 	p->make_drink();
// 	delete p;
// 	p=new Tea;
// 	p->make_drink();
// 	delete p;
// 	return 0;
// }





// class Animal
// {
// public:
// 	virtual void speak()=0;
// 	virtual ~Animal(){};//虚析构
// };

// class cat:public Animal
// {
// public:
// 	cat(string name);
// 	~cat();
// 	void speak()
// 	{
// 		cout<<*m_name<<"在说话"<<endl;
// 	}
// 	string*	 m_name;
// };

// void do_speak(string name)
// {
// 	Animal* p=new cat(name);
// 	p->speak();
// 	delete p;
// }

// int main()
// {
// 	do_speak("Tom");
// 	return 0;
// }

// cat::cat(string name)
// {
// 	cout<<"cat构造函数"<<endl;
// 	m_name = new string(name);
// }

// cat::~cat()
// {
// 	if(m_name!=NULL)
// 	{
// 		cout<<"cat析构函数"<<endl;
// 		delete m_name;
// 		m_name=NULL;
// 	}
// }




class CPU
{
public:
	virtual void caculate()=0;
};

class videocard
{
public:
	virtual void display()=0;
};

class memory
{
public:
	virtual void storage()=0;
};

class computer
{
private:
	CPU* m_cpu;
	videocard* m_vc;
	memory* m_mem;
public:
	computer(CPU* cpu,videocard *vc,memory *mem)
	{
		m_cpu=cpu;
		m_vc=vc;
		m_mem=mem;
	}
	void work()
	{
		m_cpu->caculate();
		m_vc->display();
		m_mem->storage();
	}
};

class AMD_CPU:public CPU{
public:
	void caculate()
	{
		cout<<"AMD_CPU工作"<<endl;
	}
};

class AMD_VC:public videocard{
public:
	void display()
	{
		cout<<"AMD_显卡工作"<<endl;
	}
};

class AMD_MEM:public memory{
public:
	void storage()
	{
		cout<<"AMD_内存工作"<<endl;
	}
};

int main()
{
	computer* computer1=new computer(new AMD_CPU,new AMD_VC ,new AMD_MEM);
	computer1->work();
	delete computer1;
	return 0;
}