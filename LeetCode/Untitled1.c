// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   int i,j;
        returnSize=(int *)malloc (2* sizeof(int));
        for(i=0;i<numsSize;i++)
        {
            for(j=1;j<numsSize-1;j++){
               if(nums[i]+nums[j]==target ){
               returnSize[0]=i; returnSize[1]=j;
                for(int i=0;i<2;i++){

                return returnSize;
                }

               }
            }

        }

return NULL;
}
int main() {
    // Write C code here
    int size,target;
    printf("Enter size");
    scanf("%d",&size);
    int arr[size],arr5[2];
   printf("Enter the values in  aray:");

   for(int i=0;i<size;i++){
   scanf ("%d",&arr[i]);
}
printf("Enter target : ");
scanf("%d",&target);
    twoSum(arr,size,target,arr5);

    return 0;
}
