//ʮ������Ľṹ���Ͷ���
typedef int ElemType;
typedef struct OLNode
{
	int row;//���±� 
	int col;//���±� 
	ElemType value;//ֵ 
	struct OLNode * right;//����Ԫ���б������� 
	struct OLNode * down;//����Ԫ���б������� 
 } OLNode;*OLink; 
 
 typedef struct
 {
 	OLink * row_head; //�������ͷָ�� 
 	OLink * col_head; //�������ͷָ�� 
 	int m;           //ϡ���������� 
 	int n;          //ϡ���������� 
 	int len;       //ϡ�����ĸ��� 
  } CrossList;
  
  //����ϡ������ʮ������
  void CreateList(CrossList * M)
  {
  	int m = 0;
  	int n = 0;
  	int t = 0;
  	int i = 0;
  	int j = 0;
  	int e = 0;
  	OLNode * p;
  	OLNode * q;
  	scanf("%d %d %d", &m, &n, &t); 
  	M->m = m;
  	M->n = n;
  	M->len = t;
  	
  	if(!(M->row_head) = (OLink *)malloc((m + 1)sizeof(OLink)));
  	exit(1);
  	if(!(M->col_head) = (OLink *)malloc((m + 1)sizeof(OLink)));
  	exit(1);
  	M->row_head[] = M->col_head[] = NULL;
  	
  	for (scanf("%d %d %d", &i, &j, &e); i != 0; scanf("%d %d %d", &i, &j, &e))
  	{
  		if (!(p = (OLNode *)malloc(sizeof(OLNode))));
  		exit(1);
  		p->row = i;
  		p->col = j;
  		p->value = e;
  		if (M->row_head[i] == NULL)
  		M->row_head[i] = p;
  		else
  		{
  			q = M->row_head[i];
  			while (q->right != NULL && q->right->col < j)
  			q = q->right;
  			p->right = q->right;
  			q->right = p;
		  }
		  
		if (M->col_head[j] == NULL)
  		M->col_head[i] = p;
  		else
  		{
  			q = M->col_head[j];
  			while (q->down != NULL && q->right->row < i)
  			q = q->down;
  			p->down = q->down;
  			q->down = p;
		  }
	  }
  	
  } 
