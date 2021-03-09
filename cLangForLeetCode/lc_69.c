//ʵ�� int sqrt(int x) ������
//���㲢���� x ��ƽ���������� x �ǷǸ�������
//���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��
//ʾ�� 1:
//����: 4
//��� : 2
//ʾ�� 2 :
//���� : 8
//��� : 2
//˵�� : 8 ��ƽ������ 2.82842...,
//���ڷ���������������С�����ֽ�����ȥ��
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