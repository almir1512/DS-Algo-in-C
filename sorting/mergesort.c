#include<stdio.h>
void print(int A[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%d ", A[i]);
        i++;
    }
}
void merge(int A[],int low,int high,int mid){
    int i,j,k,B[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high) 
    {
        if (A[i]<A[j])
        {
            B[k]=A[i];
            i++;k++;
        }
        else{
            B[k]=A[j];
            j++;k++;
        }
        
    }
    while(i<=mid)        //copy all remaining elements from A to C
    {
        B[k]=A[i];
        i++;k++;
    }
    while(j<=high)      //copy all remaining elements from B to C
    {
        B[k]=A[j];
        j++;k++;
    }
    for(i=low;i<=high;i++)
    {
        A[i]=B[i];
    }

}
void mergesort(int A[],int low,int high)
{
    if(low<high)
    {
    int mid=(low+high)/2;
    mergesort(A,low,mid);
    mergesort(A,mid+1,high);
    merge(A,low,high,mid);
    }
}
    int main()
{
    int A[]={1,2,5,3,4,4,11};
    int n=6;
    print(A,n);
    mergesort(A,0,5);
    printf("\n");
    print(A,n);
    
    return 0;
}