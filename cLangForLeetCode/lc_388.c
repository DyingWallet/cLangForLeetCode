//����һ���Ǹ�����num������0 �� i �� num ��Χ�е�ÿ������i����������������е� 1 ����Ŀ����������Ϊ���鷵�ء�
//ʾ�� 1:
//����: 2
//��� : [0, 1, 1]
//ʾ��?2 :
//���� : 5
//��� : [0, 1, 1, 2, 1, 2]

#include"leetCode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//�����Чλ
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

//�����Чλ
int* countBitsLow(int num, int* returnSize) {
	int* res = (int*)calloc(num + 1, sizeof(int));
	int lowVal = 0;

	for (int i = 1; i <= num; i++) {
		res[i] = res[i / 2] + (res[i] & 1);
	}
	*returnSize = num + 1;
	return res;
}