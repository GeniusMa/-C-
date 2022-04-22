#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size;
};

void show_menu()
{
	cout<<"****************************"<<"\n"<<"*****   1.添加联系人   *****"<<"\n"
	<<"*****   2.显示联系人   *****"<<"\n"<<"*****   3.删除联系人   *****"<<"\n"
	<<"*****   4.查找联系人   *****"<<"\n"<<"*****   5.修改联系人   *****"<<"\n"
	<<"*****   6.清空联系人   *****"<<"\n"<<"*****   0.退出通讯录   *****"<<"\n"
	<<"****************************"<<"\n"<<ends;	
}

void add_person(Addressbooks*abs)
{
	if(abs->m_size==MAX)
	{
		return;
	}
	else{
		cout<<"请输入姓名：\n"<<ends;
		cin>>abs->personArray[abs->m_size].m_name;
		cout<<"输入："<<abs->personArray[abs->m_size].m_name<<"\n"<<ends;

		cout<<"请输入性别：\n"<<"1----男  2----女\n"<<ends;
		int sex;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				abs->personArray[abs->m_size].m_sex=sex;
				cout<<"输入："<<abs->personArray[abs->m_size].m_sex<<"\n"<<ends;
				break;
			}
			cout<<"输入有误，请重新输入：\n"<<ends;
		}

		cout<<"请输入年龄：\n"<<ends;
		cin>>abs->personArray[abs->m_size].m_age;
		cout<<"输入："<<abs->personArray[abs->m_size].m_age<<"\n"<<ends;

		cout<<"请输入电话号码：\n"<<ends;
		cin>>abs->personArray[abs->m_size].m_phone;
		cout<<"输入："<<abs->personArray[abs->m_size].m_phone<<"\n"<<ends;

		cout<<"请输入地址：\n"<<ends;
		cin>>abs->personArray[abs->m_size].m_addr;
		cout<<"输入："<<abs->personArray[abs->m_size].m_addr<<"\n"<<ends;

		abs->m_size++;
		cout<<"添加成功\n"<<ends;
		system("clear");
	}
}

void show_person(Addressbooks abs,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"\t姓名："<<abs.personArray[i].m_name<<"\n"<<ends;
		// if(abs.personArray[i].m_sex==1)
		// {
		// 	cout<<"\t性别：男"<<"\n"<<ends;
		// }
		// if(abs.personArray[i].m_sex==2)
		// {
		// 	cout<<"\t性别：女"<<"\n"<<ends;
		// }
		cout<<"\t性别："<<(abs.personArray[i].m_sex==1?"男":"女")<<"\n"<<ends;
		cout<<"\t年龄："<<abs.personArray[i].m_age<<"\n"<<ends;
		cout<<"\t电话号码："<<abs.personArray[i].m_phone<<"\n"<<ends;
		cout<<"\t地址："<<abs.personArray[i].m_addr<<"\n"<<ends;
		cout<<"\n"<<ends;
	}
}

int find_person(string name,Addressbooks abs)
{
	for(int i=0;i<abs.m_size;i++)
	{
		if(abs.personArray[i].m_name==name)
		{
			return i;
		}
	}
	return -1;
}

void delete_person(string name,Addressbooks*abs)
{
	int ret=find_person(name,*abs);
	if(ret==-1)
	{
		cout<<"查无此人！\n"<<ends;
		return;
	}
	else
	{
		for(int i=ret;i<abs->m_size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];

		}
		abs->m_size--;
		cout<<"删除成功！\n"<<ends;
	}
}

void change_person(Addressbooks*abs)
{
	string name;
	cout<<"请输入要修改的联系人："<<ends;
	cin>>name;
	int ret=find_person(name,*abs);
	if(ret==-1)
		cout<<"查无此人！\n"<<ends;
	else
	{
		cout<<"请输入名字：\n"<<ends;
		cin>>abs->personArray[ret].m_name;

		cout<<"请输入要修改的联系人性别："<<ends;
		int sex;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				abs->personArray[ret].m_sex=sex;
				break;
			}
			cout<<"输入有误，请重新输入：\n"<<ends;
		}

		cout<<"请输入年龄：\n"<<ends;
		cin>>abs->personArray[ret].m_age;

		cout<<"请输入电话号码：\n"<<ends;
		cin>>abs->personArray[ret].m_phone;

		cout<<"请输入地址：\n"<<ends;
		cin>>abs->personArray[ret].m_addr;

		int j = find_person(abs->personArray[ret].m_name,*abs);
		cout<<"联系人为第"<<j+1<<"人\n"
				<<"其姓名为:"<<abs->personArray[j].m_name<<"\n"
	   			<<"其性别为："<<(abs->personArray[j].m_sex==1?"男":"女")<<"\n"
	   			<<"其年龄为："<<abs->personArray[j].m_age<<"\n"
	   			<<"其电话号码为："<<abs->personArray[j].m_phone<<"\n"
	   			<<"其地址为："<<abs->personArray[j].m_addr<<"\n"<<ends;
	}
}

void clean_all(Addressbooks*abs)
{
	char makesure;
	cout<<"确认全部删除吗！Y--yes N--no"<<"\n"<<ends;
	cin>>makesure;
	if(makesure=='Y'||makesure=='y')
	{
		abs->m_size=0;
		cout<<"清除成功！\n"<<ends;
		system("clear");
	}
	else
		return;
}

int main()
{
	Addressbooks abs;
	abs.m_size=0;
	int select;
	int i;
	string name;
	while(true)
	{
		show_menu();
		cin>>select;
		switch(select)
		{
		case 1://添加联系人
			add_person(&abs);
			break;
		case 2://显示联系人
			show_person(abs,abs.m_size);
		   	break;
	   	case 3://删除联系人
	   		cout<<"请输入联系人名字："<<ends;
	   		cin>>name;
	   		delete_person(name,&abs);
		   	break;
	   	case 4://查找联系人
	   		cout<<"请输入联系人名字："<<ends;
	   		cin>>name;
	   		i=find_person(name,abs);
	   		if(i!=-1)
	   			cout<<"联系人为第"<<i+1<<"人\n"
	   			<<"其性别为："<<(abs.personArray[i].m_sex==1?"男":"女")<<"\n"
	   			<<"其年龄为："<<abs.personArray[i].m_age<<"\n"
	   			<<"其电话号码为："<<abs.personArray[i].m_phone<<"\n"
	   			<<"其地址为："<<abs.personArray[i].m_addr<<"\n"<<ends;
	   		else
	   			cout<<"查无此人！\n"<<ends;
		   	break;
		case 5://修改联系人
			change_person(&abs);
		   	break;
		case 6://清空联系人
			clean_all(&abs);
		   	break;
		case 0://退出通讯录
		   	cout<<"欢迎下次使用"<<"\n"<<ends;
		   	return 0;
		    break;
		default:
			cout<<"请输入正确指令"<<"\n"<<ends;
		   	break;
		};
	}
}