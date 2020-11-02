#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int i = 1;//记录步数

void move(int n, char a, char c)//显示移动路径
{
	printf("第%d步:把第%d个盘子%c--->%c\n", i++, n, a, c);
}

void Hanoi(int n, char a, char b, char c)//汉诺塔递归算法
{
	if (n == 1)//一个盘子, 直接a -> c
	{
		move(n, a, c);
	}
	else
	{
		Hanoi(n-1, a, c, b);//a上的n-1移动到b上
		move(n, a, c);//最后一个盘子移动到测上
		Hanoi(n-1, b, a, c);//b上的n-1个盘子移动到c上
	}
}
int main()
{
	int num = 0;
	printf("请输入盘子的个数\n");
	scanf("%d", &num);
	Hanoi(num, 'A', 'B', 'C');

	return 0;
}