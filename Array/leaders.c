#include<stdio.h>

int main()
{
	int arr[]={16,17,4,3,5,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int i,leader;
	leader = arr[n-1];
	printf("%d ", leader);
	for(i=n-2;i>=0;i--)
	{
		
		if(arr[i]>leader)
		{
			leader=arr[i];
	    printf("%d ", leader);	
		
	}
	}
	
	return 0;
}
