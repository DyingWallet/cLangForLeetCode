//����һ����������ɵķǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//ʾ��1��						ʾ��2��							ʾ�� 3��
//���룺digits = [1, 2, 3]		���룺digits = [4, 3, 2, 1]		���룺digits = [0]
//�����[1, 2, 4]				�����[4, 3, 2, 2]				�����[1]
//���ͣ����������ʾ���� 123��	���ͣ����������ʾ���� 4321��
//��ʾ��
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