//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
//示例 1：
//输入：x = 121
//输出：true
//示例 2：
//输入：x = -121
//输出：false
//解释：从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
//示例 3：
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
//示例 4：
//输入：x = -101
//输出：false

#include"leetCode.h"

bool isPalindrome(int x) {
	if (x < 0) return false;
	int i = 0, j = 0;
	char* num = (char*)calloc(32, sizeof(char));
	while (x) {
		num[j++] = x % 10 + '0';
		x /= 10;
	}
	for (j--; i < j; i++, j--)
		if (num[i] != num[j]) return false;
	return true;
}