#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//循环队列不损失一个空间全部都能得到利用,设置一个标志量tag,
//以tag为0或1来区分头尾指针相同时的队列状态,编写此结构相应的入队与出队算法
#define MAXSIZE 50
typedef int QueueElementType;
typedef struct
{
	QueueElementType element[MAXSIZE];//队列的元素空间
	QueueElementType front;//头指针
	QueueElementType rear; //尾指针
	QueueElementType tag;  //标志位,入队为1,出队为0
}SeqQueue;

//入队
void EnQueue(SeqQueue * Q, QueueElementType x)
{
	//判满
	if (Q->front == Q->rear && Q->tag == 1)
	{
		//队列已满
		printf("队列已满\n");
		exit(1);
	}
	Q->element[Q->rear] = x;
	Q->rear = Q->rear + 1;//尾指针后移
	Q->tag = 1;//入队标志位赋值为1
}

//出队
QueueElementType OutQueue(SeqQueue *Q)
{
	//判空
	if (Q->front == Q->rear && Q->tag == 0)
	{
		//队列为空
		printf("队列为空\n");
		exit(1);
	}
	Q->front = Q->front + 1;//队头指针后移
	Q->tag = 0;//出队标志位为0
	return(Q->element[Q->front]);

}
