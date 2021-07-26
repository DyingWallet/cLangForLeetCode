#include"leetCode.h"
#include"leetCodeStructs.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define WEIGHT 1000
#define MAX 2001

int* twoSum_167(int* numbers, int numbersSize, int target, int* returnSize) {
	int* res = (int*)calloc(2, sizeof(int));
	(*returnSize) = 2;

	int targetTable[MAX] = { 0 };
	int temp = 0;

	for (int index = 0; index < numbersSize; index++) {
		temp = target - numbers[index] + WEIGHT;
		if (0 <= temp && temp <= 2000)
			targetTable[temp] = index;
	}
	temp = 0;

	for (int i = 0; i < numbersSize; i++) {
		temp = targetTable[numbers[i] + WEIGHT];
		if (temp != 0) {
			i++, temp++;
			res[0] = temp > i ? i : temp;
			res[1] = temp > i ? temp : i;
			break;
		}
	}
	return res;
}