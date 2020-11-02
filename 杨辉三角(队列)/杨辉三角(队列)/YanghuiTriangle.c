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
		printf("队列已满");
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

void YangHuiTriangle(QueueSq * Q)
{
	int line = 0;
	printf("请输入杨辉三角的行数: \n");
	scanf("%d", &line);
	InitQueue(Q,line+2);//初始化队列
	EnQueue(Q, 1);//第一行元素入队
	for (int n = 2; n <= line; n++)//利用队中第n-1行产生第n行的中间n-2个元素
	{
		EnQueue(Q, 1);//第n行的第一个元素入队
		for (int j = 1; j <= n - 2; j++)
		{
			int temp = OutQueue(Q);
			printf("%d ", temp);//打印n-1行元素
			int qhead = PeekQueue(Q);
			temp = temp + qhead;//利用n-1行产生第n行
			EnQueue(Q, temp);
		}
		printf("%d ", OutQueue(Q));//打印n-1行的最后一个元素
		EnQueue(Q, 1);//第n行的最后一个元素入队
		printf("\n");
	}

		while (!EmptyQueue(Q))
		{
			printf("%d ", OutQueue(Q));
		}
}

//主函数
int main()
{
	QueueSq  q;
	YangHuiTriangle(&q);

	return 0;
}



