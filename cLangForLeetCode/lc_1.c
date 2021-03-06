//1. 两数之和
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//你可以按任意顺序返回答案。
//示例 1：
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//示例 2：
//输入：nums = [3, 2, 4], target = 6
//输出：[1, 2]
//示例 3：
//输入：nums = [3, 3], target = 6
//输出：[0, 1]
//提示：
//2 <= nums.length <= 10e3
//- 10e9 <= nums[i] <= 10e9
//- 10e9 <= target <= 10e9
//只会存在一个有效答案
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"leetCode.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* res = (int*)calloc(*returnSize, sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				res[0] = i;
				res[1] = j;
			}
		}
	}
	return res;
}