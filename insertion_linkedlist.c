#include<stdio.h>
#include<stdlib.h>

struct node{                            //creation of linked list  
    int data;
    struct node *next;
};

//PRINTING LINKEDLIST

void display(struct node *ptr)         
{
    while(ptr!=NULL){
    printf("\nElement : %d",ptr->data);
    ptr = ptr->next;
    }

}

//  1. INSERTION AT STARTING


struct node * insertStart(struct node *head,int a)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=a;    // a=12

    return ptr;
}
   
//  1. INSERTION AT GIVEN INDEX


struct node * insertatIndex(struct node *head,int a,int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1){    // p pointer 
    p=p->next;            //moves pointer head by one node
    i++;
    }
    ptr->data=a;
    ptr->next=p->next;
    p->next=ptr;

    return head;
}

//  1. INSERTION AT END


struct node * insertatEnd(struct node *head, int a)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
  
    while(p->next!=NULL)
    {
        p=p->next;         // p pointer aage badho
        
    }
    ptr->data=a;
    p->next=ptr;
    ptr->next=NULL;

    return head;
}

//  1. INSERTION AT AFTER SPECIFIED NODE


struct node * insertafterNode(struct node *head,struct node *prevNode,int a)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=a;
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
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    
    //link head to second
    head->data=10;
    head->next=second;            // linking the blockss of linked list
    //link second to third
    second->data=20;
    second->next=third;
    //link third to fourth
    third->data=30;
    third->next=fourth;
    //link fourth to NULL
    fourth->data=40;
    fourth->next=NULL;


    // head=insertStart(head,40);
    int index=3;
    display(head);
    // head=insertatIndex(head,640,index);

    // head=insertatEnd(head,50);
    printf("\n");
    head = insertafterNode(head,second,45);
    display(head);

    return 0;
}