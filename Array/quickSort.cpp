#include<stdio.h>

void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int pi = start;
	int i;
	
	for(i=start;i<end;i++)
	{
		if(arr[i]<pivot)
		{
			swap(&arr[i],&arr[pi]);
			pi++;
		}
	}
	swap(&arr[pi],&arr[end]);
	return pi;
}

void quickSort(int arr[], int start, int end)
{
	if(start<end)
	{
		int pi = partition(arr,start,end);
		quickSort(arr,start,pi-1);
		quickSort(arr,pi+1,end);
    }
}
int main()
{
	int arr[]={7,2,1,6,8,5,3,4};
	int n = sizeof(arr)/sizeof(int);
	int i;
	
	printf("before sorting array is \n");
	for(i=0;i<n;i++)
	    printf("%d ", arr[i]);
	
	quickSort(arr,0,n-1);
	
	printf("\nAfter sorting array is \n");
	for(i=0;i<n;i++)
	    printf("%d ", arr[i]);
	
	
}
