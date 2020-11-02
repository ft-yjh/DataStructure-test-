#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int QueueElemType;
typedef struct Node
{
	QueueElemType data;//������
	struct Node * next;//ָ����
}LinkQueueNode;

typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

//�����еĳ�ʼ��
void InitQueue(LinkQueue * Q)
{
	Q->front = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
	
	if (Q->front)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
	}
}

//��������Ӳ����㷨
void EnQueue(LinkQueue * Q, QueueElemType x)
{
	LinkQueueNode * NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));

	if (NewNode)
	{
		NewNode->next = NULL;
		NewNode->data = x;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
	}
}

//�����г��Ӳ����㷨
QueueElemType OutQueue(LinkQueue * Q)
{
	LinkQueueNode * p;
	if (Q->front == Q->rear)
		exit(1);
	p = Q->front->next;
	Q->front->next = p->next;//Ԫ��p����
	if (Q->rear == p)  //����ֻ��һ��Ԫ��
	{
		Q->rear = Q->front;
	}
	QueueElemType temp = p->data;
	free(p);
	return temp;
}

//��ȡ����Ԫ��
QueueElemType PeekQueue(LinkQueue * Q)
{
	if (Q->front == Q->rear)
		exit(1);
	return Q->front->next->data;
}

//�ж϶����Ƿ�Ϊ�� ��Ϊ�� ����1 ��Ϊ�� ����0
int EmptyQueue(LinkQueue * Q)
{
	if (Q->front == Q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//��ն���
void ClearQueue(LinkQueue * Q)
{
	LinkQueueNode * p = Q->front->next;
	while (p != NULL)
	{
		Q->front = Q->front->next;
		free(p);
	}
	Q->rear = Q->front;
}

int main()
{
	LinkQueue q;
	QueueElemType a[8] = { 3, 8, 5, 17, 9, 30, 15, 22 };
	InitQueue(&q);
	for (int i = 0; i < 8; i++)
	{
		EnQueue(&q, a[i]);
	}
	printf("%d ", OutQueue(&q));
	printf("%d \n", OutQueue(&q));
	EnQueue(&q, 68);
	printf("%d ", PeekQueue(&q));
	printf("%d \n", OutQueue(&q));

	while (!EmptyQueue(&q))
	{
		printf("%d ", OutQueue(&q));
	}
	printf("\n");
	ClearQueue(&q);
	return 0;
}