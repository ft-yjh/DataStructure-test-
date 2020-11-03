/*从键盘以此读入一个以@为结束符的字符序列，
判断此序列是否为形如"序列1 & 序列2"模式的字符序列。
其中序列1和序列2中都不含字符"&"，而且序列2是序列1的逆序列。
例如，字符序列"a+b&b+a"是属于该模式的序列，而"1+3&3-1"则不是回文。
要求设计一个程序，利用栈或者队列模拟此过程，判断输入的字符序列是否为回文，
并将判断结果输出。*/
#include<stdio.h>
#include<stdbool.h>//bool变量的头文件 
#include<stdlib.h>
#define INIT_SIZE 10
//定义栈

typedef struct
{
	char * base;//基地址 
	char * top; //top指针 
}StackLinst; 

//创建栈 
void CreateStack(StackLinst * S)
{
	S->base = (char *)malloc(INIT_SIZE * sizeof(char));
	if (!S)
	{
		exit(1);
	}
	S->top = S->base;
 } 

//入栈
void EnterStack(StackLinst * S, char *ch, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		S->top[i] = ch[i];
	}
	printf("入栈完毕!\n"); 
}

//出栈 
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
    printf("出栈完毕!\n"); 
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
	printf("请输入串的长度:\n");
	scanf("%d", &len);
	ch = (char *)malloc(len * sizeof(char));
	ch = (char *)malloc(len * sizeof(char));
	printf("请输入字符串\n");
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
