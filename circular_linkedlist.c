#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head)
{
   struct node *ptr=head;
   
   do
   {
       printf("\nElement = %d",ptr->data);
       ptr=ptr->next;
   }while (ptr!=head);
    
}
struct node * insertatfirst(struct node *head,int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p=head->next;
    ptr->data=data;
    while(p->next!=head)
    {
        p=p->next;    //p will point last node
    }
   
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;    
}
struct node * insertatEnd(struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    
    while (p->next!=head)
    {
        p=p->next;
        
    }
    p->next=ptr;
    ptr->next=head;

    return head;
}

struct node * insertafterIndex(struct node *head,int index,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head->next;
    int t=0;
    while(t!=index-1)
    {
        p=p->next;  //move ahead before the inserted pointer
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    
    return head;
}
struct node *insertafterNode(struct node *head,int data ,struct node* prevNode)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
   
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;

    return head;

}


    int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
   fourth=(struct node *)malloc(sizeof(struct node));
    

    //link head to second
    head->data=1;
    head->next=second;
    //link second to third
    second->data=2;
    second->next=third;
    //link third to fourth 
    third->data=3;
    third->next=fourth;
    //link fourth to head
    fourth->data=4;
    fourth->next=head;
    
    display(head);
    head=insertafterNode(head,677,third);
    
    printf("\nAfter insertion");
    display(head);
    return 0;
}