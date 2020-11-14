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
	#define MAXSIZE 10 
	
	typedef char BiTreeDataType;
	typedef struct Node
	{
		BiTreeDataType data;//数据域 
		struct Node * left;//左节点 
		struct Node * right;//右节点 
	 } BiTree;
	 
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
	 	    //初始化
		    bit->left = bit->right = NULL; 
		 
		 	bit->data = Tree[*i];
		 	(*i)++;
		 	bit->left = CreateBiTree(Tree, i);
		 	bit->right = CreateBiTree(Tree, i);
		 	return bit;
		  } 
		  
	  } 
	
	//递归 
	
	//二叉树的先序遍历
	void PreOrder(BiTree * bit)
	{
		if (bit)
		{
			printf("%c ", bit->data);
			PreOrder(bit->left);
			PreOrder(bit->right);
		}
		
	 } 
	 
	 //二叉树的中序遍历
	 void InOrder(BiTree * bit)
	 {
	 	if (bit)
	 	{
	 		InOrder(bit->left);
		 	printf("%c ", bit->data);
		 	InOrder(bit->right);
		 }
	}
	  
	  //二叉树的后序遍历
	  void PostOrder(BiTree * bit)
	  {
	  	if (bit)
	  	{
	  		PostOrder(bit->left);
		  	PostOrder(bit->right);
		  	printf("%c ", bit->data);
		}
	  }

    //树节点的销毁 
		void Destroy(BiTree * bit)
		{
			if (bit)
			{
				Destroy(bit->left);
				Destroy(bit->right);
				free(bit);
			}
			
	    }
		
		//递归的二叉树
		void test01()
		{
		BiTree * Bit;
	   	int i = 0;
	   	char tree[] = "ABC**DE*G**F***";
		Bit = CreateBiTree(tree, &i);
		printf("二叉树的先序遍历:\n");
		PreOrder(Bit);
		printf("\n二叉树的中序遍历:\n");
		InOrder(Bit);
		printf("\n二叉树的后序遍历:\n");
		PostOrder(Bit); 
		printf("\n"); 
		
		//销毁
		Destroy(Bit); 
		} 
		
		void test02()
		{
		BiTree * Bit;
	   	int i = 0;
	   	char tree[] = "ABC**DE*G**F***";
		Bit = CreateBiTree(tree, &i);
		
		}
		  
	   int main()
	   {
	   	
		test01();
	   	
	   	system("pause");
	   	return 0;
	   }
