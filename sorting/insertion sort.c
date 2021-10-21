#include<stdio.h>
void print(int arr[],int n)
{   int i=0;
    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
}
void insertionsort(int arr[],int n)
{
    int key,j;
    for (int i = 0; i < n-1; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]<key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }


}
    int main()
{
    int arr[]={1,2,6,9,5};
    int n=5;
    print(arr,n);
    insertionsort(arr,n);
    printf("\n");
    print(arr,n);
    return 0;
}
