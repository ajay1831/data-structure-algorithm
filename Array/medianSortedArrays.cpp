#include<stdio.h>


int medianArray1(int arr1[], int arr2[], int n)
{
	    
	int m1=-1,m2=-1;
	int i=0;
	int j=0;
	int count=0;
	
	
	while(count<=n)
	{
		if(i<n && arr1[i]<=arr2[j] || j==n)
		{
			m1=m2;
			m2=arr1[i];
			i++;
		}
		else
		{
			m1=m2;
			m2=arr2[j];
			j++;
		}
		count++;
	}
	
	return (m1+ m2)/2;
	
}

int getMedian(int arr[],int n)
{
	if(n%2==0)
	return (arr[n/2-1]+arr[n/2])/2;
	else
	return arr[n/2]/2;
}

int medianArray2(int arr1[], int arr2[], int n)
{
	    
	int m1=-1,m2=-1;
	if(n<=0)
	{
		printf("invalid input\n");
		return -1;
	}
	
	if(n==1)
	{
		return (arr1[0]+arr2[0])/2;
	}
	
	if(n==2)
	{
		int max=(arr1[0]>arr2[0]?arr1[0]:arr2[0]);
		int min=(arr1[1]>arr2[1]?arr2[1]:arr1[1]);
		return (max+min)/2;
	}
	
	else
	{
		m1=getMedian(arr1,n);
		m2=getMedian(arr2,n);
		
		if(m1==m2)
		return m1;
		
		if(m1<m2)
		{
			if(n%2==0)
				return medianArray2(arr1+n/2-1,arr2,n-n/2+1);
			else
				return medianArray2(arr1+n/2,arr2,n-n/2);
		}
		else
		{
			if(n%2==0)
				return medianArray2(arr2+n/2-1,arr1, n-n/2+1);
			else
				return medianArray2(arr2+n/2,arr1,n-n/2);
		}
	}
	
}




int main()
{
	int arr1[] = {1, 2, 3, 6};
    int arr2[] = {4, 6, 8, 10};
	
	int n=sizeof(arr1)/sizeof(int);
	
	int i;
	
	
	int median = medianArray1(arr1,arr2,n);
		
	printf("\nMedian element of given arrays by methon 1 is and complexity is O(n)\n");
	printf("%d ", median);
	
	median = medianArray2(arr1,arr2,n);
		
	printf("\nMedian element of given arrays by methon 2 is  and complexity is O(logn)\n");
	printf("%d ", median);
	
	
	
		
	return 0;
}
