// Online C compiler to run C program online
#include <stdio.h>

#define MAX 5
int queue [MAX];
int front,rear=-1;
void insert ()
{
    int val;
    printf("Enter the element :");
    scanf("%d",&val);
    if(rear==MAX-1)
    {
        printf("overflow!");
    }
    else if(rear==-1 && front==-1){
        front =rear= 0;
    }
    else{
        rear++;
        queue[rear]=val;
    }
    
}
void display(){
    for (int i = front ; i <= rear; i++)
    {
         printf("%d ",queue[i]);
    }
    
   
}
int main() {
   insert ();
   insert ();
   insert ();
   display();

    return 0;
}