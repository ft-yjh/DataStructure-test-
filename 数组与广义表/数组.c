#include<stdio.h>
//ϵ��������Ԫ���Ķ���
#define MAXSIZE 1000
#define M 6
#define N 7
typedef struct
{
	int row;//Ԫ�ص����±� 
	int col;//Ԫ�ص����±� 
	int e;  //Ԫ�ص�ֵ 
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];//���� 
	int m;//��������� 
	int n;//��������� 
	int len;//����Ԫ�صĸ��� 
}TSMatrix;

//ϡ����� �������ת�÷�
void TransposeTsMatrix(TSMatrix A, TSMatrix * B)
{
	int i = 0;
	int j = 0;
	int k = 0;
	B->m = A.n;
	B->n = A.m;
	B->len = A.len;
	
	if (B->len)//����Ԫ�ش���0 
	{
		j = 1;//����������,��Ԫ��B���±�ֵ
		for (k = 1; k <= A.n; k++)
		{
			for (i = 1; i <= A.len; i++)
			{
				if (A.data[i].col == k)
				{
					B->data[j].row = A.data[i].col;
					B->data[j].col = A.data[i].row;
					B->data[j].e = A.data[i].e;
					j++;
				}
			}
		 } 
	}
	
 } 

 
int main()
{
	int i = 0;
	TSMatrix a;
	TSMatrix b;
	a.m = 6;
	a.n = 7;
	a.len = 8;
	a.data[1].row = 1;
	a.data[1].col = 2;
	a.data[1].e = 12;
	
	a.data[2].row = 1;
	a.data[2].col = 3;
	a.data[2].e = 9;
	
	a.data[3].row = 3;
	a.data[3].col = 1;
	a.data[3].e = -3;
	
	a.data[4].row = 3;
	a.data[4].col = 6;
	a.data[4].e = 14;
	
	a.data[5].row = 4;
	a.data[5].col = 3;
	a.data[5].e = 24;
	
	a.data[6].row = 5;
	a.data[6].col = 2;
	a.data[6].e = 18;
	
	a.data[7].row = 6;
	a.data[7].col = 1;
	a.data[7].e = 15;
	
	a.data[8].row = 6;
	a.data[8].col = 4;
	a.data[8].e = -7;
	
	printf("ԭϡ��������Ԫ��:\n");
	for (i = 1; i <= a.len; i++)
	{
		printf("��:%d ��:%d ֵ:%d\n", a.data[i].row, a.data[i].col, a.data[i].e);
	}
	TransposeTsMatrix(a, &b);
	
	printf("ת�ú����Ԫ��:\n"); 
	for (i = 1; i <= a.len; i++)
	{
		printf("��:%d ��:%d ֵ:%d\n", b.data[i].row, b.data[i].col, b.data[i].e);
	}
}
  
