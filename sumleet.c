#include <stdlib.h>
#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) ;

int main(void)
{

int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array based on user input
    int* nums = (int*)malloc(size * sizeof(int));

    if (nums == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;  // Exit with an error code
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; ++i) {
        printf("nums[%d]: ", i);
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);

    int returnSize = 0;
    int* result = twoSum(nums, size, target, &returnSize);

    if (result != NULL) {
        printf("Output: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    // Don't forget to free the dynamically allocated memory
    free(nums);

    return 0;
}





int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int minvalue = 0;
    int maxvalue = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxvalue) {
            maxvalue = nums[i];
        }
        if (nums[i] < minvalue) {
            minvalue = nums[i];
        }
    }

    // Calculate the range of values and allocate hashtable accordingly
    int range = maxvalue - minvalue + 1;
    int* result = malloc(2 * sizeof(int));
    int* hashtable = malloc(range * sizeof(int));

    if (result == NULL || hashtable == NULL) {
        free(result);
        free(hashtable);
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int missing = target - nums[i];

        if (missing >= minvalue && missing <= maxvalue && hashtable[missing - minvalue] != 0) {
            result[0] = hashtable[missing - minvalue] - 1;
            result[1] = i;
            *returnSize = 2;
            free(hashtable);
            return result;
        }

        hashtable[nums[i] - minvalue] = i + 1;
    }

    free(hashtable);
    free(result);
    return NULL;
}

