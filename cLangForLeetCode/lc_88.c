//给你两个有序整数数组nums1 和 nums2，请你将 nums2 合并到nums1中，使 nums1 成为一个有序数组。
//初始化nums1 和 nums2 的元素数量分别为m 和 n 。
//你可以假设nums1 的空间大小等于m + n，这样它就有足够的空间保存来自 nums2 的元素。
//示例 1：
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//示例 2：
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
//提示：
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


//额外空间
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
//			else {//相等
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