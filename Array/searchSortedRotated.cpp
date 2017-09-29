#include<stdio.h>


int searchSortedRotated(int arr[], int low, int high, int x)
{
	while(low<=high)
	{
		int mid = (low+high)/2;
		
		// case1 : if mid element is our key element
		if(arr[mid ]== x)
			return mid;
			
		//case 2: if left half is sorted 
		if(arr[low]<=arr[mid])
		{
			//case 2a: if key is present in this 
			if(x>=arr[low] && x<arr[mid])
				high = mid-1;
			//case 2b: if key is not prsent in this
			else
			    low = mid+1;
						
		}
		//case 3: if second half is sorted
		else
		{
			//case 2a: if key is present in this 
			if(x>arr[mid] && x<=arr[high])
				low = mid+1;
			//case 2b: if key is not prsent in this
			else
			    high = mid-1;
		}
	}
	
return -1;
	
}
int main()
{
	int arr[] = {5,6,7,8,9,10,1,2,3};
	int n = sizeof(arr)/sizeof(int);
	
	int index = searchSortedRotated(arr,0,n-1, 1);
	if(index==-1)
		printf("element not found\n");
	else
		printf("element found at %d\n", index);
	
	return 0;
}
