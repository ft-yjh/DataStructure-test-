#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct
{
	//����
	char name[20];

	//�绰����
	char telnum[11];
}ElemType;

typedef struct Node
{
	ElemType data;

	struct Node * next;
}Node, LinkList;
//Linklist ͷָ����� Node �������нڵ��ָ��

//�˵�����
void menu()
{
	printf("******!��ӭ����ͨѶ¼����ϵͳ!******\n");
	printf("***********1 ��ʾ��ϵ��*************\n");
	printf("***********2 �����ϵ��*************\n");
	printf("***********3 ɾ����ϵ��*************\n");
	printf("***********4 ������ϵ��*************\n");
	printf("***********5 �޸���ϵ��*************\n");
	printf("***********0 �˳�ϵͳ*************\n");
	printf("************************************\n");
}

//��ʼ��������
void InitList(LinkList * L)
{
	L = (LinkList *)malloc(sizeof(Node));
	L->next = NULL;
}


//��������
void CreateFromHead(LinkList *L)
{
	Node * s[100];
	ElemType e;
	int num = 0;
	printf("������Ҫ������������\n");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		s[i] = (Node *)malloc(sizeof(Node));
		printf("����������: \n");
		scanf("%s", e.name);
		printf("������绰����: \n");
		scanf("%s", e.telnum);
		s[i]->data = e;

		s[i]->next = L->next;
		L->next = s[i];

	}

}


//��������
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
		printf("����λ�ò�����\n");
		return;
	}

	s = (Node *)malloc(sizeof(Node));
	printf("������������ݵ�����: \n");
	scanf_s("%s", e.name, sizeof(e.name));
	printf("������������ݵĵ绰����: \n");
	scanf_s("%s", e.telnum, sizeof(e.telnum));
	s->data = e;
	s->next = pre->next;
	pre->next = s;
	printf("����ɹ�\n");

}

//ɾ������
void DelList(LinkList *L, int i, ElemType e)
{

}

//�޸�����
void ModList()
{

}

//��ֵ����
void LocateByValue(LinkList *L, ElemType e)
{

}

//����Ų���
void LocateByNum(LinkList *L, int i)
{

}

//�������Ȳ���
void ListLength(LinkList *L)
{

}

//���������
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
	int select = 0;//���ѡ��
	LinkList L;
	InitList(&L);
	CreateFromHead(&L);

	while (select)
	{
		menu();
		printf("���������ѡ��\n");

		scanf("%d", &select);

		switch (select)
		{
		case 1://��ʾ��ϵ��
			PrintList(&L);
			system("pause");
			system("cls");
			break;
		case 2://�����ϵ��
			InsList(&L, 2);
			break;
		case 3://ɾ����ϵ��
			break;
		case 4://������ϵ��
			break;
		case 5://�޸���ϵ��
			break;
		case 0://�˳�ϵͳ
			printf("��ӭ�´�ʹ��\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("��������\n");
			system("pause");
			system("cls");
		}

	}
	system("pause");
	return 0;
}



