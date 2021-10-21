#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node* next;
    struct node* prev;

};
void display(struct node *ptr){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }

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

    //link first to second
    head->prev=NULL;
    head->data=1;
    head->next=second;
    //link second to third 
    second->prev=head;
    second->data=2;
    second->next=third;
    //link third to fourth
    third->prev=second;
    third->data=3;
    third->next=fourth;
    //link fourth to null
    second->prev=third;
    second->data=4;
    second->next=NULL;

    display(head);
    return 0;
}