#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void print(int arr[],int n)
{   int i=0;
    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
}
int maximum(int a[],int n){
    int max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>max){
        max=a[i];
        }
    }
    return max;
}

void countsort(int *A,int n){
   int max=maximum(A,n); //find maximum no in array

    int *count =(int *)malloc((max+1)*sizeof(int)); //making count array dynamically
    int i,j;
    for (i = 0; i < max+1; i++)  //initialize all elements of count array to zero
    {
        count[i]=0;
    }
    for (i = 0; i < n; i++)  
    {
        count[A[i]]=count[A[i]]+1;  //intializing 0 to 1 in count array
    } 
    i=0; // counter for count array
    j=0; // counter for main array
    while(i<=max){
        if(count[i]>0){
            A[j]=i;
            count[i]=count[i]-1;
            j++;

        }
        else{
            i++;
        }
    }
}
    int main()
{
    int A[]={1,2,5,3,4,4,11};
    int n=7;
    print(A,n);
    countsort(A,n);
    printf("\n");
    print(A,n);
    
    return 0;
}