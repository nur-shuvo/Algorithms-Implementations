//** Binary search
//** Time complexity O(log2 n)
//** Data should be sorted first
//** If it is required to search (** only one time **) then linear search is better
//** It is assumed that the data are sorted in ascending order in this code0
#include<stdio.h>
int binary_search(int arr[],int size,int search)
{
    int first,last,middle;
    int result=0;
    first=0;
    last=size-1;

    while(first<=last){
        middle=(first+last)/2;
        if(arr[middle]<search)
            first=middle+1;
        else if(arr[middle]==search){
            result=1;
            break;
        }
        else
            last=middle-1;
    }
    return result;
}
int main()
{
    int arr[100],size,i,search;
    while(scanf("%d",&size)==1){
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&search);
    if (binary_search(arr,size,search)==1)
        printf("Found\n");
    else
        printf("Not found\n");
    }
}

