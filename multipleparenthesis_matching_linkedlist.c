#include<stdio.h>
#include<stdlib.h>
struct node {           //creating stack using linked list
    char data;
    struct node *next;
}; 
 struct node *top;
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

char pop(struct node *tp)  // global variable and local variable cannot be of same name
{


    if(isEmpty(tp))
    {
        printf("Stack Underflow!");
    }
    else
    {
        struct node *ptr=tp;
        top=tp->next;   // first deferencing then taking the value using arrow operators
        int x=ptr->data;
        free(ptr);

        return x;
    }
}
int match(char a,char b){
    if(a=='{' && b=='}') 
    {
        return 1;
    }
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    return 0;

}
int isbalanced(char *exp)
{   char popped_char;
   
    for(int i=0;exp='\0';i++)
    {
        if(exp[i]=='(' ||exp[i]=='{' || exp[i]=='[')
        {
            push(top,exp[i]);
        }
        else if(exp[i]==')' ||exp[i]=='}' || exp[i]==']')
        {
            if(isEmpty(top))
            {
                return 0;
            }
            popped_char=pop(&top);
            if(!match(popped_char,exp[i])){
            return 0;
            }

        }
    }

 if(isEmpty(top)){
    return 1;
 }
 else{
    return 0;
 }
}
    int main()
{   
    char *exp="{1+9}[8+9](2*70";
    if(isbalanced(exp))
    {
        printf("Parenthesis is balanced");
    }
    else{
    printf("Parenthesis is not balanced");
    }
    
    return 0;
}