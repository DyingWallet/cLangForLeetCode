//��������������������dividend�ͳ���divisor�������������Ҫ��ʹ�ó˷���������mod�������
//���ر�����dividend���Գ���divisor�õ����̡�
//���������Ľ��Ӧ����ȥ��truncate����С�����֣����磺truncate(8.345)=8�Լ�truncate(-2.7335)=-2
//ʾ��1:
//����:dividend=10,divisor=3
//���:3
//����:10/3=truncate(3.33333..)=truncate(3)=3
//ʾ��2:
//����:dividend=7,divisor=-3
//���:-2
//����:7/-3=truncate(-2.33333..)=-2
//dividend:������,divisor:����

#include"leetCode.h"

int divide(int dividend, int divisor) {
	bool isPositive = (dividend >> 31 ^ divisor >> 31) == 0 ? true : false;
	unsigned int num, fac;
	//�����������
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
	//һ�����
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