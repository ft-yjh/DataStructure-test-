#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int i = 1;//��¼����

void move(int n, char a, char c)//��ʾ�ƶ�·��
{
	printf("��%d��:�ѵ�%d������%c--->%c\n", i++, n, a, c);
}

void Hanoi(int n, char a, char b, char c)//��ŵ���ݹ��㷨
{
	if (n == 1)//һ������, ֱ��a -> c
	{
		move(n, a, c);
	}
	else
	{
		Hanoi(n-1, a, c, b);//a�ϵ�n-1�ƶ���b��
		move(n, a, c);//���һ�������ƶ�������
		Hanoi(n-1, b, a, c);//b�ϵ�n-1�������ƶ���c��
	}
}
int main()
{
	int num = 0;
	printf("���������ӵĸ���\n");
	scanf("%d", &num);
	Hanoi(num, 'A', 'B', 'C');

	return 0;
}