#include<stdio.h>
#include<stdlib.h>


int binary_search(int arr[],int low,int high,int key)
{
   int mid = low + (high - low)/2;
   while(low<=high)
   {
    if(arr[mid]>key)
    {
        high = mid-1;
    }
    if(arr[mid]<key)
    {
        low  = mid+1;
    }
    if(arr[mid]==key)
    {
        return mid;
    }
   }
   return -1;
}
int main()
{
    int n;
    printf("Enter the length of the array\n");
    scanf("%d",&n);
    printf("Enter the elements in the array in ascending order\n");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int low = 0;
    int high = n-1;
    int key;
    printf("Enter the element you want to find \n");
    scanf("%d",&key);
    int result = binary_search(arr,low,high,key);
    if(result != -1)
    {
        printf("Element is present in the array at index %d : ",result);
    }
    else
    {
        printf("Element is not present in the array.\n");
    }
    
    return 0;
}
