
#include"leetCode.h"
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int sum = 0;
    int* resultNums = NULL;
    if ((resultNums = (int*)malloc(numsSize * sizeof(int))) == NULL) {
        exit(-1);
    }
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        *(resultNums + i) = sum;
    }
    return resultNums;
}