#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack *s;
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // manual initializing value in stack
    s->arr[0] = 12;
    s->top++;
    if (isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }

    return 0;
}