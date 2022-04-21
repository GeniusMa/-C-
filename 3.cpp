#include <iostream>
#include <string>
using namespace std;

// int main()
// {
// 	cout<<10%3<<"\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	int a=10;
// 	int b=a++*10;
// 	cout<<a<<"\n"<<ends;
// 	cout<<b<<"\n"<<ends;

// 	int a1=10;
// 	int b1=++a1*10;
// 	cout<<a1<<"\n"<<ends;
// 	cout<<b1<<"\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	/*
// 	！非
// 	&& 与
// 	|| 或
// 	*/
// 	int a,b;
// 	cout<<"请输入AB！\n"<<ends;
// 	cin>>a>>b;
// 	if(a&&b)
// 		cout<<"True!\n"<<ends;
// 	else
// 		cout<<"False!\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	int a,b,c;
// 	cin>>a>>b>>c;
// 	if(a>b&&a>c)
// 		cout<<"a"<<ends;
// 	else if(b>c&&b>a)
// 		cout<<"b"<<ends;
// 	else
// 		cout<<"c"<<ends;
// 	return 0;
// }

// int main()
// {
// 	int a=30,b=20,c;
// 	c=(a>b?a:b);
// 	cout<<"C="<<c<<"\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	int a=30,b=40;
// 	(a>b?a:b)=100;
// 	cout<<"a="<<a<<ends;
// 	cout<<"b="<<b<<ends;
// 	return 0;
// }

// int main()
// {
// 	int a=10;
// 	int *p=&a;
// 	cout <<p<<"="<< *p <<"\n"<<ends;
// 	cout<<sizeof(p)<<"\n"<<ends;
// 	return 0;
// }

// int main()//常量指针
// {
// 	//int*p=NULL;//空指针,不可进行访问
// 	int a=10;
// 	const int*p=&a;
// 	int b=20;
// 	p=&b;//const修饰指针的指向可以更改但，指向的值不能更改
// 	cout<<*p<<ends;
// 	return 0;
// }

// int main()//指针常量
// {
// 	int a=10,b=20;
// 	int* const p=&a;
// 	*p=20;
// 	cout<<*p<<ends;//指针指向不能修改	
// 	return 0;
// }

// int main()
// {	
// 	int a=10;
// 	const int* const p=&a;
// 	/*
// 	不能修改
// 	*/
// 	return 0;
// }

// int main()
// {
// 	int arr[10]={0,1,2,3,4,5,6,7,8,9};
// 	int*p=arr;
// 	for(int i=0;i<10;i++)
// 		cout<<"第"<<i<<"元素为:"<<*(p+i)<<"\n"<<ends;
// 	for(int i=0;i<10;i++)
// 	{
// 		cout<<"第"<<i<<"元素为:"<<*p<<"\n"<<ends;
// 		p++;
// 	}
// 	return 0;
// }

// void swap(int*p1,int*p2)
// {
// 	int temp=*p1;
// 	*p1=*p2;
// 	*p2=temp;
// }

// int main()
// {
// 	int a=10,b=20;
// 	swap(&a,&b);
// 	cout<<"a="<<a<<"b="<<b<<ends;	
// 	return 0;
// }

void bubblesort(int*p,int len)
{
	for(int i=0;i<len;i++)
		for(int j=i;j<len;j++)
			if(*(p+i)>*(p+j))
			{
				int temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
			}
}

int main()
{
	int arr[10]={9,7,6,4,3,1,8,5,2,0};
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
		cout<<arr[i]<<"\n"<<ends;
	bubblesort(arr,sizeof(arr)/sizeof(arr[0]));
	cout<<"\n"<<ends;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
		cout<<arr[i]<<"\n"<<ends;
	return 0;
}