/*�Ӽ����Դ˶���һ����@Ϊ���������ַ����У�
�жϴ������Ƿ�Ϊ����"����1 & ����2"ģʽ���ַ����С�
��������1������2�ж������ַ�"&"����������2������1�������С�
���磬�ַ�����"a+b&b+a"�����ڸ�ģʽ�����У���"1+3&3-1"���ǻ��ġ�
Ҫ�����һ����������ջ���߶���ģ��˹��̣��ж�������ַ������Ƿ�Ϊ���ģ�
�����жϽ�������*/
#include<stdio.h>
#include<stdbool.h>//bool������ͷ�ļ� 
#include<stdlib.h>
#define INIT_SIZE 10
//����ջ

typedef struct
{
	char * base;//����ַ 
	char * top; //topָ�� 
}StackLinst; 

//����ջ 
void CreateStack(StackLinst * S)
{
	S->base = (char *)malloc(INIT_SIZE * sizeof(char));
	if (!S)
	{
		exit(1);
	}
	S->top = S->base;
 } 

//��ջ
void EnterStack(StackLinst * S, char *ch, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		S->top[i] = ch[i];
	}
	printf("��ջ���!\n"); 
}

//��ջ 
void OutStack(StackLinst * S, char * ch2, int len)
{
	int i = 0;
	int j = 0;
	for (i = len - 1; i >= 0; i--)
	{
		ch2[j] = S->top[i];
		j++;
	 } 
}

bool CompareStack(char * ch, char * ch2, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (ch[i] != ch2[i])
		{
			return false;
		}
    }
    printf("��ջ���!\n"); 
    return true;
    
} 

int main()
{
	int len;
	int i = 0;
	bool flag;
	StackLinst s;
	char * ch;
	char * ch2;
	printf("�����봮�ĳ���:\n");
	scanf("%d", &len);
	ch = (char *)malloc(len * sizeof(char));
	ch = (char *)malloc(len * sizeof(char));
	printf("�������ַ���\n");
	getchar();
	
	gets(ch);
	CreateStack(&s);
	EnterStack(&s, ch, len);
	OutStack(&s, ch2, len);
	 
	flag = CompareStack(ch, ch2, len);
	
	if (flag)
	{
		printf("TRUE\n"); 
	 } 
	 else
	 {
	 	printf("FALSE\n");
	 }
	
	return 0;
}
