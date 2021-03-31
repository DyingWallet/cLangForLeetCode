//给定一个非负整数numRows，生成杨辉三角的前numRows行。
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//示例 :
//输入: 5
//输出 :
//[
//        [ 1],
//       [ 1, 1],
//      [ 1, 2, 1],
//	   [ 1, 3, 3, 1],
//    [ 1, 4, 6, 4, 1]
//]
#include"leetCode.h"

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	*returnSize = numRows;
	*returnColumnSizes = (int*)calloc(numRows, sizeof(int));
	int** res = (int**)calloc(numRows, sizeof(int*));
	int* curRow = NULL;
	for (int i = 0; i < numRows; i++) {
		curRow = (int*)calloc(i+1, sizeof(int));
		(*returnColumnSizes)[i] = i + 1;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				curRow[j] = 1;
			else
				curRow[j] = res[i - 1][j - 1] + res[i - 1][j];

		}
		res[i] = curRow;
	}
	return res;
}