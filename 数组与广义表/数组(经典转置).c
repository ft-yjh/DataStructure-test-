#include<stdio.h>
//系数矩阵三元组表的定义
#define MAXSIZE 1000
#define M 6
#define N 7


//稀疏矩阵转置的经典算法
//void TransMatrix(int source[M][N], int dest[N][M])
void TransMatrix(int (*source)[N], int (*dest)[M])
{
	int i = 0;
	int j = 0;
	//二维数组 
	for ( i = 0; i < M; i++)
	{
		for ( j = 0; j < N; j++)
		{
			dest[j][i] = source[i][j];
		}
	}
	//打印原矩阵
	printf("打印原矩阵:\n");
	for ( i = 0; i < M; i++)
	{
		for ( j = 0; j < N; j++)
		{
			printf("%d\t", source[i][j]);
		}
		printf("\n");
	}
	
	//打印转置矩阵 
	printf("打印转置矩阵:\n");
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < M; j++)
		{
			printf("%d\t", dest[i][j]);
		}
		printf("\n");
	}
	
}

 
int main()
{
	
	int source[M][N] = {{0,12,9,0,0,0,0}, {0,0,0,0,0,0,0}, {-3,0,0,0,0,14,0},
	                   { 0,0,24,0,0,0,0}, {0,18,0,0,0,0,0}, {15,0,0,-7,0,0,0}}; 
	int dest[N][M] = {0};
	TransMatrix(source, dest);
}
  
