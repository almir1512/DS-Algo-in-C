#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node *ptr)         
{
    while(ptr!=NULL){
    printf("\nElement : %d",ptr->data);
    ptr = ptr->next;
    }

}

struct node *deleteatStart(struct node *head)
{
        
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node *deleteatEnd(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    
  
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }

    p->next=NULL;
    free(q);

    return head;
}

struct node *deleteinbetween(struct node *head,int index)
{
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
    }
    struct node *q=p->next;
    p->next=q->next;
    free(q);
    return head;
}

struct node *deleteafterNode(struct node *head,int a)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=a && q->data!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data=a){
    p->next=q->next;
    free(q);
    }
    return head;    
}

    int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    
    //link head to second
    head->data=1;
    head->next=second;
    //link second to third
    second->data=2;
    second->next=third;

    //link third to null
    third->data=3;
    third->next=NULL;
   
    head=deleteafterNode(head,2);
    
    display(head);
    
    
    return 0;
}