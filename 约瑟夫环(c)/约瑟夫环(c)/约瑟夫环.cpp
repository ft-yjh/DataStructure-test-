//
////////Լɪ��Joeph�������һ�������ǣ����Ϊ1, 2, ��, n��n���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ������(������)��һ��ʼ��ѡһ����������Ϊ��������ֵm���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ��������m���˳��У�������������Ϊ�µ�mֵ��������˳ʱ�뷽���ϵ���һ���˿�ʼ���´�1�����������ȥ��ֱ��������ȫ������Ϊֹ�������һ�������������˳��
////////����Ҫ�����õ���ѭ������洢�ṹģ��˹��̣����ճ��е�˳��ӡ�����˵ı�š�
////////�������ݣ�m�ĳ�ֵΪ20��n = 7�����룺3��1��7��2��4��8��4
////////��ȷ����� 6��1��4��7��2��3��5
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//#define ELE int
//typedef struct list		//����
//{
//	ELE data;
//	int seq;
//	struct list* next;
//}node, *pnode;
//
//int menu()//�˵�
//{
//	int n;
//	printf("1:����Լɪ��\n");
//	printf("2:�鿴ÿ���˵�����\n");
//	printf("3:��ʼ��ȡ����\n");
//	printf("0:�˳�\n");
//	scanf("%d", &n);
//	while (n < 0 || n>3)
//	{
//		printf("��Χ������������!\n");
//		scanf("%d", &n);
//	}
//	return n;
//}
//
//void free_list(pnode head)
//{//��������
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
//pnode creat_list(pnode head)//����ѭ������
//{
//	int n, i;
//	pnode p = NULL;
//	free_list(head);//����֮ǰ��������һ�ε�����
//	printf("������Ҫ����������:");
//	scanf("%d", &n);
//	while (n <= 0)
//	{
//		printf("��������Ϊ1,����������\n");
//		scanf("%d", &n);
//	}
//	head = (pnode)malloc(sizeof(node));
//	p = head;
//	for (i = 1; i < n; i++)
//	{
//		printf("�����%d���˵�����:", i);
//		scanf("%d", &p->data);
//		p->seq = i;
//		p->next = (pnode)malloc(sizeof(node));
//		p = p->next;
//	}
//	printf("�����%d���˵�����:", i);
//	scanf("%d", &p->data);
//	p->seq = n;
//	p->next = head;
//	return head;
//}
//
//void show_list(pnode head)//�������Ԫ��
//{
//	pnode p = head;
//	if (p == NULL)
//	{
//		printf("���κ�Ԫ��\n");
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
//pnode kill_list(pnode head)//��ʼ��ȡ����
//{
//	int n, i;
//	pnode p = head;
//	pnode q = head;
//	if (head == NULL)
//	{
//		printf("���κ���\n");
//		return NULL;
//	}
//	printf("�����ʼ����:");
//	scanf("%d", &n);
//	while (n <= 1)
//	{
//		printf("����Ϊ2\n");
//		scanf("%d", &n);
//	}
//
//	if (head->next == head)//���ֻ��һ��Ԫ��
//	{
//		printf("%d", head->seq);
//		return head;
//	}
//	do
//	{
//		for (i = 1; i < n; i++)//ѭ��n�� 
//		{
//			q = p;
//			p = p->next;
//		}
//		q->next = p->next;
//		printf("%d\t", p->seq);//������
//		n = p->data;//�µ�����
//		free(p);//�ͷŸýڵ�
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