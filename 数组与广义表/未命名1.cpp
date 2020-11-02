#include<iostream>
#include<cstring>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE  100 //存储空间初始分配量 
#define STACK_INCREASEMENT  10
using namespace std;
typedef struct {
	char* base;
	char* top;
	int stacksize;//当前已经分配的存储空间
}SqStack;

//构造一个空栈
void InitStack(SqStack& S) {
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

//插入元素作为新的栈顶元素
void Push(SqStack& S, char a) {
	//栈满，追加存储空间
	if (S.top - S.base > S.stacksize) {
		S.base = (char*)realloc(S.base, (S.stacksize + STACK_INCREASEMENT) * sizeof(char));
		if (!S.base) exit(0);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREASEMENT;
	}
	*S.top = a;
}

//若栈不为空，则删除栈顶元素，用b取出 
void Pop(SqStack& S, char& b) {
	if (S.top == S.base)
		exit(0);
	b = *--S.top;
}

//比较
bool Compare(string s1, string s2) {
	if (s1 == s2)
		return true;
	else
		return false;
}


int main()
{
	string s;
	string ss;
	cout << "请输入一个数：" << endl;
	cin >> s;
	int length = s.length();
	SqStack mystack;
	InitStack(mystack);
	//入栈 
	for (int i = 0; i < length; i++) {
		Push(mystack, s[i]);
	}
	//出栈 
	int j = 0;
	char output;
	for (int k = 0; k < length; k++) {
		Pop(mystack, output);
		ss += output;
	}
	//判断回文数 
	bool flag = Compare(s, ss);
	if (flag)
		cout << "Right" << endl;
	else
		cout << "Wrong" << endl;
	return 0;
}
