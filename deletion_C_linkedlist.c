#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node *ptr=head;
    do {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node *deleteatStart(struct node *head){
    struct node *q=head;
    struct node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    head=head->next;
    p->next=head;
   
    free(q);
    
    return head;
}
struct node *deleteatEnd(struct node *head){
    struct node *p=head->next;
    struct node *q=p->next;
    while (q->next!=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);

    
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
    head=deleteatEnd(head);
    
    printf("\nAfter deletion \n");
    display(head);
    return 0;
}