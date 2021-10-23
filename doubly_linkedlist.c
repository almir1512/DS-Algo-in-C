// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node *head ,*tail =NULL;

struct node {
  int data;
  struct node *next;
  struct node *prev;
};
void display(){  //no need to pass head because it is global
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void addNode(int data){
        struct node *newnode =(struct node *)malloc (sizeof(struct node));
        newnode->data=data;
    if(head==NULL){
        head=tail=newnode;
        head->prev=NULL;
        tail->next=NULL;
        
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;  // important
        tail=newnode;
        tail->next=NULL;
    }
}
int main() {
  addNode(1);
  addNode(1);addNode(1);addNode(1);addNode(1);addNode(1);addNode(1);addNode(1);
  display(head);
  
    
    return 0;
}