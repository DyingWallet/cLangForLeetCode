//����һ���������� nums ��
//���һ������(i, j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��
//	���غ����Ե���Ŀ��
//	ʾ�� 1��
//	���룺nums = [1, 2, 3, 1, 1, 3]
//	�����4
//	���ͣ��� 4 ������ԣ��ֱ���(0, 3), (0, 4), (3, 4), (2, 5) ���±�� 0 ��ʼ
//	ʾ�� 2��
//	���룺nums = [1, 1, 1, 1]
//	�����6
//	���ͣ������е�ÿ�����ֶ��Ǻ�����
//  count+=(num * num-1)/2
#include"leetCode.h"
#define HASH_SIZE 101
#define MIN -10e9
int numIdenticalPairs(int* nums, int numsSize) {
	int count = 0, maxNum = MIN;
	int* arr = NULL;
	if ((arr = (int*)calloc(HASH_SIZE, sizeof(int))) != NULL) {
		for (int i = 0; i < numsSize; i++) {
			arr[nums[i]] += 1;
			maxNum = maxNum < nums[i] ? nums[i] : maxNum;
		}
		for (int i = 0; i <= maxNum; i++)
			if (arr[i] > 1)
				count += (arr[i] * (arr[i] - 1)) / 2;
		free(arr);
		return count;
	}
	exit(-1);
}