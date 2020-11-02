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
	if (CL)
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
		if (!s)
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

void PrintNum(ClList * CL, int len)
{
	int i = 0;
	ClList * p;
	ClList * del;
//	p = (ClList *)malloc(sizeof(ClList));
//	del = (ClList *)malloc(sizeof(ClList));

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

void DestroyClList(ClList * CL)
{
	if (CL)
	{
		free(CL) ;
	}
}



int main()
{
	int init_num; 
	ClList cl;
	printf("请输入人的数量:\n");
	scanf("%d", &init_num); 
	CreateClList(&cl);
	InsertCL(&cl, init_num);
	PrintNum(&cl,init_num);
	
}

