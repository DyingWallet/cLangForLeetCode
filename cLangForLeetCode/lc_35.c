//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//����Լ������������ظ�Ԫ�ء�
//ʾ�� 1:						ʾ�� 3 :
//���� : [1, 3, 5, 6] , 5		���� : [1, 3, 5, 6] , 7
//��� : 2						��� : 4
//ʾ�� 2 :						ʾ�� 4 :
//���� : [1, 3, 5, 6] , 2		���� : [1, 3, 5, 6] , 0
//��� : 1						��� : 0
#include"leetCode.h"

int searchInsert(int* nums, int numsSize, int target) {
	int l = 0, r = numsSize - 1, mid = (l + r) / 2;
	while (l < r) {
		if (target < nums[mid]) r = mid;
		else if (target > nums[mid]) l = mid + 1;
		else return mid;
		mid = (l + r) / 2;
	}
	return target <= nums[mid] ? mid : mid + 1;
}