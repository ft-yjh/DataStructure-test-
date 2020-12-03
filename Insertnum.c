#include<stdio.h>
 
/* ��ӡ���� */ 
void printArr(int nums[],int n){
	printf("\n");
	int i = 0;
	for(i=0;i<n;i++){
		printf("%d\t",nums[i]);
	}
	printf("\n");
}
 
/* ʹ�ö��ֲ�����˳����в���Ԫ��k */ 
void insertK(int nums[],int n,int k){
	int mid;// ��¼�м��±� 
	int low=0,high=n-1;
	int flag=0;// ��־��������¼�Ƿ��е���k��ֵ 
	int pos;// ����ı�����Ϊ�����λ�� 
	while(low<=high&&flag==0){// ѭ����low>highʱ����ѭ�� 
		mid=(low+high)/2;
		if(nums[mid]==k){
			flag=1;// ��������йؼ��ֵ���k,�򽫱�־flag��Ϊ1���˳�ѭ��Ȼ�����k 
		}else if(nums[mid]>k){
			high=mid-1;
		}else if(nums[mid]<k){
			low=mid+1;
		}
	}
	/* ȷ������λ�� */ 
	if(flag==1){// ���flagΪ1�����������йؼ��ֵ���k����ʹ����λ�õ���mid
		pos=mid; 
	}else{// ���flagΪ0���ʾ������û����ؼ���k��ȵ�ֵ�������λ��Ϊlow  ��λ��Ϊ����Ҫ��������ĵ�һ�� 
		pos=low; 
	}
	/* ����ؼ���k */
	int i = 0; 
	for(i=n-1;i>=pos;i--){  //���ƶ����һλ 
		nums[i+1]=nums[i];
	} 
	nums[pos]=k;
}
 
int main(){
	int nums[]={1,12,16,24,35,46,67,0};//��������鳤��Ҫ��һ 
	int n= sizeof(nums)/sizeof(int);
	int k=24;
	insertK(nums,n-1,k);// ����k
	printArr(nums,n);// ��ӡ���� 
	
	return 0;
}
