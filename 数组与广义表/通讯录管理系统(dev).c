
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



typedef struct
{
	//����
	char name[20];

	//�绰����
	char telnum[20];
	
	//���
	char id[10]; 
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

    //FILE * fp; 
	ElemType e;
	int select = 0;
	Node *s;
	
	while(1)
	{
	
	printf("1.�� �� �� Ա\n");
	printf("����.�� �� ϵ ͳ\n");
	printf("������: \n"); 
	scanf("%d", &select);
	
	if (select == 1)
	{
		
		s = (Node *)malloc(sizeof(Node));
		printf("����������: \n");
		scanf("%s", e.name);
		printf("������绰����: \n");
		scanf("%s", e.telnum);
		printf("��������: \n");
		scanf("%s", e.id);
		  
		s->data = e;

		s->next = L->next;
		L->next = s;
		
		//fp = fopen("contact.txt","");
		//fwrite(&e,sizeof(ElemType),1,fp);
		//fclose(fp);
		
		system("pause");
		system("cls");

	 
	 }
	 else
	 return; 	
     }
}



//ɾ������
void DelList(LinkList *L)
{
	Node * pre;
     char name[20];
     printf("������Ҫɾ���˵�����: \n");
	 scanf("%s", name);
	 
	 while (L->next != NULL)
	 {
	 	pre = L->next;
	 	if (strcmp(pre->data.name, name) == 0)
	 	{
	 		L->next = pre->next;
	 		printf("ɾ���ɹ�\n"); 
	 		system("pause");
	 		system("cls");
	 		return; 
		 }
		 
		 L = L->next;
	  }
	  printf("δ�ҵ�Ҫɾ������ϵ��!\n");
	  system("pause");
	  system("cls");
}

//�޸�����
void ModList(LinkList *L)
{
	ElemType e;
	int i = 0;
	int j = 0;
	printf("��������Ҫ�޸ĵ���ϵ�˱��: \n");
	scanf("%d", &i);
	
	while (L->next != NULL & j < i)
	{
		L = L->next;
	} 
	if (j = i)
	{
		printf("���: %s\t", L->data.id);
		printf("����: %s\t", L->data.name);
		printf("�绰����: %s\n", L->data.telnum);
		
		printf("������������: \n");
		 scanf("%s", e.name);
		 printf("�������µ绰����:\n");
		 scanf("%s", e.telnum);
		 printf("�������±��: \n");
		 scanf("%s", e.id); 
		 
		 L->data = e;
		 printf("�޸ĳɹ�\n");
		 system("pause");
	     system("cls");
	     return;

	}
	printf("δ�ҵ�Ҫ�޸ĵ���ϵ��\n");
	system("pause");
	  system("cls");

	

}

//��ֵ����
void LocateByValue(LinkList *L)
{
	Node * p;
	char name[20];
	printf("��������ϵ������: ");
	scanf("%s", name);
	
	p = L->next;
	
	while(p != NULL)
	{
		if (strcmp(p->data.name, name) == 0)
		{
		printf("���: %s\t", p->data.id);
		printf("����: %s\t", p->data.name);
		printf("�绰����: %s\n", p->data.telnum);
		system("pause");
		system("cls");
		return;
		}
		else
		{
			p = p->next;
		}
	}
	 printf("δ�ҵ�!\n"); 
	 	system("pause");
		system("cls");
		}

//����Ų���
void LocateByNum(LinkList *L)
{
	Node * p;
	int j = 0;
	int i = 0;
	
	printf("��������Ҫ���ҵ����: \n");
	scanf("%d", &i);
	 
	if (i <= 0)
	{
		printf("��������!"); 
	}
	p = L;
	
	while (p->next != NULL & j < i)
	{
		p = p->next;
		j++;
	}
	
	if (j == i)
	{
		printf("����: %s\t", p->data.name);
		printf("�绰����: %s\n", p->data.telnum);
		system("pause");
		system("cls");
	}
	else
	{
		printf("δ�ҵ�:\n"); 
		system("pause");
		system("cls");
	}

}



//���������
void PrintList(LinkList *L)
{
	//FILE *fp;
	Node *s;
	ElemType e;
/*	if ((fp = fopen("contact.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ��\n"); 
	} 
*/	

//	fread (&e, sizeof (ElemType), 1, fp);
   // fclose (fp);
	
	/*s->data = e;
	s->next = L->next;
	L->next = s;
 */
	
	if (L->next == NULL)
	{
		printf("ͨѶ¼Ϊ��\n"); 
	}
	
	while (L->next != NULL)
	{
		s = L->next;

	    printf("���: %s\t", s->data.id);
		printf("����: %s\t", s->data.name);
		printf("�绰����: %s\n", s->data.telnum);

		L = L->next;
	}
}

int main()
{
	int select = 0;//���ѡ��
	int locateby = 0; //���ҵķ�ʽ 
	LinkList L;
	L.next = NULL; 
	InitList(&L);
	//CreateFromHead(&L);

	while (1)
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
			CreateFromHead(&L);
			break;
		case 3://ɾ����ϵ��
		DelList(&L);
			break;
		case 4://������ϵ��
		
		printf("1. �� ֵ �� ��\n");
		printf("else. ����������\n");
		printf("���������ѡ��: \n"); 
		scanf("%d", &locateby);
		
		if (locateby == 1)
		{
			LocateByNum(&L);
		}
		else
		{
			LocateByValue(&L);
		}
		
			break;
		case 5://�޸���ϵ��
		    ModList(&L);
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




