//����һ���Ǹ�����k������ k��33������������ǵĵ� k �С�
//����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
//ʾ�� :
//����: 3
//��� : [1, 3, 3, 1]
//        [ 1],
//       [ 1, 1],
//      [ 1, 2, 1],
//	   [ 1, 3, 3, 1],
//    [ 1, 4, 6, 4, 1]
//���ף�
//������Ż�����㷨�� O(k) �ռ临�Ӷ���
#include"leetCode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//����һά��������������
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