//给定两个数组，编写一个函数来计算它们的交集。
//示例 1：
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2, 2]
//示例 2:
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[4, 9]
//说明：
//输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
//我们可以不考虑输出结果的顺序。
//进阶：
//如果给定的数组已经排好序呢？你将如何优化你的算法？
//如果nums1的大小比nums2小很多，哪种方法更优？
//如果nums2的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

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