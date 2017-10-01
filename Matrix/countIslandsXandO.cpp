#include<stdio.h>
#include<stdlib.h>

/* reference: http://www.geeksforgeeks.org/count-number-islands-every-island-separated-line/ */

int check_left_most(char *arr[], int i, int j)
{
	char upper_element = (i-1 >=0)?arr[i-1][j]:'O';
	char left_element = (j-1 >=0)?arr[i][j-1]:'O';
	
	if(upper_element == 'O' && left_element== 'O')
	 	return 1;
	else
		return 0;
}

int main()
{
	int r,c,i,j;
	int number_of_islands=0;
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	char *arr[r];
    
	for(i=0;i<r;i++)
	{
		arr[i]=(char *)malloc(sizeof(char)*c);
	}
	
	printf("please enter elements \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf(" %c",&arr[i][j]);
	}
	
	printf("entered matrix is\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%c",arr[i][j]);
		printf("\n");
	}
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]=='X')
			{
				if(check_left_most(arr,i,j))
					number_of_islands++;
			}
		}
	}
	
	
	printf("total number of islands where every island is row-wise and column-wise separated: %d\n", number_of_islands);
	
	return 0;
	
}
