#include <stdio.h>

int main() 
{
	
	int r,c,i,j;
	
	printf("please enter number of rows and number of column\n");
	scanf("%d %d",&r,&c);
	
	char arr[r][c];
	
	int T=0,B=r-1,L=0,R=c-1,dir=0;
	char ch='X';
	
	
    while(T<=B && L<=R)
    {
    	if(dir==0)
    	{
    		int col = L;
    		while(col<=R)
    		{
    			arr[T][col]=ch;
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
    			arr[row][R]=ch;
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
    			arr[B][col]=ch;
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
    			arr[row][L]=ch;
    			row--;
			}
			L++;
			dir =0;
		}
		ch = (ch=='O'?'X':'O');
    	
	}
	
	for(i=0;i<r;i++)
	    {
	        for(j=0;j<c;j++)
	        printf("%c ",arr[i][j]);
	        
	        printf("\n");
	    }
	    
return 0;
}
