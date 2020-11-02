//
////////约瑟夫（Joeph）问题的一种描述是：编号为1, 2, …, n的n个人按顺时针方向围坐一圈，每人持有一个密码(正整数)。一开始任选一个正整数作为报数上限值m，从第一个人开始按顺时针方向自1开始顺序报数，报到m时停止报数。报m的人出列，将他的密码作为新的m值，从他在顺时针方向上的下一个人开始重新从1报数，如此下去，直至所有人全部出列为止。试设计一个程序求出出列顺序。
////////基本要求：利用单向循环链表存储结构模拟此过程，按照出列的顺序印出各人的编号。
////////测试数据：m的初值为20；n = 7；密码：3，1，7，2，4，8，4
////////正确结果： 6，1，4，7，2，3，5
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//#define ELE int
//typedef struct list		//链表
//{
//	ELE data;
//	int seq;
//	struct list* next;
//}node, *pnode;
//
//int menu()//菜单
//{
//	int n;
//	printf("1:创建约瑟夫环\n");
//	printf("2:查看每个人的密码\n");
//	printf("3:开始读取密码\n");
//	printf("0:退出\n");
//	scanf("%d", &n);
//	while (n < 0 || n>3)
//	{
//		printf("范围错误，重新输入!\n");
//		scanf("%d", &n);
//	}
//	return n;
//}
//
//void free_list(pnode head)
//{//销毁链表
//	pnode p = head;
//	pnode q = head;
//	if (p == NULL)
//		return;
//	if (p->next == head)
//	{
//		free(p);
//		head = NULL;
//		return;
//	}
//	while (p->next != head)
//	{
//		q = p;
//		p = p->next;
//		free(q);
//	}
//	free(p);
//	free(head);
//	head = NULL;
//}
//
//pnode creat_list(pnode head)//创建循环链表
//{
//	int n, i;
//	pnode p = NULL;
//	free_list(head);//创建之前先销毁上一次的数据
//	printf("请输入要创建的人数:");
//	scanf("%d", &n);
//	while (n <= 0)
//	{
//		printf("人数至少为1,请重新输入\n");
//		scanf("%d", &n);
//	}
//	head = (pnode)malloc(sizeof(node));
//	p = head;
//	for (i = 1; i < n; i++)
//	{
//		printf("输入第%d个人的密码:", i);
//		scanf("%d", &p->data);
//		p->seq = i;
//		p->next = (pnode)malloc(sizeof(node));
//		p = p->next;
//	}
//	printf("输入第%d个人的密码:", i);
//	scanf("%d", &p->data);
//	p->seq = n;
//	p->next = head;
//	return head;
//}
//
//void show_list(pnode head)//输出链表元素
//{
//	pnode p = head;
//	if (p == NULL)
//	{
//		printf("无任何元素\n");
//		return;
//	}
//	if (head->next == head)
//	{
//		printf("%d\n", head->data);
//		return;
//	}
//	while (p->next != head)
//	{
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("%d\t", p->data);
//	printf("\n");
//}
//
//pnode kill_list(pnode head)//开始获取密码
//{
//	int n, i;
//	pnode p = head;
//	pnode q = head;
//	if (head == NULL)
//	{
//		printf("无任何人\n");
//		return NULL;
//	}
//	printf("输入初始密码:");
//	scanf("%d", &n);
//	while (n <= 1)
//	{
//		printf("至少为2\n");
//		scanf("%d", &n);
//	}
//
//	if (head->next == head)//如果只有一个元素
//	{
//		printf("%d", head->seq);
//		return head;
//	}
//	do
//	{
//		for (i = 1; i < n; i++)//循环n次 
//		{
//			q = p;
//			p = p->next;
//		}
//		q->next = p->next;
//		printf("%d\t", p->seq);//输出序号
//		n = p->data;//新的密码
//		free(p);//释放该节点
//		p = q->next;
//	} while (p->next != p);
//	printf("%d\t", p->seq);
//	return p;
//}
//
//int main()
//{
//	int n;
//	pnode head = NULL;
//	do
//	{
//		n = menu();
//		switch (n)
//		{
//		case 1:
//			head = creat_list(head);
//			printf("\n\n");
//			break;
//		case 2:
//			show_list(head);
//			printf("\n\n");
//			break;
//		case 3:
//			head = kill_list(head);
//			system("pause");
//			printf("\n\n");
//			break;
//		}
//	} while (n != 0);
//	free_list(head);
//	return 0;
//}