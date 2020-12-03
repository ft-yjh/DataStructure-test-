#include<stdio.h>
 
/* 打印数组 */ 
void printArr(int nums[],int n){
	printf("\n");
	int i = 0;
	for(i=0;i<n;i++){
		printf("%d\t",nums[i]);
	}
	printf("\n");
}
 
/* 使用二分查找在顺序表中插入元素k */ 
void insertK(int nums[],int n,int k){
	int mid;// 记录中间下标 
	int low=0,high=n-1;
	int flag=0;// 标志，用来记录是否有等于k的值 
	int pos;// 定义的变量，为插入的位置 
	while(low<=high&&flag==0){// 循环当low>high时跳出循环 
		mid=(low+high)/2;
		if(nums[mid]==k){
			flag=1;// 如果发现有关键字等于k,则将标志flag置为1，退出循环然后插入k 
		}else if(nums[mid]>k){
			high=mid-1;
		}else if(nums[mid]<k){
			low=mid+1;
		}
	}
	/* 确定插入位置 */ 
	if(flag==1){// 如果flag为1则发现序列中有关键字等于k，则使插入位置等于mid
		pos=mid; 
	}else{// 如果flag为0则表示序列中没有与关键字k相等的值，则插入位置为low  该位置为大于要插入的数的第一个 
		pos=low; 
	}
	/* 插入关键字k */
	int i = 0; 
	for(i=n-1;i>=pos;i--){  //先移动最后一位 
		nums[i+1]=nums[i];
	} 
	nums[pos]=k;
}
 
int main(){
	int nums[]={1,12,16,24,35,46,67,0};//插入后数组长度要加一 
	int n= sizeof(nums)/sizeof(int);
	int k=24;
	insertK(nums,n-1,k);// 插入k
	printArr(nums,n);// 打印数组 
	
	return 0;
}
