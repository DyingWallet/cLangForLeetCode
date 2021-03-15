//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵高度平衡二叉搜索树。
//高度平衡二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
//示例 1：
//输入：nums = [-10, -3, 0, 5, 9]
//输出：[0, -3, 9, -10, null, 5]
//解释：[0, -10, 5, null, -3, null, 9] 也将被视为正确答案：
//示例 2：
//输入：nums = [1, 3]
//输出：[3, 1]
//解释：[1, 3] 和[3, 1] 都是高度平衡二叉搜索树。
//提示：
//1 <= nums.length <= 10e4
//- 10e4 <= nums[i] <= 10e4
//nums 按 严格递增 顺序排列
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