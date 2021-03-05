//�����������飬��дһ���������������ǵĽ�����
//ʾ�� 1��
//���룺nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//�����[2, 2]
//ʾ�� 2:
//���룺nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//�����[4, 9]
//˵����
//��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ִ�������Сֵһ�¡�
//���ǿ��Բ�������������˳��
//���ף�
//��������������Ѿ��ź����أ��㽫����Ż�����㷨��
//���nums1�Ĵ�С��nums2С�ܶ࣬���ַ������ţ�
//���nums2��Ԫ�ش洢�ڴ����ϣ��ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include"leetCode.h"

int cmp(const void* _a, const void* _b) {
	int* a = _a, * b = _b;
	return *a == *b ? 0 : (*a > *b ? 1 : -1);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	bool _1shorterThan2 = nums1Size < nums2Size;
	int len = _1shorterThan2 ? nums1Size : nums2Size;
	*returnSize = 0;
	if (nums1Size == 0 || nums2Size == 0) return _1shorterThan2 ? nums1 : nums2;
	int* res = (int*)calloc(len, sizeof(int));
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
		if (nums1[i] < nums2[j]) i++;
		else if (nums1[i] > nums2[j]) j++;
		else {
			res[(*returnSize)++] = nums1[i++];
			j++;
		}
	}
	return res;
}