#include<stdio.h>


int main()
{
	int arr[]={-3, -2};
	
	int n = sizeof(arr)/sizeof(int);
	
	int s=0,start=0,end=0;
	int max_so_far=arr[0];
	int max_end_here=arr[0];
	int temp;
	
	for(int i=1;i<n;i++)
	{
		temp = arr[i] + max_end_here;
		if(arr[i]>temp)
		{
			max_end_here=arr[i];
			s=i;
		}
		else
		{
			max_end_here=temp;
		}
		
		if(max_end_here>max_so_far)
		{
			max_so_far=max_end_here;
			start=s;
			end=i;
		}
		
	}
	
	printf("largest contiguos sum is %d and range is [%d,%d]",max_so_far,start,end);
	return 0;
}
