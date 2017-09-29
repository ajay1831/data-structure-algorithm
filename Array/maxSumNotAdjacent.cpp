#include<stdio.h>

int max(int a, int b)
{
	return (a>b?a:b);
}

int maxSum(int arr[],int n)
{
	    int incl, excl,temp,i;
	    incl=arr[0];
	    excl=0;
	    
	    for(i=1;i<n;i++)
	    {
	    	temp = incl;
	    	incl = max(arr[i]+excl, temp);
	    	excl = temp;
		}
		
		return max(incl,excl);
	
}

int main()
{
	int arr[] = {4,1,1,4,2,1};
	
	int n=sizeof(arr)/sizeof(int);
	
	int i;
	
	
	int max = maxSum(arr,n);
		
	printf("\Maximum sum such that no two elements are adjacent for the given array is ");
	printf("%d ", max);
	
	return 0;
}
