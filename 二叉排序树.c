//����������
#include<stdio.h>
#include<malloc.h>
typedef int KeyType;
typedef struct node
{
	KeyType key;//�ؼ��ֵ�ֵ 
	struct node * left;//��ָ�� 
	struct node * right;//��ָ�� 
}BSTNode, *BSTree;


//��������������ĵݹ��㷨
void InsertBST(BSTree * bst, KeyType key)
{
	BSTNode * s;
	if (*bst == NULL)  //�ݹ�������� 
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->key = key;
		s->left = NULL;
		s->right = NULL;
		(*bst) = s;
	}
	else if (key < (*bst)->key) //��s�������� 
	{
		InsertBST ((&(*bst)->left), key);
	 } 
	 else if (key > (*bst)->key)//��s�������� 
	 {
	 	InsertBST((&(*bst)->right), key);
	 }
 } 
 
 //�����������Ľ���
 void CreateBST(BSTree * bit)
 {
 	KeyType key;
 	*bit = NULL;
 	printf("������Ҫ�����ֵ:(Ϊ0ʱ����) \n");
 	scanf("%d", &key);
 	while (key != 0)
 	{
 		InsertBST(bit, key);
 		printf("������Ҫ�����ֵ:(Ϊ0ʱ����)\n");
 		scanf("%d", &key);
	 }
  } 

//�������������ҵĵݹ��㷨
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

//�����������ķǵݹ�
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
 
//������������ɾ��
BSTNode * DelBST(BSTree t, KeyType key)
{
	BSTNode * p,*f,*s,*q;
	p = t;
	f = NULL;
	while (p) //���ҹؼ���Ϊk�Ĵ�ɾ�ڵ� 
	{
		if (p->key == key)
		break;
		f = p;//fָ��p��˫�׽ڵ�
		if (p->key > key)
		p = p->left;
		else
		p = p->right;
	}
	
	if (p == NULL)  //δ�ҵ�Ҫɾ���Ľ�� 
	return t;
	
	if (p->left == NULL)//p��������
	{
		if (f == NULL)//p��ԭ�������ĸ� 
		t = p->right;
		else if (f->left == p)//p��f������ 
		f->left = p->right;
		else if (f->right == p)//p��f���Һ��� 
		f->right = p->right; 
		free(p);
	 } 
	 else//p��������
	 {
	 	q = p;
	 	s = p->left;
	 	while (s->right)//��p��ǰ���ڵ� 
	 	{
	 		q = s;
	 		s = s->right;
		 }
		 if (q == p) 
		 q->left = s->left;//��s������������q�� 
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
	//���� 
	CreateBST(bst);
	//��ӡ 
	PrintBST(*bst);
	
	printf("\n");
	printf("������Ҫ������Ԫ��ֵ: \n");
	scanf("%d", &key);
	//�ݹ�������ǵݹ����� 
	ReSearchBST(*bst, key);
	SearchBST(*bst, key);
	
	printf("������Ҫɾ����Ԫ��ֵ: \n");
	scanf("%d", &key);
	//ɾ�� 
	DelBST(*bst, key); 
	PrintBST(*bst);
	return 0;
 } 
