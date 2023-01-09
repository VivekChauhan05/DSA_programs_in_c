#include<stdio.h>

int binary_search(int a[], int l, int r, int item);

void main()
{
    int a[] = {1, 7, 12, 19, 20, 39, 45};
    int n = sizeof(a);
    int item = 45;
    int l =0;
    int r = n-1;

    int ans = binary_search(a,l,r,item);
    printf("\n%d\n",ans);
    
}

int binary_search(int a[], int l, int r,int item)
{
        int mid = l+(r-l)/2;
        if (item == a[mid])
        {
            return mid;
        }
        else if (item < a[mid])
        {
            return binary_search(a,l,mid-1,item);
        }
        else
        {
            return binary_search(a,mid+1,r,item);
        }   
}