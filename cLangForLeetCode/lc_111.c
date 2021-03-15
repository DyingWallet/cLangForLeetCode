//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点。
//示例 1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：2
//示例 2：
//输入：root = [2, null, 3, null, 4, null, 5, null, 6]
//输出：5
//提示：
//树中节点数的范围在[0, 10e5] 内
//- 1000 <= Node.val <= 1000
#include"leetCode.h"

typedef struct TreeNode treeNode;

int minHelper(treeNode* node, int dep);
int minDepth(struct TreeNode* root) {
	return minHelper(root, 0);
}

int minHelper(treeNode* node, int dep) {
	if (!node) return dep;
	dep++;
	if (!node->left && !node->right) return dep;//叶子节点
	else {//非叶子节点
		if (!node->left) return minHelper(node->right, dep);
		else if (!node->right) return minHelper(node->left, dep);
		else return fmin(minHelper(node->left, dep), minHelper(node->right, dep));
	}
}