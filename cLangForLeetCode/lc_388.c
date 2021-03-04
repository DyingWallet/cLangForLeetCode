//给定一个非负整数num。对于0 ≤ i ≤ num 范围中的每个数字i，计算其二进制数中的 1 的数目并将它们作为数组返回。
//示例 1:
//输入: 2
//输出 : [0, 1, 1]
//示例?2 :
//输入 : 5
//输出 : [0, 1, 1, 2, 1, 2]

#include"leetCode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//最高有效位
int* countBitsHigh(int num, int* returnSize) {
	int* res = (int*)calloc(num + 1, sizeof(int));
	int highVal = 0;
	for (int i = 1; i <= num; i++) {
		if ((i & (i - 1)) == 0)
			highVal = i;
		res[i] = res[i - highVal] + 1;
	}
	*returnSize = num + 1;
	return res;
}

//最低有效位
int* countBitsLow(int num, int* returnSize) {
	int* res = (int*)calloc(num + 1, sizeof(int));
	int lowVal = 0;

	for (int i = 1; i <= num; i++) {
		res[i] = res[i / 2] + (res[i] & 1);
	}
	*returnSize = num + 1;
	return res;
}