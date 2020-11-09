/*����һ���ö�������ʽ�洢�Ķ���������������б�������������ͺ��򣩣������������������ʾ���ϡ�
������Ҫ�󡿴Ӽ�������һ�ö��������������У��Զ���������Ϊ�洢�ṹ��������������������б�������������ͺ��򣩣�Ȼ�󽫱��������ӡ�����Ҫ���д�ݹ�ͷǵݹ������㷨��ʵ�֡�
���������ݡ� �������У�ABC**DE*G**F***������*��ʾ��������
             ����������������ABCDEGF
                       ��������CBEGDFA
                       ��������CGEFDBA
*/ 
#include<stdio.h>
#include<stdlib.h>

typedef char BiTreeDataType;
typedef struct Node
{
	BiTreeDataType data;//������ 
	struct Node * left;//��ڵ� 
	struct Node * right;//�ҽڵ� 
 } BiTree; 
 
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
 	    //��ʼ��
	    bit->left = bit->right = NULL; 
	 
	 	bit->data = Tree[*i];
	 	(*i)++;
	 	bit->left = CreateBiTree(Tree, i);
	 	bit->right = CreateBiTree(Tree, i);
	 	return bit;
	  } 
	  
  } 

//���������������
void PreOrder(BiTree * bit)
{
	if (bit)
	{
		printf("%c ", bit->data);
		PreOrder(bit->left);
		PreOrder(bit->right);
	}
	
 } 
 
 //���������������
 void InOrder(BiTree * bit)
 {
 	if (bit)
 	{
 		InOrder(bit->left);
	 	printf("%c ", bit->data);
	 	InOrder(bit->right);
	 }
}
  
  //�������ĺ������
  void PostOrder(BiTree * bit)
  {
  	if (bit)
  	{
  		PostOrder(bit->left);
	  	PostOrder(bit->right);
	  	printf("%c ", bit->data);
	}
  }
	
	//�ڵ������
	void Destroy(BiTree * bit)
	{
		if (bit)
		{
			Destroy(bit->left);
			Destroy(bit->right);
			free(bit);
		}
		
    }
	
	//�ݹ�Ķ�����
	void test01()
	{
	BiTree * Bit;
   	int i = 0;
   	char tree[] = "ABC**DE*G**F***";
   // printf("���������ַ���:\n");
    //gets(tree);
	Bit = CreateBiTree(tree, &i);
	printf("���������������:\n");
	PreOrder(Bit);
	printf("\n���������������:\n");
	InOrder(Bit);
	printf("\n�������ĺ������:\n");
	PostOrder(Bit); 
	printf("\n"); 
	
	//����
	Destroy(Bit); 
	} 
	  
   int main()
   {
   	
	test01();
   	
   	system("pause");
   	return 0;
   }
