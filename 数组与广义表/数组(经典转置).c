#include<stdio.h>
//ϵ��������Ԫ���Ķ���
#define MAXSIZE 1000
#define M 6
#define N 7


//ϡ�����ת�õľ����㷨
//void TransMatrix(int source[M][N], int dest[N][M])
void TransMatrix(int (*source)[N], int (*dest)[M])
{
	int i = 0;
	int j = 0;
	//��ά���� 
	for ( i = 0; i < M; i++)
	{
		for ( j = 0; j < N; j++)
		{
			dest[j][i] = source[i][j];
		}
	}
	//��ӡԭ����
	printf("��ӡԭ����:\n");
	for ( i = 0; i < M; i++)
	{
		for ( j = 0; j < N; j++)
		{
			printf("%d\t", source[i][j]);
		}
		printf("\n");
	}
	
	//��ӡת�þ��� 
	printf("��ӡת�þ���:\n");
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
  
