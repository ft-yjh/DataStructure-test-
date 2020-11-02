#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int QueueElemType;
typedef struct Node
{
	QueueElemType data;//数据域
	struct Node * next;//指针域
}LinkQueueNode;

typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

//链队列的初始化
void InitQueue(LinkQueue * Q)
{
	Q->front = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
	
	if (Q->front)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
	}
}

//链队列入队操作算法
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

//链队列出队操作算法
QueueElemType OutQueue(LinkQueue * Q)
{
	LinkQueueNode * p;
	if (Q->front == Q->rear)
		exit(1);
	p = Q->front->next;
	Q->front->next = p->next;//元素p出队
	if (Q->rear == p)  //队中只有一个元素
	{
		Q->rear = Q->front;
	}
	QueueElemType temp = p->data;
	free(p);
	return temp;
}

//读取队首元素
QueueElemType PeekQueue(LinkQueue * Q)
{
	if (Q->front == Q->rear)
		exit(1);
	return Q->front->next->data;
}

//判断队列是否为空 若为空 返回1 不为空 返回0
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

//清空队列
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