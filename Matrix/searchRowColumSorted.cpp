#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,i,j,key,flag=0;
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	int *arr[r];
	for(int i=0;i<r;i++)
	{
		arr[i]=(int *)malloc(sizeof(int)*c);
	}
	
	printf("please enter elements in row wise and colum wise sorted order\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	}
	
	printf("entered matrix is\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	
	printf("please enter the element you want to search in given matrix\n");
	scanf("%d",&key);
	
	i=0;
	j=c-1;
	while(i<=r-1 && j>=0)
	{
		if(arr[i][j]==key)
		{
			flag = 1;
			printf("element found at position (%d,%d)\n", i,j);
			break;
		}	
		else if(arr[i][j]>key)
			j--;
		else
			i++;
	}
	
	if(flag==0)
		printf("element not found\n");
	
	return 0;
	
}
