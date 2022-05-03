#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
ofstream：写操作
ifstream：读操作
fstream：读写操作

ios::in//为读文件而打开文件
ios::out//为写文件而打开文件
ios::ate//初始位置：文件尾 
ios::app//追加方式写文件
ios::trunc//如果文件存在先删除，再创建
ios::binary//二进制方式
*/

// int main()//写文件
// {
// 	ofstream ofs;
// 	ofs.open("/home/robot114/learning_C++/test.txt",ios::out);
// 	ofs<<"姓名：张三"<<endl;
// 	ofs<<"性别：男"<<endl;
// 	ofs.close();
// 	return 0;	
// }



// int main()//读文件
// {
// 	char buf[1024]={0};
// 	ifstream ifs;
// 	ifs.open("/home/robot114/learning_C++/test.txt",ios::in);
// 	if(!ifs.is_open())
// 	{
// 		cout<<"文件打开失败"<<endl;
// 		return 0;
// 	}
// 	// while(ifs>>buf)
// 	// {
// 	// 	cout<<buf<<endl;
// 	// }


// 	// while(ifs.getline(buf,sizeof(buf)))
// 	// {
// 	// 	cout<<buf<<endl;
// 	// }


// 	// string buff;
// 	// while(getline(ifs,buff))
// 	// {
// 	// 	cout<<buff<<endl;
// 	// }


// 	char c;
// 	while((c=ifs.get())!=EOF)
// 	{
// 		cout<<c;
// 	}



//  ifs.close();
// 	return 0;
// }




class Person
{
public:
	char m_name[64];
	int m_age;
};

// int main()
// {
// 	Person p={"张三",18};
// 	ofstream ofs;
// 	ofs.open("Person.txt",ios::out|ios::binary);
// 	ofs.write((const char*)&p,sizeof(Person));
// 	ofs.close();
// 	return 0;
// }

int main()
{
	Person p;
	ifstream ifs;
	ifs.open("Person.txt",ios::in|ios::binary);
	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return 0;
	}
	ifs.read((char*)&p,sizeof(Person));
	cout<<p.m_name<<endl;
	cout<<p.m_age<<endl;
	return 0;
}
