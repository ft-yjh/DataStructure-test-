#include<stdio.h>

void Merge(int arr1[], int low, int mid, int high, int arr2[])
{
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high)
	{
		if (arr1[i] < arr1[j])
		{
			arr2[k] = arr1[i];
			i++;
		}
		else
		{
			arr2[k] = arr1[j];
			j++;
		}
		k++;
	}
		while (i <= mid)
		{
			arr2[k] = arr1[i];
			k++;
			i++;
		}
		while (j <= high)
		{
			arr2[k] = arr1[j];
			k++;
			j++;
		}
}

void PrintArr(int arr[])
{
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr1[8] = {05,13,19,27,01,16,26,31};
	int arr2[8] = {0};
	
	PrintArr(arr1);
	Merge(arr1,0,3,7,arr2);
	printf("\n");
	PrintArr(arr2);
	
	return 0;
}
