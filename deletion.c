#include<stdio.h>
void display(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
int indDeletion(int arr[],int size,int index)
{
    for (int i = index; i <= size-1; i++)
    {
       arr[i]=arr[i+1];
    }
    
}

    int main()
{
    int arr[100]={1,2,3,4,5,6};
    int size=6,index;
    display(arr,size);
    printf("Enter index to delete: ");
    scanf("%d",&index);
    indDeletion(arr,size,index);
    size-=1;
    display(arr,size);
    return 0;
}