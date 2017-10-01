#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int kadenes(int temp[], int *start, int *end, int n)
{

	int i,x;
	int max_so_far=temp[0];
	int max_end_here=temp[0];
	int s=0;
	
	for(i=1;i<n;i++)
	{
		x = temp[i] + max_end_here;
		if(temp[i]>x)
		{
			max_end_here=temp[i];
			s=i;
		}
		else
		{
			max_end_here=x;
		}
		
		if(max_end_here>max_so_far)
		{
			max_so_far=max_end_here;
			*start=s;
			*end=i;
		}
		
	}
	return max_so_far;
}

int main()
{
	int r,c,i,j;
	int left,right;
	int start=0,end=0;
	
	int current_max=0,max=0,max_left=0,max_right=0,max_up=0,max_down=0;
	
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	
	int *arr[r];
    int temp[r]={0};
	
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
	
	for(left=0;left<c;left++)
	{
		memset(temp,0,sizeof(temp));
		for(right=left;right<c;right++)
		{
			for(i=0;i<r;i++)
			    temp[i]+=arr[i][right];
			
			current_max = kadenes(temp,&start,&end,r);
			
			if(current_max>max)
			{
				max = current_max;
                max_left = left;
                max_right = right;
                max_up = start;
                max_down = end;
			}
		}
	}
	printf("(Top, Left) (%d, %d)\n", max_up, max_left);
    printf("(Bottom, Right) (%d, %d)\n", max_down, max_right);
    printf("Max sum is: %d\n", max);
		
	return 0;
}
