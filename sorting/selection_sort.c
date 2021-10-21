#include<stdio.h>
void print(int arr[],int n)
{   int i=0;
    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
}
void selectionsort(int arr[],int n)
{
   printf("\nRunning the selectionsort algo:\n");
   int indexofMIN,temp;
   for(int i=0;i<n-1;i++)
   {
       indexofMIN=i;
       for(int j=i+1;j<n;j++)
       {
           if(arr[indexofMIN]<arr[j])   //condition for swapping 
           {
               indexofMIN=j;
           }
       }
       temp=arr[i];
       arr[i]=arr[indexofMIN];
       arr[indexofMIN]=temp;
   }
}
    int main()
{
    int arr[]={23,1,65,44,26,7};
    int n=6;
    print(arr,n);
    selectionsort(arr,n);
    print(arr,n);
    return 0;
}