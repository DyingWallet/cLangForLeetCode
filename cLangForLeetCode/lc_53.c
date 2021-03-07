//给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//示例 1：											示例 3：
//输入：nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]		输入：nums = [0]
//输出：6											输出：0
//解释：连续子数组[4, -1, 2, 1] 的和最大，为6 。		
//示例 2：											示例 4：
//输入：nums = [1]									输入：nums = [-1]
//输出：1											输出： - 1
//示例 5：
//输入：nums = [-100000]
//输出： - 100000
//提示：
//1 <= nums.length <= 3 * 10e4
//- 10e5 <= nums[i] <= 10e5
#include"leetCode.h"
//贪心
int maxSubArray(int* nums, int numsSize) {
	int res = INT_MIN, sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
		res = sum > res ? sum : res;
		if (sum <= 0) 	//如果有sum加上nums[i]后小于0的情况，直接舍弃，从i+i开始重新累加
			sum = 0;
	}
	return res;
}
//暴力+滑动窗口
//int maxSubArray(int* nums, int numsSize) {
//	int res = INT_MIN;
//	for (int i = 1; i <= numsSize;i++) {
//		int sum = 0;
//		for (int j = 0; j < i; j++) {
//			sum += nums[j];
//		}
//		res = res < sum ? sum : res;
//		for (int j = i; j < numsSize; j++) {//滑动窗口
//			sum = sum + nums[j] - nums[j-i];
//			res = res < sum ? sum : res;
//		}
//	}
//	return res;
//}