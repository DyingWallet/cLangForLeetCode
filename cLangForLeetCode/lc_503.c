//����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ������ÿ��Ԫ�ص���һ������Ԫ�ء�
//���� x ����һ�������Ԫ���ǰ��������˳���������֮��ĵ�һ���������������
//����ζ����Ӧ��ѭ��������������һ�������������������ڣ������ - 1��
//ʾ�� 1:
//����: [1, 2, 1]
//��� : [2, -1, 2]
//���� : ��һ�� 1 ����һ����������� 2��
//���� 2 �Ҳ�����һ�����������
//�ڶ��� 1 ����һ����������Ҫѭ�����������Ҳ�� 2��
//ע�� : ��������ĳ��Ȳ��ᳬ�� 10000��

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"leetCode.h"

//��������ջ
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
	int* res = (int*)malloc(numsSize * sizeof(int)),
		* stack = (int*)malloc((numsSize + 1) * sizeof(int));
	int top = 0;
	bool flag = false;
	memset(res, -1, numsSize * sizeof(int));
	memset(stack, -1, (numsSize + 1) * sizeof(int));

	for (int i = 0; i < numsSize; i++) {
		while (top != 0 && nums[stack[top]] < nums[i]) {//ջ�ǿ��ҵ�ǰջ��Ԫ��С��i��Ԫ�ؽ��г�ջ
			res[stack[top--]] = nums[i];
		}
		if (!flag) {//ֻ��ջһ�Σ�������ѭ����ջ
			stack[++top] = i;
		}
		if (!flag && i == numsSize - 1) {//�������ѭ��
			i = -1;
			flag = true;
		}
	}
	*returnSize = numsSize;
	return res;
}

//int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
//	int i = 0, j = 0;
//	int* res = (int*)malloc(numsSize * sizeof(int));
//	memset(res, -1, numsSize * sizeof(int));
//	while (i < numsSize) {
//		for (j = i + 1; (j % numsSize) != i; j++) {
//			if (nums[i] < nums[j % numsSize]) {
//				res[i] = nums[j % numsSize];
//				break;
//			}
//		}
//		i++;
//	}
//	*returnSize = numsSize;
//	return res;
//}