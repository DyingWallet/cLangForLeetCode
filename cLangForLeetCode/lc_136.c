//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
//ʾ�� 1:
//����: [2, 2, 1]
//��� : 1
//ʾ�� 2 :
//���� : [4, 1, 2, 1, 2]
//��� : 4
#include"leetCode.h"

int arrCmp(const void* _a, const void* _b) {
	int* a = _a, * b = _b;
	return *a == *b ? 0 : (*a > *b ? 1 : -1);
}

int singleNumber(int* nums, int numsSize) {
	if (numsSize == 1) return nums[0];
	qsort(nums, numsSize, sizeof(int), arrCmp);

	int pre = nums[0], cur = 0, res = 0, i = 1;
	bool isExist = true;
	while (i < numsSize) {
		cur = nums[i];
		if (cur == pre)
			i++;
		else if (cur != pre) {
			if (cur == nums[i + 1]) {
				res = pre;
			} else {
				res = cur;
			}
			break;
		}
		pre = nums[i];
		i++;
	}
	return i == numsSize + 1 ? nums[numsSize - 1] : res;
}