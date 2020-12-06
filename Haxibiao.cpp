 /*假设有一个30人的班级，用汉语拼音表示学生姓名，
 要求以学生姓名为关键字设计一个哈希表，采用除留余数法构造哈希函数，
 用线性探测再散列法处理冲突，平均查找长度上限为2。
 并且按姓名在哈希表中查询学生的位置和成绩信息，将其输出到显示器上。*/ 
 #include<stdio.h>
 #include<string.h>
 #define HASH_LEN 50
 #define NAME_LEN 30  
 #include<malloc.h>
 #include<ctype.h>//toascii()用到的头文件 
 #define P 47 //最大素数 
 
 typedef struct NAME
 {
 	char * key;//名字的拼音 
 	int m;     //asicii码总和 
 	int score; 
 }NAME;
 
 typedef struct HASH
 {
 	char * key;//名字的拼音 
 	int m;     //asicii码总和 
 	int score;
 	int si;    //查找长度 
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
	  	if (hash[adr].si == 0)//不冲突
		  {
		  	hash[adr].key = name[i].key;
		  	hash[adr].m = name[i].m;
		  	hash[adr].score = name[i].score;
		  	hash[adr].si = sn;
		   } 
		   else    //冲突 
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
			   			printf("哈希表已满\n");
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
  
  void DisplayName()//显示姓名表
{
	int i = 0;
       printf("\n地址 \t\t 姓名 \t\t 成绩\t\t 关键字\n");
       for (i=0;i<NAME_LEN;i++)
       printf("%2d %18s \t\t  %d  \t\t %d  \n",i,name[i].key,name[i].score,name[i].m);
}

void Search_Hash()
{
	int i = 0;
	char * name;
	name = (char*)malloc(sizeof(name) * 20);
	printf("请输入要查找的姓名:\n");
	scanf("%s", name);
	for (i = 0; i < HASH_LEN; i++)
	{
		if (strcmp(hash[i].key,name) == 0)
		{
			 printf("\n\n 地址\t   姓名\t\t  关键字\t成绩\t\t搜索长度\n"); //显示的格式
			 printf("%2d %16s\t %5d\t\t %2d\t\t %d\n",
			  i,hash[i].key,hash[i].m,hash[i].score,hash[i].si);
		}
	}
}

void DisplayHash()// 显示哈希表
{
	   int i = 0;
       float asl=0.0;
       printf("\n\n 地址\t   姓名\t\t  关键字\t成绩\t\t搜索长度\n"); //显示的格式
       for (i=0;i<HASH_LEN;i++)
       {
              printf("%2d %16s\t %5d\t\t %2d\t\t %d\n",
			  i,hash[i].key,hash[i].m,hash[i].score,hash[i].si);
              asl+=hash[i].si;
       }
       asl/=NAME_LEN;//求得ASL
       printf("\n\n平均查找长度：ASL(%d)=%f \n",NAME_LEN,asl);
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
