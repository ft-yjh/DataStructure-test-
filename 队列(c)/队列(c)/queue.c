#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct QueueSq
{
	ElemType * queue;  //ָ��洢���еĴ洢�ռ�
	int front, rear;   //����ָ�� ��βָ��
	int Maxsize;       //queue���鳤��
}QueueSq;

//��չ�洢�ռ亯��
void againMalloc(QueueSq * Q)
{
	ElemType *p;
	p = realloc(Q->queue, 2 * Q->Maxsize * sizeof(ElemType));//���¿����ڴ�Ϊ����ڴ�������
	if (!p)
	{
		printf("�洢�ռ�������\n");
		exit(1);
	}
	Q->queue = p;  //ʹqueueָ���µĶ��пռ�
	if (Q->rear != Q->Maxsize - 1)
	{
		for (int i = 0; i < Q->rear; i++)
		{
			Q->queue[i + Q->Maxsize] = Q->queue[i]; //ԭ���е���������ƶ�Maxsize
			Q->rear += Q->Maxsize;                  //��βָ�����Maxsize
		}
	}
	Q->Maxsize = 2 * Q->Maxsize;      //���пռ��޸�Ϊԭ����2��
	printf("�洢�ռ���Ϊ��ǰ����\n");
}

//��ʼ������
void InitQueue(QueueSq * Q, int ms)
{
	if (ms <= 0)
	{
		printf("msֵ�Ƿ�!\n");
		exit(1);//�����쳣�˳�
	}
	Q->Maxsize = ms;
	Q->queue = malloc(ms * sizeof(ElemType));
	if (!Q->queue)
	{
		printf("�ڴ�ռ�������\n");
		exit(1);
	}
	Q->front = Q->rear = 0;//�ö���Ϊ��
}

//����в���Ԫ��
void EnQueue(QueueSq * Q, ElemType x)
{
	if ((Q->rear + 1) % Q->Maxsize == Q->front) //�ӿռ���
	{
		againMalloc(Q);
	}
	Q->queue[Q->rear] = x;
	Q->rear = (Q->rear + 1) % Q->Maxsize;
}

//�Ӷ���ɾ��Ԫ�ز�����
ElemType OutQueue(QueueSq *Q)
{
	ElemType temp;
	if (Q->front == Q->rear) //����Ϊ��
	{
		exit(1);
	}
	temp = Q->queue[Q->front];//����ɾ��������
	Q->front = (Q->front + 1) % Q->Maxsize;
	return temp;
}

//��ȡ����Ԫ��,���ı����״̬
ElemType PeekQueue(QueueSq * Q)
{
	if (Q->front == Q->rear) //����Ϊ��
	{
		exit(1);
	}
	return Q->queue[Q->front];
}

//���һ�������Ƿ�Ϊ��,�����򷵻�1,���򷵻�0
int EmptyQueue(QueueSq * Q)
{
	if (Q->front == Q->rear)
	{
		return 1;
	}
	else
		return 0;
}

//���һ������Ϊ��,�ͷŶ�̬�洢�ռ�
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

//������
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