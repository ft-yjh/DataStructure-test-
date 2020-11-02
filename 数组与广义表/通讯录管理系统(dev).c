
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



typedef struct
{
	//姓名
	char name[20];

	//电话号码
	char telnum[20];
	
	//编号
	char id[10]; 
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

    //FILE * fp; 
	ElemType e;
	int select = 0;
	Node *s;
	
	while(1)
	{
	
	printf("1.添 加 成 员\n");
	printf("其他.返 回 系 统\n");
	printf("请输入: \n"); 
	scanf("%d", &select);
	
	if (select == 1)
	{
		
		s = (Node *)malloc(sizeof(Node));
		printf("请输入姓名: \n");
		scanf("%s", e.name);
		printf("请输入电话号码: \n");
		scanf("%s", e.telnum);
		printf("请输入编号: \n");
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



//删除链表
void DelList(LinkList *L)
{
	Node * pre;
     char name[20];
     printf("请输入要删除人的姓名: \n");
	 scanf("%s", name);
	 
	 while (L->next != NULL)
	 {
	 	pre = L->next;
	 	if (strcmp(pre->data.name, name) == 0)
	 	{
	 		L->next = pre->next;
	 		printf("删除成功\n"); 
	 		system("pause");
	 		system("cls");
	 		return; 
		 }
		 
		 L = L->next;
	  }
	  printf("未找到要删除的联系人!\n");
	  system("pause");
	  system("cls");
}

//修改链表
void ModList(LinkList *L)
{
	ElemType e;
	int i = 0;
	int j = 0;
	printf("请输入你要修改的联系人编号: \n");
	scanf("%d", &i);
	
	while (L->next != NULL & j < i)
	{
		L = L->next;
	} 
	if (j = i)
	{
		printf("编号: %s\t", L->data.id);
		printf("姓名: %s\t", L->data.name);
		printf("电话号码: %s\n", L->data.telnum);
		
		printf("请输入新姓名: \n");
		 scanf("%s", e.name);
		 printf("请输入新电话号码:\n");
		 scanf("%s", e.telnum);
		 printf("请输入新编号: \n");
		 scanf("%s", e.id); 
		 
		 L->data = e;
		 printf("修改成功\n");
		 system("pause");
	     system("cls");
	     return;

	}
	printf("未找到要修改的联系人\n");
	system("pause");
	  system("cls");

	

}

//按值查找
void LocateByValue(LinkList *L)
{
	Node * p;
	char name[20];
	printf("请输入联系人姓名: ");
	scanf("%s", name);
	
	p = L->next;
	
	while(p != NULL)
	{
		if (strcmp(p->data.name, name) == 0)
		{
		printf("编号: %s\t", p->data.id);
		printf("姓名: %s\t", p->data.name);
		printf("电话号码: %s\n", p->data.telnum);
		system("pause");
		system("cls");
		return;
		}
		else
		{
			p = p->next;
		}
	}
	 printf("未找到!\n"); 
	 	system("pause");
		system("cls");
		}

//按序号查找
void LocateByNum(LinkList *L)
{
	Node * p;
	int j = 0;
	int i = 0;
	
	printf("请输入你要查找的序号: \n");
	scanf("%d", &i);
	 
	if (i <= 0)
	{
		printf("输入有误!"); 
	}
	p = L;
	
	while (p->next != NULL & j < i)
	{
		p = p->next;
		j++;
	}
	
	if (j == i)
	{
		printf("姓名: %s\t", p->data.name);
		printf("电话号码: %s\n", p->data.telnum);
		system("pause");
		system("cls");
	}
	else
	{
		printf("未找到:\n"); 
		system("pause");
		system("cls");
	}

}



//输出单链表
void PrintList(LinkList *L)
{
	//FILE *fp;
	Node *s;
	ElemType e;
/*	if ((fp = fopen("contact.txt", "r")) == NULL)
	{
		printf("打开文件失败\n"); 
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
		printf("通讯录为空\n"); 
	}
	
	while (L->next != NULL)
	{
		s = L->next;

	    printf("编号: %s\t", s->data.id);
		printf("姓名: %s\t", s->data.name);
		printf("电话号码: %s\n", s->data.telnum);

		L = L->next;
	}
}

int main()
{
	int select = 0;//你的选择
	int locateby = 0; //查找的方式 
	LinkList L;
	L.next = NULL; 
	InitList(&L);
	//CreateFromHead(&L);

	while (1)
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
			CreateFromHead(&L);
			break;
		case 3://删除联系人
		DelList(&L);
			break;
		case 4://查找联系人
		
		printf("1. 按 值 查 找\n");
		printf("else. 按姓名查找\n");
		printf("请输入你的选择: \n"); 
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
		case 5://修改联系人
		    ModList(&L);
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




