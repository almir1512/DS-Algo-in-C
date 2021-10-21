#include<stdio.h>
#include<stdlib.h>
struct node {           //creaing stack using linked list
    char data;
    struct node *next;
}; 
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
int isFull()
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
struct node * push(struct node *top,char a)
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

char pop(struct node **top)  // global variable and local variable cannot be of same name
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
int isbalanced(char *exp)
{   
    struct node *top;
    for(int i=0;exp='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(top,exp[i]);
        }
        else if(exp[i]==')')
        {
            if(isEmpty(top))
            {
                return 0;
            }
            pop(&top);
        }
    }


}
    int main()
{   
    char *exp="1*3)))(4+5)";
    if(isbalanced(exp))
    {
        printf("Parenthesis balanced");
    }
    else{
    printf("Parenthesis is not balanced");
    }
    
    return 0;
}