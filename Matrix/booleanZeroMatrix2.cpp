#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,i,j;
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	int *arr[r];
	int row_flag=0;
	int col_flag=0;
	
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
	
	// first we need to update row_flag and col_flag if we find any element as 1 in first row or first column of matrix.
	
	for(i=0;i<c;i++)
	{
		if(arr[0][i]==1)
		{
			row_flag=1;
			break;
		}
	}
	

	
	for(i=0;i<r;i++)
	{
		if(arr[i][0]==1)
		{
			col_flag=1;
			break;
		}
	}
	
			
	// traverse matrix from 1st row and 1st column now, and if any element is equal to 1 , we have to update first row and first column as 1 corrospondin to element pos.
	
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			if(arr[i][j]==1)
			{
				arr[0][j]=1;
				arr[i][0]=1;
			}
		}
	}
	
	// again traverse the matrix, and for each element if corosponding row entry or column entry is 1 , we have to update this element as 1.	
	
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			if(arr[0][j]==1 || arr[i][0]==1)
			{
				arr[i][j]=1;			
			}
		}
	}	
	
	// now update first row and first column according to row_flag and col_flag values.
	
	for(i=0;i<c;i++)
	{
		if(row_flag==1)
			arr[0][i]=1;
	}
	
	for(i=0;i<r;i++)
	{
		if(col_flag==1)
			arr[i][0]=1;
	}
	
	printf("updated matrix is\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
	
}
