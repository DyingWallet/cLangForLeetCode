//给你一个数组nums，数组中有2n个元素，按[x1, x2, ..., xn, y1, y2, ..., yn] 的格式排列。
//
//请你将数组按[x1, y1, x2, y2, ..., xn, yn] 格式重新排列，返回重排后的数组。
//示例 1：
//
//输入：nums = [2, 5, 1, 3, 4, 7], n = 3
//输出：[2, 3, 5, 4, 1, 7]
//解释：由于 x1 = 2, x2 = 5, x3 = 1, y1 = 3, y2 = 4, y3 = 7 ，所以答案为[2, 3, 5, 4, 1, 7]
#include"leetCode.h"

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
	int* res = (int*)malloc(numsSize * sizeof(int));
	int p1 = 0, p2 = n;
	int i = 0;
	while (p1 < n) {
		res[i++] = nums[p1++];
		res[i++] = nums[p2++];
	}

	*returnSize = numsSize;
	return res;
}