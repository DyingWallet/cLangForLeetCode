//��������������������nums1 �� nums2�����㽫 nums2 �ϲ���nums1�У�ʹ nums1 ��Ϊһ���������顣
//��ʼ��nums1 �� nums2 ��Ԫ�������ֱ�Ϊm �� n ��
//����Լ���nums1 �Ŀռ��С����m + n�������������㹻�Ŀռ䱣������ nums2 ��Ԫ�ء�
//ʾ�� 1��
//���룺nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//�����[1, 2, 2, 3, 5, 6]
//ʾ�� 2��
//���룺nums1 = [1], m = 1, nums2 = [], n = 0
//�����[1]
//��ʾ��
//nums1.length == m + n
//nums2.length == n
//0 <= m, n <= 200
//1 <= m + n <= 200
//- 10e9 <= nums1[i], nums2[i] <= 10e9
#include"leetCode.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i = nums1Size - 1, j = m - 1, k = n - 1;

	while (i >= 0) {
		if (j >= 0 && k >= 0) {
			if (nums1[j] > nums2[k]) {
				nums1[i--] = nums1[j--];
			} else {
				nums1[i--] = nums2[k--];
			}
		} else if (j >= 0 && k < 0) {
			nums1[i--] = nums1[j--];
		} else if (j < 0 && k >= 0) {
			nums1[i--] = nums2[k--];
		}
	}
}


//����ռ�
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//	int* res = calloc(nums1Size, sizeof(int));
//	int i = 0, j = 0, k = 0;
//
//	while (i < nums1Size) {
//		if (j < m && k < n) {
//			if (nums1[j] < nums2[k])
//				res[i++] = nums1[j++];
//			else if (nums1[j] > nums2[k])
//				res[i++] = nums2[k++];
//			else {//���
//				res[i++] = nums1[j++];
//				res[i++] = nums2[k++];
//			}
//		} else if (j < m && k >= n) {
//			res[i++] = nums1[j++];
//		} else if (j >= m && k < n) {
//			res[i++] = nums2[k++];
//		}
//	}
//	i = 0;
//	while (i < nums1Size) {
//		nums1[i] = res[i];
//		i++;
//	}
//}