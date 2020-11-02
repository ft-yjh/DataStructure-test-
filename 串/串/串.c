#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 40//串的最大长度

typedef struct
{
	char ch[MAXLEN];//存储字符串的一维数组
	int len;//字符串长度
}SString;

//生成一个字符串s
void StrAssign(SString * S, char * s1)
{
	int len = strlen(s1);
	if (S != NULL)
	{
		for (int i = 0 ; i < len; i++)
		{ 
			S->ch[i] = s1[i];
		}
	
	}
	S->len = len;
}

//在串s的pos位置插入串T
void StrInsert(SString * S, int pos, SString * T)
{
	int i = 0;
	//判断pos插入位置是否合理
	if (pos < 0 || pos > MAXLEN)
	{
		//插入位置不合理
		printf("插入位置不合理\n");
		exit(1);
	}

	if ((S->len + T->len) <= MAXLEN)//串s与串t的总长度小于MAXLEN
	{
		for (i = S->len + T->len - 1; i >= pos + T->len; i--)
		{
			S->ch[i] = S->ch[i - T->len];
		}
		for (i = 0; i < T->len; i++)
		{
			S->ch[pos + i] = T->ch[i];
		}
		S->len += T->len;
	}
	else if ((pos + T->len) <= MAXLEN)//串s插入位置后部分字符溢出
	{
		for (i = MAXLEN - 1; i >= pos + T->len; i--)
		{
			S->ch[i] = S->ch[i - T->len];
		}
		for (i = 0; i < T->len; i++)
		{
			S->ch[pos + i] = T->ch[i];
		}
		S->len = MAXLEN;
	}
	else//串s插入位置后全部溢出,部分t溢出
	{
		for (i = 0; i < MAXLEN - pos; i++)
		{
			S->ch[pos + i] = T->ch[i];
		}
		S->len = MAXLEN;
	}
}

//在串s的pos位置处删除length个长度的字符
void StrDelete(SString * S, int pos, int length)
{
	int i = 0;
	//if (pos < 0);
	//{
	//	//删除位置不合理
	//	printf("删除位置不合理\n");
	//	exit(1);
	//}
	for (i = pos + length; i < S->len; i++)
	{
		S->ch[i - length] = S->ch[i];
	}
	S->len = S->len - length;
}

//由串T复制得字符串S
void StrCopy(SString * S, SString * T)
{
	for (int i = 0; i < T->len; i++)
	{
		S->ch[i] = T->ch[i];
	}
	S->len = T->len;
}

//判断串是否为空 若为空 返回1 
int StrEmpty(SString S)
{
	if (S.len == 0)
	{
		return 1;
	}
	else
		return 0;
}

//字符串比较 S>T >0  == =0 < <0
int StrCompare(SString * S, SString * T)
{
	for (int i = 0; i < S->len && i < T->len; i++)
	{
		if (S->ch[i] != T->ch[i])
		{
			return (S->ch[i] - T->ch[i]);
		}
	}
	return (S->len - T->len);
}

//求串的长度
int StrLength(SString * S)
{
	return (S->len);
}

//清空串为空串
void StrClear(SString * S)
{
	S->len = 0;
}

//字符串的连接
void StrCat(SString * S, SString * T)
{
	if ((S->len + T->len) < MAXLEN)
	{
		for (int i = S->len; i < S->len + T->len; i++)
		{
			S->ch[i] = T->ch[i - S->len];
		}
	}
	S->len = S->len + T->len;
}

//返回S的子串
void SubString(char  sub[],SString s, int pos, int len)
{
	
	{ int i;
	
	
		for (i = 0; i < len; i++) sub[i] = s.ch[i + pos ];
		 return(1);
	}
	

}



//串s中存在和串t相同的子串,返回s中自pos之后第一次出现的位置
int StrIndex(SString * S, int pos, SString * T)
{
	int start = 0;
	int i = 0;
	int j = 0;
	start = pos;
	i = start;
	while (i < S->len && j < T->len)
	{
		if (S->ch[i] == T->ch[i])
		{
			i++;
			j++;
		}
		else
		{
			start++;
			i = start;
			j = 0;
		}
	}
	if (j >= T->len)
	{
		return (start);
	}
	else
	{
		return -1;
	}
}

//打印串
void ShowStr(SString * S)
{
	for (int i = 0; i < S->len; i++)
	{
		printf("%c", S->ch[i]);
	}
	printf("\n");
}

int main()
{
	SString s;
	char * s1 = "yajing";
	StrAssign(&s, s1);
	ShowStr(&s);

	SString t;
	char * t1 = "ng";
	StrAssign(&t, t1);
	ShowStr(&t);

	StrInsert(&s, 2, &t);
	ShowStr(&s);
	StrInsert(&s, 2, &t);
	ShowStr(&s);

	printf("%d\n", StrLength(&s));//14
	
	StrDelete(&s,2,2);
	ShowStr(&s);

	SString temp;
	StrCopy(&temp, &s);
	ShowStr(&s);
	StrClear(&temp);
	int len = StrEmpty(temp);
	printf("%d\n", len);

	SString s2;
	char * s3 = "hua";
	StrAssign(&s2, s3);
	ShowStr(&s2);
	StrCat(&s, &s2);
	ShowStr(&s);
	ShowStr(&t);

	printf("%d %d ", StrLength(&s), StrLength(&s2));
	printf("%d\n",StrIndex(&s,2, &s2));

	char sub[5] = { 0 };
	SubString(sub,s, 8, 3);
	for (int i = 0; i < strlen(sub); i++)
	{
		printf("%c", sub[i]);
	}
	

}