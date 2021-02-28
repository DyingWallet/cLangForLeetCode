//����һ������candies��һ������extraCandies������?candies[i]����� i ������ӵ�е��ǹ���Ŀ��
//��ÿһ�����ӣ�����Ƿ����һ�ַ������������?extraCandies?���ǹ������������֮�󣬴˺����� ���?���ǹ���
//ע�⣬�����ж������ͬʱӵ�� ���?���ǹ���Ŀ��
//ʾ�� 1��
//���룺candies = [2, 3, 5, 1, 3], extraCandies = 3
//�����[true, true, true, false, true]
//���ͣ�
//���� 1 �� 2 ���ǹ���������õ����ж�����ǹ���3��������ô���ܹ��� 5 ���ǹ���������Ϊӵ������ǹ��ĺ��ӡ�
//���� 2 �� 3 ���ǹ���������õ����� 2 �������ǹ�����ô������Ϊӵ������ǹ��ĺ��ӡ�
//���� 3 �� 5 ���ǹ������Ѿ���ӵ������ǹ��ĺ��ӡ�
//���� 4 �� 1 ���ǹ�����ʹ���õ����ж�����ǹ�����Ҳֻ�� 4 ���ǹ����޷���Ϊӵ���ǹ����ĺ��ӡ�
//���� 5 �� 3 ���ǹ���������õ����� 2 �������ǹ�����ô������Ϊӵ������ǹ��ĺ��ӡ�
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"leetCode.h"

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
	int lim = -1;
	*returnSize = candiesSize;
	bool* res = (bool*)calloc(candiesSize, sizeof(bool));
	for (int i = 0; i < candiesSize; i++)
		lim = lim < candies[i] ? candies[i] : lim;
	lim -= extraCandies;
	for (int i = 0; i < candiesSize; i++) {
		if (candies[i] >= lim)
			res[i] = true;
	}
	return res;
}