#include<stdio.h>
//系数矩阵三元组表的定义
#define MAXSIZE 1000
#define M 6
#define N 7
typedef struct
{
	int row;//元素的行下标 
	int col;//元素的列下标 
	int e;  //元素的值 
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];//数组 
	int m;//矩阵的行数 
	int n;//矩阵的列数 
	int len;//非零元素的个数 
}TSMatrix;

//稀疏矩阵 列序递增转置法
void TransposeTsMatrix(TSMatrix A, TSMatrix * B)
{
	int i = 0;
	int j = 0;
	int k = 0;
	B->m = A.n;
	B->n = A.m;
	B->len = A.len;
	
	if (B->len)//非零元素大于0 
	{
		j = 1;//辅助计数器,三元组B的下标值
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
	
	printf("原稀疏矩阵的三元组:\n");
	for (i = 1; i <= a.len; i++)
	{
		printf("行:%d 列:%d 值:%d\n", a.data[i].row, a.data[i].col, a.data[i].e);
	}
	TransposeTsMatrix(a, &b);
	
	printf("转置后的三元组:\n"); 
	for (i = 1; i <= a.len; i++)
	{
		printf("行:%d 列:%d 值:%d\n", b.data[i].row, b.data[i].col, b.data[i].e);
	}
}
  
