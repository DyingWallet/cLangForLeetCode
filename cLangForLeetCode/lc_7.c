//给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。
//如果反转后整数超过 32 位的有符号整数的范围[-2^31, 2^31 - 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。
//示例 1：
//输入：x = 123
//输出：321
//示例 2：
//输入：x = -123
//输出： - 321
//示例 3：
//输入：x = 120
//输出：21
//示例 4：
//输入：x = 0
//输出：0
#include"leetCode.h"

//INT_MIN     -2147483648
//INT_MAX      2147483647
//INT_MIN/10  -214748364
//INT_MAX/10   214748364
int reverse(int x) {
	int res = 0;
	while (x / 10) {
		if ((int)(res * 10) / 10 != res) return 0;
		res = 10 * res + x % 10;
		x /= 10;
	}
	if (res > INT_MAX / 10 || (res == INT_MAX / 10 && x > 7)) return 0;
	if (res < INT_MIN / 10 || (res == INT_MIN / 10 && x < -8)) return 0;
	return 10 * res + x;
}