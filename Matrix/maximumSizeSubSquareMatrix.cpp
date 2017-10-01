#include<stdio.h>
#include<stdlib.h>

int min(int a, int b, int c)
{
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}

int main()
{
	int r,c,i,j;
	int max_square_sub=0,max_i=0,max_j=0;
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	int *arr[r];
    int temp[r][c]={0};
	
	for(int i=0;i<r;i++)
	{
		arr[i]=(int *)malloc(sizeof(int)*c);
	}
	
	printf("please enter elements \n");
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
	
	// first we need to update first row and first column of temp array, it will be same as in original matrix.
	
	for(i=0;i<c;i++)
		temp[0][i]=arr[0][i];
		
	for(i=0;i<r;i++)
		temp[i][0]=arr[i][0];
	
	
	// traverse matrix from 1st row and 1st column now, and if arr[i][j] is 1 then corrosponding entry in temp array will be
	// calculated as min(arr[i-1][j-1],arr[i-i][j],arr[i][j-1])+1 and if arr[i][j] is 0 then temp[i][j] will also be 0.
	// each entry in temp array will tell about maximum size square sub array till that point
	
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			if(arr[i][j]==1)
			{
				temp[i][j]=min(temp[i][j-1],temp[i-1][j],temp[i-1][j-1])+1;
				
				if(temp[i][j]>max_square_sub)
				{
					max_square_sub = temp[i][j];
					max_i = i;
					max_j = j;
				}
			}
			else
				temp[i][j]=0;
		}
	}
	
	printf("temp matrix is\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",temp[i][j]);
		printf("\n");
	}
	
	
	
	printf("size of maximum size sub square matrix is %d at index (%d,%d)\n", max_square_sub,max_i,max_j);
	
	printf("maximum size sub square matrix is \n");
	
	for(i=max_i;i>max_i-max_square_sub;i--)
	{
		for(j=max_j;j>max_j-max_square_sub;j--)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
	
}
