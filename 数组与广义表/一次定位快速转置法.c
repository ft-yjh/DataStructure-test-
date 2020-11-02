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
void FastTransposeTSMatrix(TSMatrix A, TSMatrix * B)
{
	int col = 0;
	int t = 0;
	int p = 0;
	int q = 0;
	int num[MAXSIZE];
	int position[MAXSIZE];
	
	B->len = A.len;
	B->m = A.m;
	B->n = A.n;
	
	if (B->len)
	{
		for (col = 1; col <= B->len; col++)
		num[col] = 0;
		for (t = 1; t <= B->len; t++)
		num[A.data[t].col]++;//�±����������ÿһ�еķ���Ԫ�صĸ���
		position[1] = 1;
		for (col = 2; col <= A.n; col++)
		position[col] = position[col - 1] + num[col - 1];
		
		for (p = 1; p <= A.len; p++)
		{
			col = A.data[p].col;
			q = position[col];
			B->data[q].row = A.data[p].col;
			B->data[q].col = A.data[p].row;
			B->data[q].e = A.data[p].e; 
			position[col]++;
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
	FastTransposeTSMatrix(a, &b);
	
	printf("ת�ú����Ԫ��:\n"); 
	for (i = 1; i <= a.len; i++)
	{
		printf("��:%d ��:%d ֵ:%d\n", b.data[i].row, b.data[i].col, b.data[i].e);
	}
	return 0;
}
  
