#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	int passd;
	struct Node * next;
}ClList;

void CreateClList(ClList * CL)
{
	CL = (ClList *)malloc(sizeof(ClList));
	if (CL != NULL)
	{
		CL->data = 0;
		CL->next = NULL;
	}
}

void InsertCL(ClList * CL, int n)
{
	int i = 0; 
	ClList * s;
	ClList *p;
	int password;
	p = CL;
	for ( i = 1; i <= n; i++)
	{
		s = (ClList *)malloc(sizeof(ClList));
		if (s == NULL)
		{
			exit(1);
		}
		printf("请输入第%d个密码\n", i);
		scanf("%d", &password);
		s->data = i;
		s->passd = password;
		p->next = s;
		p = p->next;
	}
	p->next = CL->next;
}

void PrintNum(ClList * CL)
{
	int i = 0;
	int len = 7;
	ClList * p;
	ClList * del;
	p = (ClList *)malloc(sizeof(ClList));
	del = (ClList *)malloc(sizeof(ClList));

	p = CL;	
	int password;
	printf("请输入初始的密码\n");
	scanf("%d", &password);
	while (len)
	{
		for ( i = 1; i < password; i++)
		{
			p = p->next;
		}
		del = p->next;
		p->next = del->next;
		password = del->passd;
		printf("%d ", del->data);
		free(del);
		len--;
	}
	
	
}

/*void PrintNum(ClList * CL)
{
	int i = 0;
	ClList * p,*s;
	ClList * del;
	p = (ClList *)malloc(sizeof(ClList));
	del = (ClList *)malloc(sizeof(ClList));
	int len=7;
	p = CL->next;	
	int password;
	printf("请输入初始的密码\n");
	scanf("%d", &password);
	while (len>0)
	{
		for ( i = 1; i < password - 1; i++)
		{
			p = p->next;
		}
		s=p->next; 
		printf("%d ", s->data);
		del = p->next;
		p->next = del->next;
		p = p->next;
		password = del->passd;
		len--;
		free(del);
	}
	
}*/

int main()
{
	ClList cl;
	CreateClList(&cl);
	InsertCL(&cl, 7);
	PrintNum(&cl);
	
}

