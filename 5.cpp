#include <iostream>
#include <string>
using namespace std;

//面向对象

// int* func()
// {
// 	//指针本质是一个局部变量，放在栈上，指针指向的数据放在堆上。
// 	return new int(10);//开辟到堆区
// }

// int main()
// {
	
// 	//代码区：存放CPU执行的机器指令，只读，共享
// 	//全局区：全局变量、静态变量、字符串常量、全局常量存放在此，该区域数据在程序结束后由操作系统释放
// 	//堆区：由程序员分配释放，若程序员不释放，程序结束时由系统释放
// 	//栈区：有编译器分配释放，存放函数参数值，局部变量。
	
// 	int*p=func();
// 	cout<<*p<<"\n"<<ends;
// 	delete p;
// 	cout<<*p<<"\n"<<ends;
// 	return 0;
// }

void func2()
{
	int *p=new int[10];
	for(int i=0;i<10;i++)
	{
		*(p+i)=i;
	}
	for(int i=0;i<10;i++){
		cout<<*(p+i)<<"\n"<<ends;
	}
	delete[] p;
}

int main()
{
	func2();

	return 0;
}



