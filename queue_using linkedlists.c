#include<stdio.h>
#include<stdlib.h>

  struct node *f=NULL;
  struct node *r=NULL;
struct node{
  int data;
  struct node* next;
};
void display(struct node *p)
{
    while(p!=NULL){
    printf("\nElement : %d",p->data);
    p = p->next;
    }

}
void enqueue(int value)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if (n==NULL)
    {
        printf("Queue is Full");
    }
    else{

        n->data=value;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }

}
int dequeue (){
    int val=-1;
    struct node *ptr=f;
    if(f==NULL)
    {
        printf("\nQueue is empty");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }

return val;

}
    int main()
{

    printf("\nDequeueing element %d",dequeue());
    enqueue(10);
    enqueue(1);
    enqueue(50);
    printf("\nDequeueing element %d",dequeue());
    display(f);

    return 0;
}
