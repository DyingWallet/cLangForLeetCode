//给定一个非负索引k，其中 k≤33，返回杨辉三角的第 k 行。
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//示例 :
//输入: 3
//输出 : [1, 3, 3, 1]
//        [ 1],
//       [ 1, 1],
//      [ 1, 2, 1],
//	   [ 1, 3, 3, 1],
//    [ 1, 4, 6, 4, 1]
//进阶：
//你可以优化你的算法到 O(k) 空间复杂度吗？
#include"leetCode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//两个一维数组递推杨辉三角
int* getRow(int rowIndex, int* returnSize) {
	int* pre = (int*)calloc(1, sizeof(int));
	pre[0] = 1;
	int* res = pre;
	*returnSize = 1;
	if (rowIndex == 0) return res;
	for (int i = 1; i <= rowIndex; i++) {
		res = (int*)calloc(i + 1, sizeof(int));
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				res[j] = 1;
			else
				res[j] = pre[j] + pre[j - 1];
		}
		pre = res;
		(*returnSize)++;
	}
	return res;
}