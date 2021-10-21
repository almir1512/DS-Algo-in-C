#include<stdio.h>
#include<stdlib.h>
struct queue{
   
    int size;
    int f;
    int r;
    int *arr;

};
int isFull(struct queue *q)
{ 
    if(q->r == q->size-1){
    return 1;
    }
    return 0;
    
}
int isEmpty(struct queue *q)
{ 
    if(q->f == q->r){
    return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int value)
{
    if(isFull(q))
    {
        printf("Queue is FULL!");
    }
    else{
        q->r++;
        q->arr[q->r]=value;
    }
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else{
        q->f++;
        a=q->arr[q->f];
      
    }
return a;
}
    int main()
{
    struct queue q;
    q.size=100;
    q.f = q.r = -1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q,10);
    enqueue(&q,12);
    enqueue(&q,15);
    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));
    
    if(isEmpty(&q))
    {
        printf("Queue is Empty");
    }
    if(isFull(&q))
    {
        printf("Queue is FUll");
    }
    return 0;
}