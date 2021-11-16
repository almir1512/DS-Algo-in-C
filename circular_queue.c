#include<stdio.h>

#define size 5
int arr [size];
int front=-1, rear = -1; // always define differently 


int isF(){
    if ((front == rear+1 )|| (front==0 && rear==size-1)){
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}
void display ( ){
    int i ;
    if (isEmpty()){
        printf ( "Empty Queue ");
    }
    else {
        printf("Front -> %d\n ", front);
        printf("Queue - > ");
        for ( i = front; i!=rear ; i=(i+1) % size)
        {
            printf(" %d",arr[i]);
        }
        printf(" %d\n",arr[i]); // will not print the last element as the loop will end when, i == rear 
        printf("Rear -> %d\n ", rear);

    }
}

void enQueue (int element){
    if (isF()){
        printf("Queue is full !\n");
    }
    else {
        if (front == -1 )
        {
          front = 0 ;
        }
        rear =(rear + 1) % size ;
        arr [ rear ] = element;
        printf("inserted -> %d \n", element);
    }
   
}
int deQueue() {
  int element;
  if (isEmpty()){
    printf("\n Queue is empty !! \n");
    return (-1);
  }
  else {
    element = arr[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % size;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

    int main()
{
    deQueue ();  // will fail bcoz front = -1 
    
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();
  
  display();

  enQueue(7);
  display();

  // Fails to enqueue because front == rear + 1
  enQueue(8);

  return 0;

    return 0;
}