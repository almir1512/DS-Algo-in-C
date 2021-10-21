#include<stdio.h>
struct queue {
int size;
int f;
int r;
int *arr;

};
int isFull(struct queue *q)
{ 
    if(q->r=(q->r+1)%q->size == q->f){                          //i=i+1%size
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
void enqueue (struct queue *q,int value )
{
    if(isFull(q))
    {
        printf("Queue is full");

    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r]=value;
        printf("Enqueued element : %d\n",value);
    }
}
int dequeue (struct queue *q)
{
    int value=-1;
    if(isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else {
        q->f = (q->f +1)%q->size;
        value=q->arr[q->f];
        
    }
}

    int main()
{
    struct queue q;
    q.size=4;
    q.f = q.r = 0;  //in circular queue always f and r star from 0
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q,10);
    enqueue(&q,12);
    enqueue(&q,15);
    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));
    enqueue(&q,55);
    enqueue(&q,6);
    enqueue(&q,25);

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