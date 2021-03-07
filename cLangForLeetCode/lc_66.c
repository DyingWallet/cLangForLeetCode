//给定一个由整数组成的非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//示例1：						示例2：							示例 3：
//输入：digits = [1, 2, 3]		输入：digits = [4, 3, 2, 1]		输入：digits = [0]
//输出：[1, 2, 4]				输出：[4, 3, 2, 2]				输出：[1]
//解释：输入数组表示数字 123。	解释：输入数组表示数字 4321。
//提示：
//1 <= digits.length <= 100
//0 <= digits[i] <= 9
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"leetCode.h"
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int* res = (int*)calloc(digitsSize + 1, (sizeof(int)));
	bool isUp = true;
	int i = digitsSize - 1, j = digitsSize;
	while(i >= 0) {
		res[j] = isUp ? digits[i] + 1 : digits[i];
		isUp = res[j] / 10;
		if (isUp) res[j] %= 10;
		j--, i--;
	}
	*returnSize = digitsSize;
	if (isUp) {
		res[j] = 1;
		(*returnSize)++;
	}
	return isUp ? res : res + 1;
}