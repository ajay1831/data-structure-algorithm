#include<stdio.h>

void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void reverse(int arr[], int start, int end)
{
	int i=start;
	int j=end;
	while(i<=j)
	{
		swap(&arr[i],&arr[j]);
		i++;
		j--;
	}
}

void rotate(int arr[], int len, int k)
{
	reverse(arr,0,k-1);
	reverse(arr,k,len-1);
	reverse(arr,0,len-1);

}
int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(int);
	int i;
	
	printf("before rotating array is \n");
	for(i=0;i<n;i++)
	    printf("%d ", arr[i]);
	
	int k;
	printf("\nBy how many positions you want to rotate\n");
	scanf("%d",&k);
	
	if(k>=n)
	{
		printf("\nnot possible\n");
	}
	
	else
	{
		rotate(arr,n, k);
	
		printf("\nAfter rotation array is \n");
		for(i=0;i<n;i++)
	    	printf("%d ", arr[i]);
	}
	
}
