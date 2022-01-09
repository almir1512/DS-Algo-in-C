#include<stdio.h>
#include<stdlib.h>
struct stack {
   int size;
   int top;
   int *arr; 
};
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * ptr,int value)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow! %d Cannot be added.\n",value);
    
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }

}
int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow! All elements popped!\n");
        return -1;
    }
    else{
    int value=ptr->arr[ptr->top];
    ptr->top--;
    return value;
    }
}
int peek (struct stack *ptr,int i)  //
{
   
    if(ptr->top-i+1<0)
    {
        printf("Invalid positon !");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}
int stackTop(struct stack *ptr )
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}
    int main()
{
    struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=10;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("Before pushing : %d \n",isEmpty(sp));
    printf("Before pushing : %d \n",isFull(sp));
    push(sp,200);
    push(sp,22);
    push(sp,22);
    push(sp,100);
    

    printf("After pushing : %d \n",isEmpty(sp));
    printf("After pushing : %d \n",isFull(sp));
    // for(int j=1;j<=sp->top+1;j++)                   // to view all elements in stack
    // {
    //     printf("position %d = %d \n",j,(peek(sp,j)));
    // }
   
    printf("the topmost value of stack is : %d",stackTop(sp));
     printf("\nthe bottom-most value of stack is : %d",stackBottom(sp));
    

   
}