	/*����һ���ö�������ʽ�洢�Ķ���������������б�������������ͺ��򣩣������������������ʾ���ϡ�
	������Ҫ�󡿴Ӽ�������һ�ö��������������У��Զ���������Ϊ�洢�ṹ��������������������б�������������ͺ��򣩣�Ȼ�󽫱��������ӡ�����Ҫ���д�ݹ�ͷǵݹ������㷨��ʵ�֡�
	���������ݡ� �������У�ABC**DE*G**F***������*��ʾ��������
	             ����������������ABCDEGF
	                       ��������CBEGDFA
	                       ��������CGEFDBA
	*/ 
	#include<stdio.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#define MAXSIZE 50
	
	typedef char BiTreeDataType;
	typedef struct Node
	{
		BiTreeDataType data;//������ 
		struct Node * left;//��ڵ� 
		struct Node * right;//�ҽڵ� 
	 } BiTree;
	 
	 typedef struct StackBiTree
	 {
	 	BiTree * t[MAXSIZE];//���ڵ� 
	 	int top;
	  } Stack;
	   
	 
	 //�������Ľ��� 
	 BiTree * CreateBiTree(BiTreeDataType * Tree, int * i)
	 {
	 	if (Tree[*i] == '*')
	 	{
	 		(*i)++;
	 		return NULL;
		 }
		 else
		 {
		 	BiTree * bit;
	 	    bit = (BiTree *)malloc(sizeof(BiTree));
	 	
		    bit->left = bit->right = NULL; 
		 
		 	bit->data = Tree[*i];
		 	(*i)++;
		 	bit->left = CreateBiTree(Tree, i);
		 	bit->right = CreateBiTree(Tree, i);
		 	return bit;
		  } 
		  
	  } 
	
	//��ʼ��
	void InitStack(Stack * s)
	{
		s = (Stack*)malloc(sizeof(Stack));
		s->top = -1;
	 }
	 
	 //�ж�ջ�Ƿ�Ϊ��
	 int StackIsEmpty(Stack * s)
	 {
	 	if (s->top == -1)
	 	{
	 		return 0;
		 }
		 return 1;
	  } 
	
	//��ջ
	void EnterBiTree(Stack * s,BiTree * bit)
	{
		if (s->top == MAXSIZE-1)
		{
			exit(1); 
		} 
		s->top++;
		s->t[s->top] = bit;
	 } 
	 
	 //ջ��Ԫ�� 
	 BiTree * GetTopBiTree(Stack * s)
	 {
	 		return (s->t[s->top]);
	 }
	 
	 //��ջ 
	 void PopTree(Stack * s)
	 {
	 	s->top--;
	 }
	 
	 //�ǵݹ�����
	 void PreBitOrder(BiTree * bit, Stack * s) 
	 {
	 	BiTree * p = bit;
	 	InitStack(s);
	 	
	 	while (p || StackIsEmpty(s))
	 	{
	 		while(p)
	 		{
	 			printf("%c",p->data);
	 			EnterBiTree(s, p);
	 			p = p->left;
			 }
			 p = GetTopBiTree(s);
			 PopTree(s);
			 p = p->right;
		} 
	 }

	 //�ǵݹ����� 
	 void InBitOrder(BiTree * bit, Stack * s)
	 {
	 	BiTree * p = bit;
	 	InitStack(s);
	 	
	    while(p || StackIsEmpty(s))
	 	{
	 		while(p)
	 		{
	 			EnterBiTree(s,p);
	 			p = p->left;                    //"ABC**DE*G**F***";
			 }
			 	
				p = GetTopBiTree(s);
				PopTree(s);
			 	printf("%c", p->data);
			 	p = p->right;	 
		 
		 }
	 	
	 }
	  
	  //�ǵݹ���� 
	  void PostBitOrder(BiTree * bit, Stack * s)
	  {
	  BiTree * p = bit;
	  BiTree * pre = NULL;
	  InitStack(s);
	  while (p || StackIsEmpty(s))
	  {
	  	while (p)
	  	{
	  		EnterBiTree(s,p);
	 		p = p->left; 
		}
		
		p = GetTopBiTree(s);
		
	    if(p->right == NULL || p->right == pre)
		   {
			printf("%c",p->data);
			pre = p;
			PopTree(s);
			p = NULL;
		   }
	    else
	    {
	    	p = p->right;
		}
	   } 
	  }
		
		void test01()
		{
		BiTree * Bit;
		Stack s;
	   	int i = 0;
	   	char tree[] = "ABC**DE*G**F***";
		Bit = CreateBiTree(tree, &i);
		printf("�������ǵݹ��ǰ�����!\n");
		PreBitOrder(Bit,&s);
		printf("\n�������ķǵݹ���������!\n"); 
		InBitOrder(Bit, &s);
		printf("\n�������ǵݹ�ĺ������!\n"); 
		PostBitOrder(Bit,&s);
		printf("\n");	
	}
		  
	   int main()
	   {
		test01(); 
	   	system("pause");
	   	return 0;
	   }
