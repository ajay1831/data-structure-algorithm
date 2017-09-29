#include<stdio.h>
#include<stdlib.h>

int merge(int arr[], int temp[], int start,int mid,int end)
{
	
	int i=start;
	int j=mid;
	int k=start;
	int inversion_count=0;
	
	while(i<mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			inversion_count +=mid-i;
		}
	}
	
	while(i<mid)
	temp[k++]=arr[i++];
	
	while(j<=end)
	temp[k++]=arr[j++];
	
	for(i=start;i<=end;i++)
	arr[i]=temp[i];
	
	return inversion_count;
	
}

int mergeSort(int arr[], int temp[], int start, int end)
{
	int inversion_count=0;
	if(start<end)
	{
		int mid = (start+end)/2;
		inversion_count=mergeSort(arr,temp,start,mid);
		inversion_count+=mergeSort(arr,temp,mid+1,end);
		inversion_count+=merge(arr,temp,start,mid+1,end);
    }
    
    return inversion_count;
}
int main()
{
	int arr[]={1, 20, 6, 4, 5};
	int n = sizeof(arr)/sizeof(int);
	int i,inversion_count=0;
	
	
	int *temp = (int *)malloc(sizeof(int)*n);
	
	inversion_count = mergeSort(arr,temp,0,n-1);
	
	printf("after sorting array is \n");
	for(i=0;i<n;i++)
	    printf("%d ", arr[i]);
	    
	printf("inversion count is %d \n",inversion_count);
	
}
