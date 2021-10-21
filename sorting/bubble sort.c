#include<stdio.h>
void print(int arr[],int n)
{   int i=0;
    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
}
void bubblesortAdaptive(int arr[],int n)
{
    int flag=0;            // setting flag
    for(int i=0;i<n-1;i++)   //no of passes
    {
     printf("pass %d\n",i+1);
            flag=1;
        for(int j=0;j<n-1-i;j++)  //no of comparison
        {

            if(arr[j]>arr[j+1])
            {
                int temp;     //swapping
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=0;
            }
        }
        if(flag){   //if flag is set then return the entire function
            return;
        }
    }
}
void bubblesort(int arr[],int n)
{

    for(int i=0;i<n-1;i++)   //no of passes
    {
     printf("\npass %d\n",i+1);

        for(int j=0;j<n-1-i;j++)  //no of comparison
        {

            if(arr[j]>arr[j+1])
            {
                int temp;     //swapping
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }

    }
}
    int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=6;
    print(arr,n);
    bubblesortAdaptive(arr,n);
    printf("\nSorted array: \n");
    print(arr,n);

    print(arr,n);
    bubblesort(arr,n);
    printf("\nSorted array: \n");
    print(arr,n);   return 0;
}
