#pragma once
#include<iostream>
#include<string>
#include "WorkerManger.h"
using namespace std;

class Worker
{
public:
	virtual void show_info()=0;//显示个人信息
	virtual string get_deptid()=0;//获取岗位名称

	int m_id;
	string m_name;
	int m_deptid;
};
//员工
class Employer:public Worker
{
public:
	Employer(int id ,string name, int deptid);
	void show_info();
	string get_deptid();
};

Employer::Employer(int id ,string name, int deptid)
{
	this->m_id=id;
	this->m_name=name;
	this->m_deptid=deptid;
}

void Employer::show_info()
{
	cout<<"职工编号："<<this->m_id
	<<"\t职工姓名:"<<this->m_name
	<<"\t职工岗位:"<<this->get_deptid()
	<<"\t岗位职责:完成经理交给的任务"<<endl;
}

string Employer::get_deptid()
{
	return string("员工");
}

//经理
class Manager:public Worker
{
public:
	Manager(int id ,string name, int deptid);
	void show_info();
	string get_deptid();
};

Manager::Manager(int id ,string name, int deptid)
{
	this->m_id=id;
	this->m_name=name;
	this->m_deptid=deptid;
}

void Manager::show_info()
{
	cout<<"职工编号："<<this->m_id
	<<"\t职工姓名:"<<this->m_name
	<<"\t职工岗位:"<<this->get_deptid()
	<<"\t岗位职责:完成老板交给的任务"<<endl;
}

string Manager::get_deptid()
{
	return string("经理");
}


//老板
class Boss:public Worker
{
public:
	Boss(int id ,string name, int deptid);
	void show_info();
	string get_deptid();
};

Boss::Boss(int id ,string name, int deptid)
{
	this->m_id=id;
	this->m_name=name;
	this->m_deptid=deptid;
}

void Boss::show_info()
{
	cout<<"职工编号："<<this->m_id
	<<"\t职工姓名:"<<this->m_name
	<<"\t职工岗位:"<<this->get_deptid()
	<<"\t岗位职责:管理公司"<<endl;
}

string Boss::get_deptid()
{
	return string("老板");
}