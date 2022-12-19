#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//����һ��ѧ��
/*

ѧ��
����
�Ա�
�༶
����
���
����
�Ƿ���
��Χ
�ɼ�

*/

typedef struct _Student
{
	int stunum;			//ѧ��
	char name[20];		//����
	char sex[4];		//�Ա�
	float chinese;		//���ĳɼ�
	float math;			//��ѧ�ɼ�
	float english;		//Ӣ��ɼ�
}Student;


//����
//������
//����������һ�л𳵣���ͷ������
//������Ľڵ����
//

//�ڵ�
typedef struct _Node
{
	Student stu;				//������
	struct _Node* next;			//ָ����
}Node;

Node* g_pStudentList=NULL;		//ѧ������

//��ӭ
void Welcome();
//¼��ѧ����Ϣ
void InputStudent();
//��ӡѧ����Ϣ
void PrintStudent();

int main()
{
	while (1)
	{
		//��ӭ
		Welcome();

		//���ܼ��̵�����
		//scanf("");
		//getchar()
		//��ȡһ���ַ�
		char ch = getch();

		switch (ch)
		{
		case '1'://¼��ѧ����Ϣ
			InputStudent();
			break;
		case '2'://��ӡѧ����Ϣ
			PrintStudent();
			break;
		case '3'://����ѧ����Ϣ
			break;
		case '4'://ɾ��ѧ����Ϣ
			break;
		case '5'://�޸�ѧ����Ϣ
			break;
		case '6'://�˳�ϵͳ
			printf("Bye �� Bye ~~~\n");
			return 0;
		}

	}
	

	return 0;
}
//��ӭ
void Welcome()
{
	printf("**************************************************\n");
	printf("*                                                *\n");
	printf("*          ��ӭʹ�ø�Уѧ���ɼ�����ϵͳ          *\n");
	printf("*                                                *\n");
	printf("*               ��ѡ������Ҫ�Ĺ���               *\n");
	printf("*                 1.¼��ѧ����Ϣ                 *\n");
	printf("*                 2.��ӡѧ����Ϣ                 *\n");
	printf("*                 3.����ѧ����Ϣ                 *\n");
	printf("*                 4.ɾ��ѧ����Ϣ                 *\n");
	printf("*                 5.�޸�ѧ����Ϣ                 *\n");
	printf("*                 6.�� �� ϵ ͳ                  *\n");
	printf("*                                                *\n");
	printf("**************************************************\n");
}

//¼��ѧ����Ϣ
void InputStudent()
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->next = NULL;

	//����ѧ������
	/*
	int stunum;			//ѧ��
	char name[20];		//����
	char sex[4];		//�Ա�
	float chinese;		//���ĳɼ�
	float math;			//��ѧ�ɼ�
	float english;		//Ӣ��ɼ�
	*/
	printf("������ѧ��������\n");
	scanf("%s", pNewNode->stu.name);
	printf("������ѧ����ѧ�ţ�\n");
	scanf("%d", &pNewNode->stu.stunum);
	printf("������ѧ�����Ա�:\n");
	scanf("%s", pNewNode->stu.sex);
	printf("������ѧ�������ĳɼ�:\n");
	scanf("%f", &pNewNode->stu.chinese);
	printf("������ѧ������ѧ�ɼ�:\n");
	scanf("%f", &pNewNode->stu.math);
	printf("������ѧ����Ӣ��ɼ�:\n");
	scanf("%f", &pNewNode->stu.english);

	//���뵽����
	if (g_pStudentList == NULL)
	{
		g_pStudentList = pNewNode;
	}
	else
	{
		pNewNode->next = g_pStudentList;
		g_pStudentList = pNewNode;
	}
	
	printf("¼��ѧ����Ϣ�ɹ�.\n");
	system("pause");
	system("cls");
}

//��ӡѧ����Ϣ
void PrintStudent()
{
	system("cls");

	printf("**********************************************************\n");
	printf("*                                                        *\n");
	printf("*              ��ӭʹ�ø�Уѧ���ɼ�����ϵͳ              *\n");
	printf("*                                                        *\n");
	printf("* ѧ��\t* ����\t\t* �Ա�\t* ����\t* ��ѧ\t* Ӣ��   *\n");
	printf("**********************************************************\n");
	//��������
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
��Ȥ����Ȥ���������ǵĿ�ʼ��
���ϵ��ҵ��ɾ͸У�
�ɾ͸�
�Ҹ��У�4��һ����

��һ��ƴ��ѧ��C���ԣ�C++�����ݽṹ���㷨��MFC, �����̣�ϵͳ��̣�Qt�����̣߳�����̣�Linux�����ܷ�����������MySQL��Linux�ں�
��������� ���ű���ACM��������ƴ�������֤��������֤�顢����ܹ�ʦ��������ʦ������Ա֤�飬���
���������� + ʵϰ
���ģ�ֱ���ϸ�, һ��2��һ����

8-9���µ�ʱ�䣬һ�ɸ���������
VIP����0��ʼһ��һ������ѧϰ
VIPͬѧ�������Σ���һ�ν��������ҵ�ʱ��İ��ţ�VIP�γ̰��ţ�
����ͬѧ��

��ѧѧ�ѣ�6000��
��ѧ��ʦ����ppt ������ûд�����룬���Ƶ������������������ˣ����������

����ѧ��һ��ѧ��2��һ��

��ѧ�����ѧ�Ѿ�����ζ��������ԥ��������һ��������������������ļ����ģ��汾�µģ��ų⣬


�й�ͬ��ֵ�۵��ˣ�

Ȧ�ӣ��й�ͬ־�������һ�� ��Ҳ�������㡣

������

��ʲô�ͱ��˾���������
ʲô����  �̰�

Ҫѧ��ûѧ��
Ҫ����û����
��Ŭ������������
���˽����㻹������

*/