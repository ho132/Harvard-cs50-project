#include<stdio.h>
cc
#icwwc

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
    {

        {

            int *result=malloc(2*sizeof(int));
           int sum=nums[i]+nums[j];
            if(sum==target)
            {
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                printf("Output:[%i,%i]",result[0],result[1]);

return result;
            }
            free(result);
        }
    }
    }
    return NULL;
}
