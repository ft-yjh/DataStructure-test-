	/*n个学生的考试成绩表,每条信息由学号,姓名,分数组成:
	(1) 按学号排序
	(2) 按分数排序(分数相同保持按学号排序)
	*/
	#include<stdio.h>
	#define Max_Size 20
	#include<string.h>
	#include<malloc.h>
	
	typedef struct Student
	{
		char num[10];
		char name[20];
		float score;
	}Student;
	
	void Swap(Student * s1,Student * s2)
	{
		Student * temp;
		temp = (Student *)malloc(sizeof(Student));//疑问 
		*temp = *s2;
		*s2 = *s1;
		*s1 = *temp;
	}
	
	
	//按学号排序
	void Sort_By_Num(Student * s, int len)
	{
		int i = 0;
		int j = 0;
		for (i = len-1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				//Swap(&s[j], &s[j+1]);
				if ((strcmp(s[j].num , s[j+1].num) > 0))
				{
					Swap(&s[j], &s[j+1]);
				}
			}
		}
	 } 
	 
	 //按分数排序
	 void Sort_By_Score(Student * s, int len)
	 {
	 	int i = 0;
	 	int j = 0;
	 	for (i = len-1; i > 0; i--)
	 	{
	 		for (j = 0; j < i; j++)
	 		{
	 			if ((s[j].score > s[j+1].score))
	 			{
	 				Swap(&s[j],&s[j+1]);
				 }
				 else if (s[j].score == s[j+1].score)
				 {
				 	if ( (strcmp(s[j].num,s[j+1].num) ) > 0)
				 	{
				 		Swap(&s[j],&s[j+1]);
					 }
				 	
				 }
			 }
		 }
	 }
	 
	 void AddData(Student * s, int len)
	 {
	 	FILE * fp = NULL;
	 	fp = fopen("student.txt","r");
	 	int i = 0;
	 	for (i = 0; i < len; i++)
	 	{
	 		/*printf("依次输入第%d个人的学号, 姓名, 成绩: \n", i+1);
	 		scanf("%s %s %f",s[i].num, s[i].name, &s[i].score);*/
	 		fscanf(fp,"%s",s[i].num);
	 		fscanf(fp,"%s",s[i].name);
	 		fscanf(fp,"%f",&s[i].score);
		 }
		 fclose(fp);
	 }
	 
	 void PrintData(Student * s, int len)
	 {
	 	int i = 0;
	 	printf("学号   姓名  \t成绩  \n");
	 	for (i = 0; i < len; i++)
	 	{
	 		printf("%-6s %-6s %6.1f\n",s[i].num,s[i].name,s[i].score); 
		 }
		 
	 }
	  
	
	int main()
	{
		int length = 0;
		Student * s;
		printf("请输入学生的个数: \n");
		scanf("%d", &length);
		s = (Student *)malloc(length * sizeof(Student));
		
		AddData(s,length);
		printf("原数据: \n");
	    PrintData(s,length);
		int select = 0;
		while(1)
		{
		   printf("请输入你的选择: \n");
		   printf("1.by score    2.by num     \n");
		   scanf("%d", &select); 
		if (select == 1)
		{
		   printf("-----------------------\n"); 
		   Sort_By_Score(s,length);
		   PrintData(s,length);
		   system("pause"); 
		   break;
		}
		else if(select == 2 )
		{
		printf("---------------\n");
		Sort_By_Num(s,length);
		PrintData(s,length);
		system("pause");
		break;
		} 
	    }
		
		return 0;
	 } 
