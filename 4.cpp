#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// struct Student
// {
// 	string name;
// 	int age;
// 	int score;
// }s3;

// int main()
// {
// 	Student s1;
// 	s1.name="张三";
// 	s1.age=18;
// 	s1.score=60;

// 	Student s2={"李四",19,70};

// 	s3.name="王五";
// 	s3.age=20;
// 	s3.score=80;
// 	cout<<s1.name<<"\n"<<s1.age<<"\n"<<s1.score<<"\n"<<ends;
// 	cout<<s2.name<<"\n"<<s2.age<<"\n"<<s2.score<<"\n"<<ends;
// 	cout<<s3.name<<"\n"<<s3.age<<"\n"<<s3.score<<"\n"<<ends;
// 	return 0;
// }

// int main()
// {
// 	Student StudentArr[2]={{"张三",18,60},{"李四",19,70}};//结构体数组
// 	cout<<StudentArr[0].name<<"\n"<<StudentArr[0].age<<"\n"<<StudentArr[0].score<<"\n"<<ends;
// 	cout<<StudentArr[1].name<<"\n"<<StudentArr[1].age<<"\n"<<StudentArr[1].score<<"\n"<<ends;		
// 	return 0;
// }

// int main()
// {
// 	/*
// 	结构体指针
// 	*/
// 	Student s={"李四",19,70};
// 	Student*p=&s;
// 	cout << p->name << "\n"<<p->age<<"\n"<<p->score<<"\n"<<ends;
// 	return 0;
// }

// struct teacher{
// 	int ID;
// 	string name;
// 	int age;
// 	Student stu;
// };

// int main()
// {
// 	teacher t;
// 	t.ID=1000;
// 	t.name="老王";
// 	t.age=50;
// 	t.stu.age=18;
// 	t.stu.name="小王";
// 	t.stu.score=60;
// 	cout<<t.ID<<"\n"<<t.name<<"\n"<<t.age<<"\n"<<t.stu.age
// 	<<"\n"<<t.stu.name<<"\n"<<t.stu.score<<"\n"<<ends;
// 	return 0;
// }

// void print_student(const Student*p)
// {
// 	cout<<p->name<<ends;
// }

// int main()
// {
// 	s3.name="张三";
// 	s3.age=20;
// 	s3.score=77;
// 	print_student(&s3);
// 	return 0;
//  }















/**************************
	    教师管理学生
**************************/
struct student{
	string name_s;
	int score;
};

struct teacher{
	string name_t;
	student stu_arr[5];
};

void allocateSpace(teacher*p,int len){
	string nameSeed="ABCDE";
	for(int i=0;i<len;i++){
		(p+i)->name_t="Teacher_";
		(p+i)->name_t+=nameSeed[i];
		for(int j=0;j<5;j++){
			(p+i)->stu_arr[j].name_s="Student_";
			(p+i)->stu_arr[j].name_s+=nameSeed[j];
			int random=rand()%61+40;
			(p+i)->stu_arr[j].score=random;
		}
	}
	
}

void print_info(teacher tea_arr[],int len){
	for(int i=0;i<len;i++){
		cout<<"老师姓名:"<<tea_arr[i].name_t<<"\n"<<ends;
		for(int j=0;j<5;j++){
			cout<<"\t"<<"学生姓名:"<<tea_arr[i].stu_arr[j].name_s
			<<":"<<tea_arr[i].stu_arr[j].score<<"\n"<<ends;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	teacher tea_arr[3];
	int len=sizeof(tea_arr)/sizeof(tea_arr[0]);
	allocateSpace(tea_arr,len);
	print_info(tea_arr,len);
	
	return 0;
}