#include<iostream>
#include<cstring>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE  100 //�洢�ռ��ʼ������ 
#define STACK_INCREASEMENT  10
using namespace std;
typedef struct {
	char* base;
	char* top;
	int stacksize;//��ǰ�Ѿ�����Ĵ洢�ռ�
}SqStack;

//����һ����ջ
void InitStack(SqStack& S) {
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

//����Ԫ����Ϊ�µ�ջ��Ԫ��
void Push(SqStack& S, char a) {
	//ջ����׷�Ӵ洢�ռ�
	if (S.top - S.base > S.stacksize) {
		S.base = (char*)realloc(S.base, (S.stacksize + STACK_INCREASEMENT) * sizeof(char));
		if (!S.base) exit(0);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREASEMENT;
	}
	*S.top = a;
}

//��ջ��Ϊ�գ���ɾ��ջ��Ԫ�أ���bȡ�� 
void Pop(SqStack& S, char& b) {
	if (S.top == S.base)
		exit(0);
	b = *--S.top;
}

//�Ƚ�
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
	cout << "������һ������" << endl;
	cin >> s;
	int length = s.length();
	SqStack mystack;
	InitStack(mystack);
	//��ջ 
	for (int i = 0; i < length; i++) {
		Push(mystack, s[i]);
	}
	//��ջ 
	int j = 0;
	char output;
	for (int k = 0; k < length; k++) {
		Pop(mystack, output);
		ss += output;
	}
	//�жϻ����� 
	bool flag = Compare(s, ss);
	if (flag)
		cout << "Right" << endl;
	else
		cout << "Wrong" << endl;
	return 0;
}
