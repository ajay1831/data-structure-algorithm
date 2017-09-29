#include<stdio.h>

int findCandidate(int arr[], int size)
{
	int maj_index=0;
	int count=1;
	
	int i;
	for(i=1;i<size;i++)
	{
		if(arr[i]==arr[maj_index])
		{
			count++;
		}
		else
		    count--;
		if(count==0)
		{
			maj_index=i;
			count=1;
		}
		
	}
	
	return arr[maj_index];
}
void majorityElement(int arr[], int size)
{
	int candidate = findCandidate(arr,size);
	int i;
	int count=0;
	for(i=0;i<size;i++)
	{
		if(arr[i]==candidate)
		   count++;
	}
	
	if(count>size/2)
		printf("majority element is %d ", candidate);
	else
		printf("no majority element found");
	
	
}
int main()
{
	int arr[] = {1,3,3,1,3};
	int n = sizeof(arr)/sizeof(int);
	
	majorityElement(arr,n);
	return 0;
}
