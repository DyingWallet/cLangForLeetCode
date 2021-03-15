//����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�ø߶�ƽ�������������
//�߶�ƽ���������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������
//ʾ�� 1��
//���룺nums = [-10, -3, 0, 5, 9]
//�����[0, -3, 9, -10, null, 5]
//���ͣ�[0, -10, 5, null, -3, null, 9] Ҳ������Ϊ��ȷ�𰸣�
//ʾ�� 2��
//���룺nums = [1, 3]
//�����[3, 1]
//���ͣ�[1, 3] ��[3, 1] ���Ǹ߶�ƽ�������������
//��ʾ��
//1 <= nums.length <= 10e4
//- 10e4 <= nums[i] <= 10e4
//nums �� �ϸ���� ˳������
#include"leetCode.h"

typedef struct TreeNode treeNode;

treeNode* builder(int * nums,int left,int right);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	return builder(nums, 0, numsSize - 1);
}

treeNode* builder(int* nums, int left, int right) {
	if (left > right) return NULL;
	int mid = left + (right - left) / 2;
	treeNode* node = (treeNode*)calloc(1, sizeof(treeNode));
	node->val = nums[mid];
	node->left = builder(nums, left, mid - 1);
	node->right = builder(nums, mid + 1, right);
	return node;
}