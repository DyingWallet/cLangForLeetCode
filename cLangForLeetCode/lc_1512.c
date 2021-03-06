//给你一个整数数组 nums 。
//如果一组数字(i, j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
//	返回好数对的数目。
//	示例 1：
//	输入：nums = [1, 2, 3, 1, 1, 3]
//	输出：4
//	解释：有 4 组好数对，分别是(0, 3), (0, 4), (3, 4), (2, 5) ，下标从 0 开始
//	示例 2：
//	输入：nums = [1, 1, 1, 1]
//	输出：6
//	解释：数组中的每组数字都是好数对
//  count+=(num * num-1)/2
#include"leetCode.h"
#define HASH_SIZE 101
#define MIN -10e9
int numIdenticalPairs(int* nums, int numsSize) {
	int count = 0, maxNum = MIN;
	int* arr = NULL;
	if ((arr = (int*)calloc(HASH_SIZE, sizeof(int))) != NULL) {
		for (int i = 0; i < numsSize; i++) {
			arr[nums[i]] += 1;
			maxNum = maxNum < nums[i] ? nums[i] : maxNum;
		}
		for (int i = 0; i <= maxNum; i++)
			if (arr[i] > 1)
				count += (arr[i] * (arr[i] - 1)) / 2;
		free(arr);
		return count;
	}
	exit(-1);
}