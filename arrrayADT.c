#include<stdio.h>
#include<stdlib.h>

typedef struct myArray{
    int tsize;
    int usize;
    int *ptr;  // imp to declare a pointer 

}almir;
void createARRay(int t,int u,almir *a){
    (*a).tsize=t;   // arrow operator 
    (*a).usize=u;   // a->usize=u
    
    a->ptr=(int *)malloc(t * sizeof(int));  // creating dma in heap
}
void setval(almir *a){
    int n;
    for (int i = 0; i < a->usize; i++)
    {
        printf("enter element %d: ",i);
        scanf("%d",&n);
        a->ptr[i]=n;
    }
    
}
void show(almir *a){
    for (int i = 0; i < a->usize; i++)
    {
       printf("%d\n",a->ptr[i]);
    }
    
}




    int main()
{
    almir marks;
    createARRay(15,3,&marks);
    printf("running set val function\n");
    setval(&marks);
    printf("running show function\n");
    show(&marks);
    return 0;
}