//给定两个整数，被除数dividend和除数divisor。将两数相除，要求不使用乘法、除法和mod运算符。
//返回被除数dividend除以除数divisor得到的商。
//整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345)=8以及truncate(-2.7335)=-2
//示例1:
//输入:dividend=10,divisor=3
//输出:3
//解释:10/3=truncate(3.33333..)=truncate(3)=3
//示例2:
//输入:dividend=7,divisor=-3
//输出:-2
//解释:7/-3=truncate(-2.33333..)=-2
//dividend:被除数,divisor:除数

#include"leetCode.h"

int divide(int dividend, int divisor) {
	bool isPositive = (dividend >> 31 ^ divisor >> 31) == 0 ? true : false;
	unsigned int num, fac;
	//处理特殊情况
	if (dividend == INT_MIN) {
		if (divisor == -1) return INT_MAX;
		if (divisor == 1) return dividend;
		num = (unsigned int)dividend;
	} else
		num = dividend > 0 ? dividend : -dividend;
	if (divisor == INT_MIN)
		return dividend == INT_MIN ? 1 : 0;
	else
		fac = divisor > 0 ? divisor : -divisor;
	if (fac == 1)
		return isPositive ? (dividend >> 31 ? -dividend : dividend) : (dividend >> 31 ? dividend : -dividend);
	//一般情况
	int res = 0;
	if (!(num < fac)) {
		int counter = 1;
		unsigned int temp = fac;
		while (num >= temp) {
			while (num > temp << 1) {
				counter <<= 1;
				temp <<= 1;
			}
			res += counter;
			counter = 1;
			num -= temp;
			temp = fac;
		}
	}
	return isPositive ? res : -res;
}