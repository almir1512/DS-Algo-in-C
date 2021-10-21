#include<stdio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    char *arr;

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
void push(struct stack * ptr,char value)
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
int isOperator(char ch){
    if(ch=='+'||ch=='*'||ch=='-'||ch=='/'||ch=='%'||ch=='^'){
        return 1;

    }
    else{
        return 0;
    }
}
int precedence (char ch){
    if(ch=='*'){
        return 5;
    }
    else if(ch=='/'){
        return 4 ;
    }
    else if(ch=='+'){
        return 3;
    }
    else if(ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
int stackTop(struct  stack *sp){
 return sp->arr[sp->top];
}
int stackBottom(struct stack *sp){
    return sp->arr[0];
}


char *infixtoPostfix(char *infix){   // return type = string 

    // create stack inside this function 
    struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=100;
    sp->arr=(char *)malloc (sp->size*sizeof(char));
    int i=0; // scanning infix exp
    int j=0; // filling in postfix exp

    char *postfix= (char * )malloc ((strlen(infix)+1) * sizeof(char));  // creating postfix exp string 

    push(sp,'('); //step 2

    while(infix[i]!='\0')  // step 3 -> method to scan all elements in the string 
    {
        if(!isOperator(infix[i])){  // when operand is encountered
            postfix[j]=infix[i];
            i++;j++;
        } 
        else{ // when operator is encountered
            if(precedence(infix[i])>precedence(stackTop(sp))){  //higher precedence than the operator in stack 
                push(sp,infix[i]);
                i++;
            }
                postfix[j]=pop(sp);
                j++;
            }
        }
        if(infix[i]=='('){
            push(sp,'(');
        }
        
        if(infix[i]==')'){
            while(sp->arr[sp->top]!='('){
                postfix[j]=pop(sp);
                j++;
            }
        
        }
        
    }
    while(!isEmpty(sp))
    {     //step 4
        postfix[j]=pop(sp);
        j++;
    }

    postfix[j]='\0';
    return postfix;
}
    int main()
{
   char *infix="a - ( b / c + ( d % e * f ) / g) * h)";
    printf("postfix expression is %s",infixtoPostfix(infix));

    return 0;
}
