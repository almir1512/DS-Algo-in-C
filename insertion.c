#include<stdio.h>

void display(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {      
     printf("%d ",arr[i]);
    }
    
}

int indInsertion(int arr[],int size,int capacity,int index,int element)
{
    if(size>=capacity)
    {
        return -1;
    }
    
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
    int main()
{
    int arr[100]={1,2,3,5,6};
    int size=5,index,element;
    display(arr,size);
    
    printf("\nEnter the no to insert: ");
    scanf("%d",&element);
    printf("Enter the index at which you want to insert: ");
    scanf("%d",&index);
    indInsertion(arr,size,100,index,element);

    if(indInsertion(arr,size,100,index,element)==1){
    size+=1;
    display(arr,size);
    }
    else{
        printf("Insertion denied!");
    }
    return 0;
}