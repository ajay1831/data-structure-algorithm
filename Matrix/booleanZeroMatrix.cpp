#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,i,j;
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	int *arr[r];
	int row[r];
	int col[c];
	
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
		
	// initializing row array
	for(i=0;i<r;i++)
		row[i]=0;
	
	// initializing col array
	for(i=0;i<c;i++)
		col[i]=0;
		
	// traverse matrix now, and if any element is equal to 1 , mark corrospondin row entry and col entry as 1.
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]==1)
			{
				row[i]=1;
				col[j]=1;
			}
		}
	}
	
	// again traverse the matrix, and for each element if corosponding row entry or column entry is 1 , we have to update this element as 1.	
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(row[i]==1 || col[j]==1)
			{
				arr[i][j]=1;
			
			}
		}
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
