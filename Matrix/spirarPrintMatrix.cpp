#include <stdio.h>

int main() 
{
	
	    int m=4,n=4,i,j;
	    int arr[4][4];
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        scanf("%d",&arr[i][j]);
	    }
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        printf("%d ",arr[i][j]);
	    }
	    
	    int T=0,B=m-1,L=0,R=n-1,dir=0;
	    while(T<=B && L<=R)
	    {
	    	if(dir==0)
	    	{
	    		int col = L;
	    		while(col<=R)
	    		{
	    			printf("%d ",arr[T][col]);
	    			col++;
				}
				T++;
				dir=1;
	    		
			}
			
			if(dir==1)
	    	{
	    		int row = T;
	    		while(row<=B)
	    		{
	    			printf("%d ",arr[row][R]);
	    			row++;
				}
				R--;
				dir=2;
	    		
			}
			
			if(dir==2)
	    	{
	    		int col = R;
	    		while(col>=L)
	    		{
	    			printf("%d ",arr[B][col]);
	    			col --;
				}
				B--;
				dir=3;
			}
			
			if(dir==3)
	    	{
	    		int row = B;
	    		while(row>=T)
	    		{
	    			printf("%d ",arr[row][L]);
	    			row--;
				}
				L++;
				dir =0;
			}
			
	    	
		}
	return 0;
}
