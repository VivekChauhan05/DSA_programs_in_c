#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool linear_search(int arr[],int key,int n)
{
   for(int i=0;i<n;i++)
    {
       if(arr[i] == key)
        {
           return true;
        }
    }
   return false;       
}    
int main()
{
   int n;
   printf("Enter the length of the array\n");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the elements of the array\n");
   for(int i=0;i<n;i++)
{
   scanf("%d",&arr[i]);
}
int key;
printf("Enter the element you want to find\n");
scanf("%d",&key);

int result = linear_search(arr,key,n);

if(result == true)
{
   printf("Element found\n");
}
else
{
   printf("Element not found\n");
}
}