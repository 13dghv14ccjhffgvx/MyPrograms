#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//定义一个学生
/*

学号
姓名
性别
班级
年龄
身高
体重
是否单身
三围
成绩

*/

typedef struct _Student
{
	int stunum;			//学号
	char name[20];		//姓名
	char sex[4];		//性别
	float chinese;		//语文成绩
	float math;			//数学成绩
	float english;		//英语成绩
}Student;


//链表
//单链表：
//链表：就像是一列火车，火车头、车厢
//许许多多的节点组成
//

//节点
typedef struct _Node
{
	Student stu;				//数据域
	struct _Node* next;			//指针域
}Node;

Node* g_pStudentList=NULL;		//学生链表

//欢迎
void Welcome();
//录入学生信息
void InputStudent();
//打印学生信息
void PrintStudent();

int main()
{
	while (1)
	{
		//欢迎
		Welcome();

		//接受键盘的输入
		//scanf("");
		//getchar()
		//读取一个字符
		char ch = getch();

		switch (ch)
		{
		case '1'://录入学生信息
			InputStudent();
			break;
		case '2'://打印学生信息
			PrintStudent();
			break;
		case '3'://查找学生信息
			break;
		case '4'://删除学生信息
			break;
		case '5'://修改学生信息
			break;
		case '6'://退出系统
			printf("Bye 了 Bye ~~~\n");
			return 0;
		}

	}
	

	return 0;
}
//欢迎
void Welcome()
{
	printf("**************************************************\n");
	printf("*                                                *\n");
	printf("*          欢迎使用高校学生成绩管理系统          *\n");
	printf("*                                                *\n");
	printf("*               请选择您需要的功能               *\n");
	printf("*                 1.录入学生信息                 *\n");
	printf("*                 2.打印学生信息                 *\n");
	printf("*                 3.查找学生信息                 *\n");
	printf("*                 4.删除学生信息                 *\n");
	printf("*                 5.修改学生信息                 *\n");
	printf("*                 6.退 出 系 统                  *\n");
	printf("*                                                *\n");
	printf("**************************************************\n");
}

//录入学生信息
void InputStudent()
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->next = NULL;

	//输入学生姓名
	/*
	int stunum;			//学号
	char name[20];		//姓名
	char sex[4];		//性别
	float chinese;		//语文成绩
	float math;			//数学成绩
	float english;		//英语成绩
	*/
	printf("请输入学生姓名：\n");
	scanf("%s", pNewNode->stu.name);
	printf("请输入学生的学号：\n");
	scanf("%d", &pNewNode->stu.stunum);
	printf("请输入学生的性别:\n");
	scanf("%s", pNewNode->stu.sex);
	printf("请输入学生的语文成绩:\n");
	scanf("%f", &pNewNode->stu.chinese);
	printf("请输入学生的数学成绩:\n");
	scanf("%f", &pNewNode->stu.math);
	printf("请输入学生的英语成绩:\n");
	scanf("%f", &pNewNode->stu.english);

	//插入到链表
	if (g_pStudentList == NULL)
	{
		g_pStudentList = pNewNode;
	}
	else
	{
		pNewNode->next = g_pStudentList;
		g_pStudentList = pNewNode;
	}
	
	printf("录入学生信息成功.\n");
	system("pause");
	system("cls");
}

//打印学生信息
void PrintStudent()
{
	system("cls");

	printf("**********************************************************\n");
	printf("*                                                        *\n");
	printf("*              欢迎使用高校学生成绩管理系统              *\n");
	printf("*                                                        *\n");
	printf("* 学号\t* 姓名\t\t* 性别\t* 语文\t* 数学\t* 英语   *\n");
	printf("**********************************************************\n");
	//遍历链表
	Node* p = g_pStudentList;
	while (p)
	{
		printf("* %d\t* %s\t* %s\t* %.1f\t* %.1f\t* %.1f\t*\n", 
			p->stu.stunum,
			p->stu.name,
			p->stu.sex,
			p->stu.chinese,
			p->stu.math,
			p->stu.english
			);
		p = p->next;
	}

	printf("**********************************************************\n");
	system("pause");
	system("cls");
}

/*
兴趣？兴趣仅仅是我们的开始，
不断地找到成就感，
成就感
幸福感，4万一个月

大一：拼命学，C语言，C++，数据结构和算法，MFC, 网络编程，系统编程，Qt，多线程，多进程，Linux高性能服务器开发，MySQL，Linux内核
大二：竞赛 蓝桥杯，ACM，电子设计大赛，考证：国家软考证书、软件架构师、软件设计师、程序员证书，外包
大三：考研 + 实习
大四：直接上岗, 一万，2万一个月

8-9个月的时间，一律给你终身制
VIP，从0开始一步一步的来学习
VIP同学，公开课（这一次讲座），我的时间的安排，VIP课程安排，
入班的同学，

大学学费：6000，
大学老师：念ppt ，从来没写过代码，复制到编译器，甚至出错了，还解决不了

民办大学：一年学费2万一年

大学里面的学费晶晶有味，毫不犹豫，但凡有一个在这里跟他讲解真正的技术的，真本事的，排斥，


有共同价值观的人：

圈子：有共同志向的人在一起， 你也会变得优秀。

技术；

那什么和别人竞争：：：
什么都是  短板

要学历没学历
要技术没技术
不努力，还不上心
别人讲的你还不听。

*/