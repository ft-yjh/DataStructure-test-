#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//ѭ�����в���ʧһ���ռ�ȫ�����ܵõ�����,����һ����־��tag,
//��tagΪ0��1������ͷβָ����ͬʱ�Ķ���״̬,��д�˽ṹ��Ӧ�����������㷨
#define MAXSIZE 50
typedef int QueueElementType;
typedef struct
{
	QueueElementType element[MAXSIZE];//���е�Ԫ�ؿռ�
	QueueElementType front;//ͷָ��
	QueueElementType rear; //βָ��
	QueueElementType tag;  //��־λ,���Ϊ1,����Ϊ0
}SeqQueue;

//���
void EnQueue(SeqQueue * Q, QueueElementType x)
{
	//����
	if (Q->front == Q->rear && Q->tag == 1)
	{
		//��������
		printf("��������\n");
		exit(1);
	}
	Q->element[Q->rear] = x;
	Q->rear = Q->rear + 1;//βָ�����
	Q->tag = 1;//��ӱ�־λ��ֵΪ1
}

//����
QueueElementType OutQueue(SeqQueue *Q)
{
	//�п�
	if (Q->front == Q->rear && Q->tag == 0)
	{
		//����Ϊ��
		printf("����Ϊ��\n");
		exit(1);
	}
	Q->front = Q->front + 1;//��ͷָ�����
	Q->tag = 0;//���ӱ�־λΪ0
	return(Q->element[Q->front]);

}
