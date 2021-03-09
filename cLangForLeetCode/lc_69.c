//实现 int sqrt(int x) 函数。
//计算并返回 x 的平方根，其中 x 是非负整数。
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//示例 1:
//输入: 4
//输出 : 2
//示例 2 :
//输入 : 8
//输出 : 2
//说明 : 8 的平方根是 2.82842...,
//由于返回类型是整数，小数部分将被舍去。
#include"leetCode.h"

int mySqrt(int x) {
	if (x == 0) return 0;
	if (x <= 3) return 1;

	int low = 2, up = x / 2, mid = (low + up) / 2, res = -1;
	while (low <= up) {
		if ((long long)mid * mid <= x) {
			res = mid;
			low = mid + 1;
		} else up = mid - 1;
		mid = (low + up) / 2;
	}
	return res;
}