//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
//数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，
//这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 - 1。
//示例 1:
//输入: [1, 2, 1]
//输出 : [2, -1, 2]
//解释 : 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数；
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
//注意 : 输入数组的长度不会超过 10000。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"leetCode.h"

//单调递增栈
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
	int* res = (int*)malloc(numsSize * sizeof(int)),
		* stack = (int*)malloc((numsSize + 1) * sizeof(int));
	int top = 0;
	bool flag = false;
	memset(res, -1, numsSize * sizeof(int));
	memset(stack, -1, (numsSize + 1) * sizeof(int));

	for (int i = 0; i < numsSize; i++) {
		while (top != 0 && nums[stack[top]] < nums[i]) {//栈非空且当前栈顶元素小于i处元素进行出栈
			res[stack[top--]] = nums[i];
		}
		if (!flag) {//只入栈一次，不进行循环入栈
			stack[++top] = i;
		}
		if (!flag && i == numsSize - 1) {//数组进行循环
			i = -1;
			flag = true;
		}
	}
	*returnSize = numsSize;
	return res;
}

//int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
//	int i = 0, j = 0;
//	int* res = (int*)malloc(numsSize * sizeof(int));
//	memset(res, -1, numsSize * sizeof(int));
//	while (i < numsSize) {
//		for (j = i + 1; (j % numsSize) != i; j++) {
//			if (nums[i] < nums[j % numsSize]) {
//				res[i] = nums[j % numsSize];
//				break;
//			}
//		}
//		i++;
//	}
//	*returnSize = numsSize;
//	return res;
//}