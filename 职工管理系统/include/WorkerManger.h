#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
using namespace std;

#define FILENAME "/home/robot114/learning_C++/职工管理系统/EmpFile.txt"

class WorkerManger
{
public:
	WorkerManger();
	~WorkerManger();

	void show_menu();
	void Exit_System();
	void Add_Worker();
	void save();
	int get_EmpNum();
	void init_Emp();
	void show_Emp();
	void delete_Emp();
	int IsExit(int id);
	void find_Emp();
	void modify_Emp();
private:
	int m_EmpNum;
	Worker** m_EmpArry;
	bool m_FileIsEmpty;
};

WorkerManger::WorkerManger()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if(!ifs.is_open())//文件不存在
	{
		cout<<"文件不存在!"<<endl;
		this->m_EmpNum=0;
		this->m_EmpArry=NULL;
		this->m_FileIsEmpty=true;
		ifs.close();
		return;
	}
	char ch;
	ifs>>ch;
	if(ifs.eof())//文件存在数据为空
	{
		cout<<"文件为空!"<<endl;
		this->m_EmpNum=0;
		this->m_EmpArry=NULL;
		this->m_FileIsEmpty=true;
		ifs.close();
		return;
	}
	this->m_FileIsEmpty=false;
	this->m_EmpNum=this->get_EmpNum();
	cout<<"职工人数为"<<this->m_EmpNum<<endl;

	this->m_EmpArry=new Worker*[this->m_EmpNum];//开辟空间，才能存储数据\
	，init_Emp与get_EmpNum重复但不可替代.
	this->init_Emp();

	// for(int i=0;i<this->m_EmpNum;i++)
	// {
	// 	this->m_EmpArry[i]->show_info();
	// }
}

WorkerManger::~WorkerManger()
{
	if(this->m_EmpArry!=NULL)
	{
		delete[] this->m_EmpArry;
		this->m_EmpArry=NULL;
	}
}

void WorkerManger::show_menu()
{
	cout<<"******************************************"<<endl;
	cout<<"**********欢迎使用职工管理系统!***********"<<endl;
	cout<<"************* 0.退出管理系统 *************"<<endl;
	cout<<"************* 1.增加职工信息 *************"<<endl;
	cout<<"************* 2.显示职工信息 *************"<<endl;
	cout<<"************* 3.删除离职职工 *************"<<endl;
	cout<<"************* 4.修改职工信息 *************"<<endl;
	cout<<"************* 5.查找职工信息 *************"<<endl;
	cout<<"************* 6.按照编号排序 *************"<<endl;
	cout<<"************* 7.清除职工信息 *************"<<endl;
	cout<<"******************************************"<<endl;
}	

void WorkerManger::Exit_System()
{
	system("clear");
	cout<<"欢迎下次使用"<<endl;
	exit(0);
}

void WorkerManger::Add_Worker()
{
	cout<<"请输入添加职工数量"<<endl;
	int addNum=0;
	cin>>addNum;
	if(addNum>0)
	{
		int newsize=this->m_EmpNum+addNum;
		Worker** newSpace=new Worker*[newsize];
		if(this->m_EmpArry!=NULL)//转移原有数据
		{
			for(int i=0;i<this->m_EmpNum;i++)
			{
				newSpace[i]=this->m_EmpArry[i];
			}
		}

		for(int i=0;i<addNum;i++)
		{
			int id;
			string name;
			int depart;
			cout<<"请输入第"<<i+1<<"个新职工编号:"<<endl;
			cin>>id;
			cout<<"请输入第"<<i+1<<"个新职工姓名:"<<endl;
			cin>>name;
			cout<<"请输入第"<<i+1<<"个新职工岗位:\n1.普通职工\n2.经理\n3.老板"<<endl;
			cin>>depart;
			Worker* worker=NULL;
			switch(depart)
			{
			case 1:
				worker= new Employer(id,name,depart);
				break;
			case 2:
				worker= new Manager(id,name,depart);
				break;
			case 3:
				worker= new Boss(id,name,depart);
				break;
			default:
				break;
			}
			newSpace[i+this->m_EmpNum]=worker;
		}
		delete[] this->m_EmpArry;
		this->m_EmpArry=newSpace;
		this->m_EmpNum=newsize;
		this->m_FileIsEmpty=false;

		this->save();

		system("clear");
		cout<<"添加成功"<<addNum<<"人"<<endl;
		
	}

	else
	{
		cout<<"输入有误"<<endl;
	}
}

void WorkerManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for(int i=0;i<this->m_EmpNum;i++)
	{
		ofs<<this->m_EmpArry[i]->m_id<<" "
		   <<this->m_EmpArry[i]->m_name<<" "
		   <<this->m_EmpArry[i]->m_deptid<<endl;
	}

	ofs.close();
}

int WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;

	int num=0;
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;

	int num=0;
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		Worker* worker=NULL;
		if(did==1)
		{
			worker=new Employer(id,name,did);
		}
		else if(did==2)
		{
			worker=new Manager(id,name,did);
		}
		else if(did==3)
		{
			worker=new Boss(id,name,did);
		}
		this->m_EmpArry[num]=worker;
		num++;
	}
	ifs.close();
}

void WorkerManger::show_Emp()
{
	system("clear");
	if(this->m_FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
	}
	else
	{
		for(int i=0;i<this->m_EmpNum;i++)
		{
			this->m_EmpArry[i]->show_info();
		}
	}
}

void WorkerManger::delete_Emp()
{
	cout<<"请输入所删除职工的编号:"<<endl;
	int id;
	cin>>id;
	system("clear");
	int index=this->IsExit(id);
	if(index==-1)
	{
		cout<<"查无此人"<<endl;
	}
	else
	{
		for(int i=index;i<this->m_EmpNum-1;i++)
		{
			this->m_EmpArry[i]=this->m_EmpArry[i+1];
		}
		this->m_EmpNum--;
		cout<<"删除成功！"<<endl;
		this->save();
	}
}

int WorkerManger::IsExit(int id)
{
	int index=-1;
	for(int i=0;i<this->m_EmpNum;i++)
	{
		if(this->m_EmpArry[i]->m_id==id)
		{
			index=i;
			break;
		}
	}
	return index;
}

void WorkerManger::find_Emp()
{
	cout<<"请输入所查找职工的编号:"<<endl;
	int id;
	cin>>id;
	system("clear");
	int ret=this->IsExit(id);
	if(ret!=-1)
	{
		this->m_EmpArry[ret]->show_info();
	}
	else
	{
		cout<<"查无此人！"<<endl;
	}
}

void WorkerManger::modify_Emp()
{
	cout<<"请输入所修改职工的编号:"<<endl;
	int id;
	cin>>id;
	system("clear");
	int ret=this->IsExit(id);

	cout<<"请输入新职工编号:"<<endl;
	cin>>this->m_EmpArry[ret]->m_id;
	cout<<"请输入新职工姓名:"<<endl;
	cin>>this->m_EmpArry[ret]->m_name;
	cout<<"请输入新职工岗位:\n1.普通职工\n2.经理\n3.老板"<<endl;
	cin>>this->m_EmpArry[ret]->m_deptid;

	this->save();
	system("clear");
}