#include"leetCode.h"
#include"leetCodeStructs.h"
//ÅÅÐò
//¹þÏ£
//±©Á¦£¨³¬Ê±£©

int cmp_217(const void* _a, const void* _b) {
	int* a = _a, * b = _b;
	return *a == *b ? 0 : (*a > *b ? 1 : -1);
}

bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp_217);
	int pre = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (pre == nums[i]) return true;
		pre = nums[i];
	}
	return false;
}