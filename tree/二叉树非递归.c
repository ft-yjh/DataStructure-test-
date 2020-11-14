	/*建立一棵用二叉链表方式存储的二叉树，并对其进行遍历（先序、中序和后序），将遍历序列输出到显示器上。
	【基本要求】从键盘输入一棵二叉树的先序序列，以二叉链表作为存储结构，建立二叉树并对其进行遍历（先序、中序和后序），然后将遍历结果打印输出。要求编写递归和非递归两种算法来实现。
	【测试数据】 输入序列：ABC**DE*G**F***（其中*表示空子树）
	             输出结果：先序序列ABCDEGF
	                       中序序列CBEGDFA
	                       后序序列CGEFDBA
	*/ 
	#include<stdio.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#define MAXSIZE 50
	
	typedef char BiTreeDataType;
	typedef struct Node
	{
		BiTreeDataType data;//数据域 
		struct Node * left;//左节点 
		struct Node * right;//右节点 
	 } BiTree;
	 
	 typedef struct StackBiTree
	 {
	 	BiTree * t[MAXSIZE];//树节点 
	 	int top;
	  } Stack;
	   
	 
	 //二叉树的建立 
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
	
	//初始化
	void InitStack(Stack * s)
	{
		s = (Stack*)malloc(sizeof(Stack));
		s->top = -1;
	 }
	 
	 //判断栈是否为空
	 int StackIsEmpty(Stack * s)
	 {
	 	if (s->top == -1)
	 	{
	 		return 0;
		 }
		 return 1;
	  } 
	
	//入栈
	void EnterBiTree(Stack * s,BiTree * bit)
	{
		if (s->top == MAXSIZE-1)
		{
			exit(1); 
		} 
		s->top++;
		s->t[s->top] = bit;
	 } 
	 
	 //栈顶元素 
	 BiTree * GetTopBiTree(Stack * s)
	 {
	 		return (s->t[s->top]);
	 }
	 
	 //出栈 
	 void PopTree(Stack * s)
	 {
	 	s->top--;
	 }
	 
	 //非递归先序
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

	 //非递归中序 
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
	  
	  //非递归后序 
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
		printf("二叉树非递归的前序遍历!\n");
		PreBitOrder(Bit,&s);
		printf("\n二叉树的非递归的中序遍历!\n"); 
		InBitOrder(Bit, &s);
		printf("\n二叉树非递归的后序遍历!\n"); 
		PostBitOrder(Bit,&s);
		printf("\n");	
	}
		  
	   int main()
	   {
		test01(); 
	   	system("pause");
	   	return 0;
	   }
