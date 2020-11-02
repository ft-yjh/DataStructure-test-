#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct
{
	//姓名
	char name[20];

	//电话号码
	char telnum[11];
}ElemType;

typedef struct Node
{
	ElemType data;

	struct Node * next;
}Node, LinkList;
//Linklist 头指针变量 Node 单链表中节点的指针

//菜单界面
void menu()
{
	printf("******!欢迎来到通讯录管理系统!******\n");
	printf("***********1 显示联系人*************\n");
	printf("***********2 添加联系人*************\n");
	printf("***********3 删除联系人*************\n");
	printf("***********4 查找联系人*************\n");
	printf("***********5 修改联系人*************\n");
	printf("***********0 退出系统*************\n");
	printf("************************************\n");
}

//初始化单链表
void InitList(LinkList * L)
{
	L = (LinkList *)malloc(sizeof(Node));
	L->next = NULL;
}


//建立链表
void CreateFromHead(LinkList *L)
{
	Node * s[100];
	ElemType e;
	int num = 0;
	printf("请输入要创建的链表数\n");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		s[i] = (Node *)malloc(sizeof(Node));
		printf("请输入姓名: \n");
		scanf("%s", e.name);
		printf("请输入电话号码: \n");
		scanf("%s", e.telnum);
		s[i]->data = e;

		s[i]->next = L->next;
		L->next = s[i];

	}

}


//插入链表
void InsList(LinkList *L, int i)
{
	ElemType e;
	Node * pre;
	Node * s;
	int k = 0;
	if (i <= 0)
		return;
	pre = L;

	while (pre != L && k < i - 1)
	{
		pre = pre->next;
		k = k + 1;
	}
	if (pre == NULL)
	{
		printf("插入位置不合理\n");
		return;
	}

	s = (Node *)malloc(sizeof(Node));
	printf("请输入插入数据的姓名: \n");
	scanf_s("%s", e.name, sizeof(e.name));
	printf("请输入插入数据的电话号码: \n");
	scanf_s("%s", e.telnum, sizeof(e.telnum));
	s->data = e;
	s->next = pre->next;
	pre->next = s;
	printf("插入成功\n");

}

//删除链表
void DelList(LinkList *L, int i, ElemType e)
{

}

//修改链表
void ModList()
{

}

//按值查找
void LocateByValue(LinkList *L, ElemType e)
{

}

//按序号查找
void LocateByNum(LinkList *L, int i)
{

}

//求单链表长度操作
void ListLength(LinkList *L)
{

}

//输出单链表
void PrintList(LinkList *L)
{
	while (L->next != NULL)
	{

		printf("%s\t", L->data.name);
		printf("%s\n", L->data.telnum);

		L = L->next;
	}
}

int main()
{
	int select = 0;//你的选择
	LinkList L;
	InitList(&L);
	CreateFromHead(&L);

	while (select)
	{
		menu();
		printf("请输入你的选择\n");

		scanf("%d", &select);

		switch (select)
		{
		case 1://显示联系人
			PrintList(&L);
			system("pause");
			system("cls");
			break;
		case 2://添加联系人
			InsList(&L, 2);
			break;
		case 3://删除联系人
			break;
		case 4://查找联系人
			break;
		case 5://修改联系人
			break;
		case 0://退出系统
			printf("欢迎下次使用\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("输入有误\n");
			system("pause");
			system("cls");
		}

	}
	system("pause");
	return 0;
}



