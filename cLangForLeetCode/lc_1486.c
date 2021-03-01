//��������������n �� start ��
//���� nums ����Ϊ��nums[i] = start + 2 * i���±�� 0 ��ʼ���� n == nums.length ��
//�뷵�� nums ������Ԫ�ذ�λ���XOR����õ��Ľ����
//ʾ�� 1��
//���룺n = 5, start = 0
//�����8
//���ͣ����� nums Ϊ[0, 2, 4, 6, 8]������(0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 ��
//"^" Ϊ��λ��� XOR �������
//ʾ�� 2��
//���룺n = 4, start = 3
//�����8
//���ͣ����� nums Ϊ[3, 5, 7, 9]������(3 ^ 5 ^ 7 ^ 9) = 8.

#include"leetCode.h"

int xorOperation(int n, int start) {
	int res = start, next;
	for (int i = 1; i < n; i++) {
		next = start + 2 * i;
		res ^= next;
	}
	return res;
}