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
		printf("��������");
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

void YangHuiTriangle(QueueSq * Q)
{
	int line = 0;
	printf("������������ǵ�����: \n");
	scanf("%d", &line);
	InitQueue(Q,line+2);//��ʼ������
	EnQueue(Q, 1);//��һ��Ԫ�����
	for (int n = 2; n <= line; n++)//���ö��е�n-1�в�����n�е��м�n-2��Ԫ��
	{
		EnQueue(Q, 1);//��n�еĵ�һ��Ԫ�����
		for (int j = 1; j <= n - 2; j++)
		{
			int temp = OutQueue(Q);
			printf("%d ", temp);//��ӡn-1��Ԫ��
			int qhead = PeekQueue(Q);
			temp = temp + qhead;//����n-1�в�����n��
			EnQueue(Q, temp);
		}
		printf("%d ", OutQueue(Q));//��ӡn-1�е����һ��Ԫ��
		EnQueue(Q, 1);//��n�е����һ��Ԫ�����
		printf("\n");
	}

		while (!EmptyQueue(Q))
		{
			printf("%d ", OutQueue(Q));
		}
}

//������
int main()
{
	QueueSq  q;
	YangHuiTriangle(&q);

	return 0;
}



