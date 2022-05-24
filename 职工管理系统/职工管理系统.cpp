#include <iostream>
#include <string>
#include "include/WorkerManger.h"
#include "include/Worker.h"
using namespace std;


int main()
{
	WorkerManger wm;
	int choice=0;
	while(true)
	{
		wm.show_menu();	
		cout<<"清选择！"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0://退出系统
			wm.Exit_System();
			break;
		case 1://添加职工
			wm.Add_Worker();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.delete_Emp();
			break;
		case 4://修改职工
			wm.modify_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://排序职工
			break;
		case 7://清空文件
			break;
		default:
			system("clear");
			cout<<"请输入正确指令!"<<endl;
			break;
		}	
	}
	return 0;
}