#include <stdio.h>
void print(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low], temp;
    int i = low + 1;
    int j = high;
    do   // is for repeating the 1. and 2. until i>=j
    {  
        while (arr[i] <= pivot) // 1. incrementing the i unitl elemnent > pivot
        {
            i++;
        }
        while (arr[j] > pivot) //  2. decrementing the j unitl element <= pivot
        {
            j--;
        }
        if (i < j)
        {
            //swapping the arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    //swapping the pivot and arr[j]
    temp=arr[low];   
    arr[low]=arr[j];
    arr[j]=temp;
    return j;   //returning j to the function 
}
void quicksort(int arr[], int low, int high)
{
    int partitionIndex;
    if(low<high){
    partitionIndex = partition(arr, low, high); //returning the value of j
    quicksort(arr, low, partitionIndex-1); // sorting left subarray
    quicksort(arr, partitionIndex+1, high); //sorting right subarray
    }
}
int main()
{
    int arr[] = {1, 268, 5, 0, 78, 56, 2};
    int n = 7;
    print(arr, n);
    quicksort(arr, 0, n - 1);  // low = 0    high = n-1
    printf("\n");
    print(arr, n);
    return 0;
}