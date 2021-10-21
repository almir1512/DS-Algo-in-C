#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left ;
    struct node *right;
};
struct node *createNode(int data){
    struct node *n;  //creating a node pointer 
    n=(struct node *)malloc(sizeof(struct node)); //allocating in heap
    n->data=data;
    n->left=NULL;  //setting the left and right pointer as null
    n->right=NULL;
 
    return n;  //finally returning the created node
}
void preorder(struct node* p){
    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(struct node* p){
    if(p!=NULL){
        
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }

}
void Inorder(struct node* p){
    if(p!=NULL){
        
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
        
    }

}
int isBST(struct node *p){
    static struct node *prev=NULL;
    if(p!=NULL){
        if(!isBST(p->left)){
            return 0;
        }
        if(prev!=NULL && p->data <= prev->data)
        {
            return 0;
        }
        prev=p;
        return isBST(p->right);

    }
    else {
        return 1;
    }

}
struct node * search(struct node* p,int data){
    if(p==NULL){    // the root is null 
        return NULL;
    }
    if(p->data==data){   //if we find what we are searching in the root 
        return p;
    }
    else if(p->data>data){  //if the no is less than the root then we check the left subtree
        return search(p->left,data);       //performing recursive search 
    }
    else{
        return search(p->right,data); //if the no is greater than the root then we check the right subtree
    }

}
struct node* iterSearch(struct node *p,int data){
    while (p!=NULL){

    if(data==p->data){
        return p;
    }
    else if(data<p->data){
        p=p->left;  // we change the root    //using loop to shift the root
      // consider left subtree as a BST

    }
    else{
        p=p->right; // we change the root 
      // consider right subtree as a BST
    }
   }
   return NULL;

}
void insert(struct node *p,int key){
    struct node* prev=NULL;
    while(p!=NULL)
    {
        prev=p;
        if(key==p->data)
        {
            printf("We cannot insert %d.It is already present",key);
            return;
        }
        else if(key<p->data)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    struct node *new=createNode(key);
    if(key<prev->data){
        prev->left = new;

    }
    else{
        prev->right= new;
    }

}
struct node *inPredecessor(struct node* p){
    p=p->left;
    while(p->right!=NULL){
        p=p->right;
    }
    return p;
}
struct node* deletion(struct node *p,int data){
    struct node * iPre;
    if(p==NULL){
        return NULL;
    }
    if(p->left==NULL && p->right==NULL){
        free(p);
        return NULL;
    }
    if (data < p->data)
    {
       p->left=deletion(p->left,data);

    }
    else if(data > p->data)
    {
        p->right=deletion(p->right,data);
    }
    else{
        iPre=inPredecessor(p);
        p->data=iPre->data;
        p->left=deletion(p->left,iPre->data);
    }
    return p;

}
 int main()
{
   

    struct node *p=createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);
    p->left=p1;  //linking the first and second child of parent node
    p->right=p2;
    p1->left=p3;  //linking the third and fourth of first node
    p1->right=p4;
    /* tree:
          5
         / \
        3   6
       / \ 
      1   4      */

    
  
   Inorder(p);
   deletion(p,6);
   printf("\n");
   Inorder(p);

   
    return 0;
}