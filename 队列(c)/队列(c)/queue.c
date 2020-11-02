#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct QueueSq
{
	ElemType * queue;  //指向存储队列的存储空间
	int front, rear;   //队手指针 队尾指针
	int Maxsize;       //queue数组长度
}QueueSq;

//扩展存储空间函数
void againMalloc(QueueSq * Q)
{
	ElemType *p;
	p = realloc(Q->queue, 2 * Q->Maxsize * sizeof(ElemType));//重新开辟内存为最大内存大的两倍
	if (!p)
	{
		printf("存储空间已用完\n");
		exit(1);
	}
	Q->queue = p;  //使queue指向新的队列空间
	if (Q->rear != Q->Maxsize - 1)
	{
		for (int i = 0; i < Q->rear; i++)
		{
			Q->queue[i + Q->Maxsize] = Q->queue[i]; //原队列的内容向后移动Maxsize
			Q->rear += Q->Maxsize;                  //队尾指针后移Maxsize
		}
	}
	Q->Maxsize = 2 * Q->Maxsize;      //队列空间修改为原来的2倍
	printf("存储空间已为当前两倍\n");
}

//初始化队列
void InitQueue(QueueSq * Q, int ms)
{
	if (ms <= 0)
	{
		printf("ms值非法!\n");
		exit(1);//程序异常退出
	}
	Q->Maxsize = ms;
	Q->queue = malloc(ms * sizeof(ElemType));
	if (!Q->queue)
	{
		printf("内存空间已用完\n");
		exit(1);
	}
	Q->front = Q->rear = 0;//置队列为空
}

//向队列插入元素
void EnQueue(QueueSq * Q, ElemType x)
{
	if ((Q->rear + 1) % Q->Maxsize == Q->front) //队空间满
	{
		againMalloc(Q);
	}
	Q->queue[Q->rear] = x;
	Q->rear = (Q->rear + 1) % Q->Maxsize;
}

//从队列删除元素并返回
ElemType OutQueue(QueueSq *Q)
{
	ElemType temp;
	if (Q->front == Q->rear) //队列为空
	{
		exit(1);
	}
	temp = Q->queue[Q->front];//保留删除的数据
	Q->front = (Q->front + 1) % Q->Maxsize;
	return temp;
}

//读取队首元素,不改变队列状态
ElemType PeekQueue(QueueSq * Q)
{
	if (Q->front == Q->rear) //队列为空
	{
		exit(1);
	}
	return Q->queue[Q->front];
}

//检查一个队列是否为空,若是则返回1,否则返回0
int EmptyQueue(QueueSq * Q)
{
	if (Q->front == Q->rear)
	{
		return 1;
	}
	else
		return 0;
}

//清除一个队列为空,释放动态存储空间
void ClearQueue(QueueSq * Q)
{
	if (Q->queue != NULL)
	{
		free(Q->queue);
		Q->queue = NULL;
		Q->front = Q->rear = 0;
		Q->Maxsize = 0;
	}
}

//主函数
int main()
{
	QueueSq  q;
	int a[8] = { 3, 8, 5, 17, 9, 30, 15, 22 };
	InitQueue(&q, 5);
	for (int i = 0; i < 8; i++)
	{
		EnQueue(&q, a[i]);
	}
		printf("%d ", OutQueue(&q));
		printf("%d\n", OutQueue(&q));
		EnQueue(&q, 68);
		printf("%d ", PeekQueue(&q));
		printf("%d\n", OutQueue(&q));
		while (!EmptyQueue(&q))
		{
			printf("%d ", OutQueue(&q));
	    }
		printf("\n");
		ClearQueue(&q);


	return 0;
}