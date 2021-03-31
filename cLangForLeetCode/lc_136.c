//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//示例 1:
//输入: [2, 2, 1]
//输出 : 1
//示例 2 :
//输入 : [4, 1, 2, 1, 2]
//输出 : 4
#include"leetCode.h"

int arrCmp(const void* _a, const void* _b) {
	int* a = _a, * b = _b;
	return *a == *b ? 0 : (*a > *b ? 1 : -1);
}

int singleNumber(int* nums, int numsSize) {
	if (numsSize == 1) return nums[0];
	qsort(nums, numsSize, sizeof(int), arrCmp);

	int pre = nums[0], cur = 0, res = 0, i = 1;
	bool isExist = true;
	while (i < numsSize) {
		cur = nums[i];
		if (cur == pre)
			i++;
		else if (cur != pre) {
			if (cur == nums[i + 1]) {
				res = pre;
			} else {
				res = cur;
			}
			break;
		}
		pre = nums[i];
		i++;
	}
	return i == numsSize + 1 ? nums[numsSize - 1] : res;
}