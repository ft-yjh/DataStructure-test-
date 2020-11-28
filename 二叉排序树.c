//二叉排序树
#include<stdio.h>
#include<malloc.h>
typedef int KeyType;
typedef struct node
{
	KeyType key;//关键字的值 
	struct node * left;//左指针 
	struct node * right;//右指针 
}BSTNode, *BSTree;


//二叉排序树插入的递归算法
void InsertBST(BSTree * bst, KeyType key)
{
	BSTNode * s;
	if (*bst == NULL)  //递归结束条件 
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->key = key;
		s->left = NULL;
		s->right = NULL;
		(*bst) = s;
	}
	else if (key < (*bst)->key) //将s插入左树 
	{
		InsertBST ((&(*bst)->left), key);
	 } 
	 else if (key > (*bst)->key)//将s插入右树 
	 {
	 	InsertBST((&(*bst)->right), key);
	 }
 } 
 
 //二叉排序树的建立
 void CreateBST(BSTree * bit)
 {
 	KeyType key;
 	*bit = NULL;
 	printf("请输入要插入的值:(为0时结束) \n");
 	scanf("%d", &key);
 	while (key != 0)
 	{
 		InsertBST(bit, key);
 		printf("请输入要插入的值:(为0时结束)\n");
 		scanf("%d", &key);
	 }
  } 

//二叉排序树查找的递归算法
BSTree ReSearchBST(BSTree bst,KeyType key)
{
	if (!bst)
	return NULL;
	else if (bst->key == key)
	return bst; 
	else if (bst->key > key)
	return (ReSearchBST(bst->left, key));
	else if (bst->key < key)
	return (ReSearchBST(bst->right,key));
 } 

//二叉排序树的非递归
BSTree SearchBST (BSTree bst, KeyType key)
{
	BSTree q;
	q = bst;
	while (q)
	{
		if (q->key == key)
		return q;
		else if (q->key > key)
		q = q->left;
		else 
		q = q->right;
	}
	return NULL;
 } 
 
//二叉排序树的删除
BSTNode * DelBST(BSTree t, KeyType key)
{
	BSTNode * p,*f,*s,*q;
	p = t;
	f = NULL;
	while (p) //查找关键字为k的待删节点 
	{
		if (p->key == key)
		break;
		f = p;//f指向p的双亲节点
		if (p->key > key)
		p = p->left;
		else
		p = p->right;
	}
	
	if (p == NULL)  //未找到要删除的结点 
	return t;
	
	if (p->left == NULL)//p无左子树
	{
		if (f == NULL)//p是原二叉树的根 
		t = p->right;
		else if (f->left == p)//p是f的左孩子 
		f->left = p->right;
		else if (f->right == p)//p是f的右孩子 
		f->right = p->right; 
		free(p);
	 } 
	 else//p有左子树
	 {
	 	q = p;
	 	s = p->left;
	 	while (s->right)//找p的前驱节点 
	 	{
	 		q = s;
	 		s = s->right;
		 }
		 if (q == p) 
		 q->left = s->left;//将s的左子链链到q上 
		 else
		 q->right = s->left;
		 
		 p->key = s->key; 
		 free(s); 
	  } 
	  return t;
 } 
 
 void PrintBST(BSTree bst)
 {
 	BSTree q = bst;
 	if (q)
 	{
 		PrintBST(q->left);
 		printf("%d ", q->key);
 		PrintBST(q->right);
	 }
 }

int main()
{
	KeyType key; 
	BSTree * bst;
	bst = (BSTree *)malloc(sizeof(BSTree));
	//创建 
	CreateBST(bst);
	//打印 
	PrintBST(*bst);
	
	printf("\n");
	printf("请输入要搜索的元素值: \n");
	scanf("%d", &key);
	//递归搜索与非递归搜索 
	ReSearchBST(*bst, key);
	SearchBST(*bst, key);
	
	printf("请输入要删除的元素值: \n");
	scanf("%d", &key);
	//删除 
	DelBST(*bst, key); 
	PrintBST(*bst);
	return 0;
 } 
