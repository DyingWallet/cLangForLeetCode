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

//¶þ·Ö
//int* twoSum_167(int* numbers, int numbersSize, int target, int* returnSize) {
//	int* res = (int*)calloc(2, sizeof(int));
//	(*returnSize) = 2;
//	int resVal, left, right, mid;
//
//	for (int i = 0; i < numbersSize; i++) {
//		resVal = target - numbers[i];
//		left = 0; right = numbersSize - 1, mid = left + (right - left) / 2;
//		while (left <= right) {
//			if (resVal == numbers[mid]) {
//				if (mid == i)
//					mid += 1;
//				res[0] = i + 1;
//				res[1] = mid + 1;
//				return res;
//			} else if (resVal < numbers[mid]) {
//				right = mid - 1;
//			} else if (resVal > numbers[mid]) {
//				left = mid + 1;
//			}
//			mid = left + (right - left) / 2;
//		}
//	}
//	return NULL;
//}

//Ë«Ö¸Õë
//int* twoSum_167(int* numbers, int numbersSize, int target, int* returnSize) {
//	int* res = (int*)calloc(2, sizeof(int));
//
//	for (int low = 0, high = numbersSize - 1; low < high;) {
//		int sum = numbers[low] + numbers[high];
//
//		if (sum == target) {
//			res[0] = low + 1;
//			res[1] = high + 1;
//			(*returnSize) = 2;
//			return res;
//		} else if (sum < target) {
//			low++;
//		} else {
//			high--;
//		}
//	}
//	return NULL;
//}