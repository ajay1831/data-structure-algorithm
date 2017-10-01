#include<stdio.h>
#include<stdlib.h>
#define INF 9999


int min_arr(int *arr[], int i, int j, int r, int c)
{
    if(i>=r || j>=c)
        return INF;
    else
        return arr[i][j];
}

void maintain(int *arr[], int i, int j, int r, int c)
{
    int down= min_arr(arr, i+1,j,r,c);
    int right= min_arr(arr, i,j+1,r,c);
    
	if(down==INF && right==INF)
        return;
    if(down<right)
    {
        arr[i][j]=down;
        arr[i+1][j]=INF;
        maintain(arr, i+1, j, r, c);
    }
    else
    {
        arr[i][j]=right;
        arr[i][j+1]=INF;
        maintain(arr, i, j+1, r, c);
    }
}

int extract_min(int *arr[], int r, int c)
{
    int min=arr[0][0];
    arr[0][0]=INF;
    maintain(arr, 0, 0, r, c);
    return min;
}


int main()
{
	
	int r,c,i,j;
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	int *arr[r];
	
	for(i=0;i<r;i++)
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
	
	printf("sorted order:\n");						
	for(i=0;i<r*c;i++)
	{
		printf("%d ",extract_min(arr,r,c));
	}
	return 0;
	
}

