#include<stdio.h>


void mergeMNwithN(int A[], int B[], int MN, int N)
{
	// move all elements of MN array to end
	int i,j=MN-1;
	for(i=MN-1;i>=0;i--)
	{
		if(A[i]!=-1)
		{
			A[j]=A[i];
			j--;
		}
	}
	
	    
	int k=0;
	i=N;
	j=0;
	
	
	while(k<MN)
	{
		if(i<MN && A[i]<=B[j] || j==N)
		{
			A[k]=A[i];
			k++;
			i++;
		}
		else
		{
			A[k]=B[j];
			k++;
			j++;
		}
	}
	
	
}
int main()
{
	int A[]={2, 8, -1, -1, -1, 13, -1, 15, 20};
	int B[]={5,7,9,25};
	
	int MN=sizeof(A)/sizeof(int);
	int N=sizeof(B)/sizeof(int);
	
	int i;
	
	printf("before merging MN array is \n");
	for(i=0;i<MN;i++)
	    printf("%d ", A[i]);
	    
	printf("\nbefore merging N array is \n");
	for(i=0;i<N;i++)
	    printf("%d ", B[i]);
	
	mergeMNwithN(A,B,MN,N);
	
	printf("\nAfter merging MN array is \n");
	for(i=0;i<MN;i++)
	    printf("%d ", A[i]);
	
	printf("\nAfter merging N array is \n");
	for(i=0;i<N;i++)
	    printf("%d ", B[i]);
		
	return 0;
}
