#include<stdio.h>
#include<stdlib.h>

int merge(int arr[], int start,int mid,int end)
{
	
	int inversion_count=0;
	
	int i, j, k;
    int n1 = mid - start + 1;
    int n2 =  end - mid;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];
 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = start; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            inversion_count+=n1-i;
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
	return inversion_count;
	
}

int mergeSort(int arr[],int start, int end)
{
	int inversion_count=0;
	if(start<end)
	{
		int mid = (start+end)/2;
		inversion_count=mergeSort(arr,start,mid);
		inversion_count+=mergeSort(arr,mid+1,end);
		inversion_count+=merge(arr,start,mid,end);
    }
    
    return inversion_count;
}
int main()
{
	int arr[]={1, 20, 6, 4, 5};
	int n = sizeof(arr)/sizeof(int);
	int i,inversion_count=0;
	
	
    inversion_count = mergeSort(arr,0,n-1);
	
	printf("after sorting array is \n");
	for(i=0;i<n;i++)
	    printf("%d ", arr[i]);
	    
	printf("inversion count is %d \n",inversion_count);
	
}
