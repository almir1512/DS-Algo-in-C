#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack {
   int size;
   int top;
   char *arr;  // character array
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
int peek (struct stack *ptr,int i)
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
char stackTop(struct stack *ptr )
{
    return ptr->arr[ptr->top];
}

char stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int prec(char ch)
{
    if(ch=='*')
    {
        return 6;
    }
    else if(ch=='/')
    {
        return 5;
    }
    else if(ch=='%')
    {
        return 4;
    }

    else if(ch=='+')
    {
        return 3;
    }
    else if(ch=='-')
    {
        return 2;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){

    if(ch=='*'||ch=='+'||ch=='-'||ch=='/')
    {
        return 1;

    }
    else{
        return 0;
    }
}

char *infixtopostfix(char *infix)
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));  // stack
    sp->size=100; 
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));  // array for postfix exp
    int i=0;  // index for scanning infix
    int j=0;  // index for filling postfix

    while(infix[i]!='\0')
    {
       if(!isOperator(infix[i]))  // not an operator
        {
          postfix[j]=infix[i];
          j++;i++;
        }
       else{                       // it is an operator
           if(prec(infix[i])>prec(stackTop(sp)))
           {
               push(sp,infix[i]);
               i++;
           }
           else{
            postfix[j]= pop(sp);
            j++;
           }
        }

    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *infix="a - ( b / c + ( d % e * f ) / g) * h" ;  // array for infix exp
    printf("postfix is %s",infixtopostfix(infix));
    return 0;

}
