#include <stdio.h>
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int binarysearch(int arr[], int size, int element)
{
    int low = 0, mid;
    int high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 22, 69, 98, 155, 225, 516, 855, 958};
    int size = sizeof(arr) / sizeof(int);
   
    int element;
    printf("Enter the element : ");
    scanf("%d", &element);
    int index = binarysearch(arr, size, element);

    printf("Element %d was found at index %d", element, index);

    return 0;
    
}