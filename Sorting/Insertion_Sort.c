#include<stdio.h>
#include<stdlib.h>
void Insertion_Sort(int arr[],int n)
{
    for(int i = 1;i<n;i++)
    {   
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;}
    arr[j+1] = key;}
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
   Insertion_Sort(arr,n);
   printf("Sorted array is :\n");

    for(int i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
   return 0;
}