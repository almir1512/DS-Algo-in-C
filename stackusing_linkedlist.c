#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element %d \n",ptr->data);
        ptr=ptr->next;
    }
}
int isEmpty(struct node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *top)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));

    if(n==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node * push(struct node *top,int a)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=a;
    if(isFull(top))
    {
        printf("Stack Overflow!");
    }
    else
    {
        ptr->next=top;
        top=ptr;

        return top;
    }
}
int pop(struct node **top)  // global variable and local variable cannot be of same name
{
    if(isEmpty(top) )
    {
        printf("Stack Underflow!");
    }
    else
    {
        struct node *ptr=*top;
        *top=(*top)->next;   // first deferencing then taking the value using arrow operators
        int x=ptr->data;
        free(ptr);

        return x;
    }

}
int peek(struct node *top,int position)
{
    struct node *ptr=top;
    for(int i=0;(i<position - 1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}


int main()
{
    struct node *top=NULL;
    top= push (top,5);
    top= push (top,4);
    top= push (top,3);
    top= push (top,2);
    display(top);

    // printf("%d is popped ! \n",pop(&top));      // we need to top the value and passs to function (&top)
                                                   // or I can declare a global variable and chanage the name of the local variables
    // display(top);

for(int i = 0; i < 4; i++)
{
  printf("Value at position %d : %d\n",i+1,peek(top,i+1));
}
    return 0;
}
