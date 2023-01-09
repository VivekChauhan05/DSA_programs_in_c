#include<stdio.h>
#include<stdlib.h>

void Selection_Sort(int arr[], int n)
{
   for(int i = 0; i<n-1;i++)
   {
      int min = i;
      for(int j = i+1; j< n;j++)
      {
         if(arr[min]>arr[j])
         {
             min = j;
         }

      }
      int key = arr[min];
      while(min>i)
      {
         arr[min] = arr[min-1];
         min--;
      }
      arr[i] = key;
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
   Selection_Sort(arr,n);
   printf("Sorted array is :\n");
    for(int i=0;i<n;i++)
   {
      printf("%d ",arr[i]);
   }

   return 0;
}