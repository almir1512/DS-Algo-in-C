#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * ptr;
};
void print(struct node *ptr1)
{
    while(ptr1!=NULL){
    printf("\nElement :%d",ptr1->data);
    ptr1=ptr1->ptr;
    }
}
    int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    //link first to second
    head->data=1;     //  = (*head).data=1
    head->ptr=second;
    //link second to third
    second->data=2;
    second->ptr=third;
    //end linked list
    third->data=3;
    third->ptr=NULL;

    print(head);



    return 0;                               
}