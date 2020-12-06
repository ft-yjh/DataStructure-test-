 /*������һ��30�˵İ༶���ú���ƴ����ʾѧ��������
 Ҫ����ѧ������Ϊ�ؼ������һ����ϣ�����ó��������������ϣ������
 ������̽����ɢ�з������ͻ��ƽ�����ҳ�������Ϊ2��
 ���Ұ������ڹ�ϣ���в�ѯѧ����λ�úͳɼ���Ϣ�������������ʾ���ϡ�*/ 
 #include<stdio.h>
 #include<string.h>
 #define HASH_LEN 50
 #define NAME_LEN 30  
 #include<malloc.h>
 #include<ctype.h>//toascii()�õ���ͷ�ļ� 
 #define P 47 //������� 
 
 typedef struct NAME
 {
 	char * key;//���ֵ�ƴ�� 
 	int m;     //asicii���ܺ� 
 	int score; 
 }NAME;
 
 typedef struct HASH
 {
 	char * key;//���ֵ�ƴ�� 
 	int m;     //asicii���ܺ� 
 	int score;
 	int si;    //���ҳ��� 
 }HASH;
 
 NAME name[HASH_LEN];
 HASH hash[HASH_LEN];
 
  void Init_Name()
  {
  	FILE * fp;
  	fp = fopen("HName.txt","r");
  	int i = 0;
  	for (i = 0; i < NAME_LEN; i++)
  	{
  		int s = 0;
  		int j = 0;
  		name[i].key = (char *)malloc(sizeof(char)*20);
  		fscanf(fp,"%s",name[i].key);
  		fscanf(fp,"%d",&name[i].score);
  		char * p = name[i].key;
  		for (j = 0; *(p+j)!= '\0'; j++)
  		s += toascii(*(p+j));
  		name[i].m = s;
  		//printf("%s %d %d\n",name[i].key,name[i].m,name[i].score);
	}
	fclose(fp);
  }
  
  void Create_Hash()
  {
  	int i = 0;
  	for (i = 0; i < HASH_LEN; i++)
  	{
  		hash[i].key = (char *)malloc(sizeof(char)*20); 
  		hash[i].key = "\0";
  		hash[i].m = 0;
  		hash[i].score = 0;
  		hash[i].si = 0;
	  }
	  
	  for (i = 0; i < NAME_LEN; i++)
	  {
	  	int sn = 1;
	  	int adr = (name[i].m) % P;
	  	if (hash[adr].si == 0)//����ͻ
		  {
		  	hash[adr].key = name[i].key;
		  	hash[adr].m = name[i].m;
		  	hash[adr].score = name[i].score;
		  	hash[adr].si = sn;
		   } 
		   else    //��ͻ 
		   {
		   	int t = adr;
		   	adr = (adr+1)%HASH_LEN;
			   for (adr; hash[adr].si != 0 && adr < HASH_LEN; adr++)
			   {
			   	sn++;
			   	if (adr == HASH_LEN -1)
			   	{
			   		for (adr = 0; hash[adr].si != 0 && adr < t; adr++)
			   		{
			   			sn++;
			   			if (adr == t)
			   			printf("��ϣ������\n");
					   }
				   }
				} 
			hash[adr].key = name[i].key;
		  	hash[adr].m = name[i].m;
		  	hash[adr].score = name[i].score;
		  	hash[adr].si = sn;
		   	
		   }
	  }
  }
  
  void DisplayName()//��ʾ������
{
	int i = 0;
       printf("\n��ַ \t\t ���� \t\t �ɼ�\t\t �ؼ���\n");
       for (i=0;i<NAME_LEN;i++)
       printf("%2d %18s \t\t  %d  \t\t %d  \n",i,name[i].key,name[i].score,name[i].m);
}

void Search_Hash()
{
	int i = 0;
	char * name;
	name = (char*)malloc(sizeof(name) * 20);
	printf("������Ҫ���ҵ�����:\n");
	scanf("%s", name);
	for (i = 0; i < HASH_LEN; i++)
	{
		if (strcmp(hash[i].key,name) == 0)
		{
			 printf("\n\n ��ַ\t   ����\t\t  �ؼ���\t�ɼ�\t\t��������\n"); //��ʾ�ĸ�ʽ
			 printf("%2d %16s\t %5d\t\t %2d\t\t %d\n",
			  i,hash[i].key,hash[i].m,hash[i].score,hash[i].si);
		}
	}
}

void DisplayHash()// ��ʾ��ϣ��
{
	   int i = 0;
       float asl=0.0;
       printf("\n\n ��ַ\t   ����\t\t  �ؼ���\t�ɼ�\t\t��������\n"); //��ʾ�ĸ�ʽ
       for (i=0;i<HASH_LEN;i++)
       {
              printf("%2d %16s\t %5d\t\t %2d\t\t %d\n",
			  i,hash[i].key,hash[i].m,hash[i].score,hash[i].si);
              asl+=hash[i].si;
       }
       asl/=NAME_LEN;//���ASL
       printf("\n\nƽ�����ҳ��ȣ�ASL(%d)=%f \n",NAME_LEN,asl);
}
 
 int main()
 {
 	Init_Name();
 	Create_Hash();
 	DisplayName();
 	//DisplayHash();
 	Search_Hash();
 	return 0;
  } 
