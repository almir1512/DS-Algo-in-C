#include<stdio.h>
struct queue
{
    int size;
    int r;
    int f;
    int *arr;
};
void enqueueR(struct queue *q,int val){
    if(q->r == q->size -1)
    {
        printf("Queue is Full");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
    
}
int dequeueF(struct queue *q){
    int val=-1;
    if(q->f == q->r)
    {
        printf("Queue is Empty");
    }
    else{
        q->f++;
        val=q->arr[q->f];
    }
    return val;
}
void enqueueF(struct queue *q,int val){
    if(q->r == q->size -1)
    {
        printf("Queue is Full");
    }
    else{

    }
}
int dequeueR(struct queue *q)
{
    int val=-1;
    if(q->f == q->r)
    {
        printf("Queue is Empty");
    }
    else{
        val=q->arr[q->r];
        q->r--;
    }
    return val;
    
}

  int main()
{
    struct queue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    return 0;
}