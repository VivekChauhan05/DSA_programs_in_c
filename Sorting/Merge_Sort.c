#include<stdio.h>
#include<stdlib.h>
void Merge_Sort();
void Merge();

void Merge_Sort(int arr[],int low,int high)
{
    int mid = low + (high - low)/2 ;
    if(low<high)
    {  
    Merge_Sort( arr,low,mid);
    Merge_Sort(arr,mid+1,high);
    Merge( arr,low,mid,high);
    }
}

void Merge(int arr[],int low,int mid,int high)
{
    int n1;
    int n2;
    n1 = mid-low+1;
    n2 = high-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i] = arr[low+i];
    }

    for(int j=0;j<n2;j++)
    {
        R[j] = arr[mid+1+j];
    }

    int i =0;
    int j =0;
    int k = low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j]; 
        j++;
        k++;
    } 
}


int main()
{
   int n;
   printf("Enter the length of array :\n");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the element of array :\n");
   for(int i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   int low = 0;
   int high = n-1;
   Merge_Sort(arr,low,high);

   printf("Sorted array is :\n");
    for(int i=0;i<n;i++)
   {
      printf("%d ",arr[i]);
   }

   return 0;
}
