#include<stdio.h>

void BiInsertSort(int arr[], int len)
{
	int i = 0;
	int low = 0;
	int high = len - 1;
	for (i = 1; i < len; i++){
		int x = arr[i];
		while (low <= high)
	    {
		int mid = (low + high)/2;
		if (x < arr[mid])
		high = mid - 1;
		else
		low = mid + 1;
	    }
	    int j = 0;
	    for (j = i -1; j >= low; j--)
	    arr[j+1] = arr[j];
	    arr[low] = x;
	}
 } 
 
 int main()
 {
 	int arr[10] = {4,1,3,9,10,5,7,2,6,8};
 	BiInsertSort(arr, 10);
 	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	 } 
	 return 0;
 }
