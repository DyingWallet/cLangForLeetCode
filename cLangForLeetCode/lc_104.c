//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明 : 叶子节点是指没有子节点的节点。
//示例：
//给定二叉树[3, 9, 20, null, null, 15, 7]，
//    3
//   / \
//  9  20
// / \
//15  7
//返回它的最大深度3 。
#include"leetCode.h"

typedef struct TreeNode treeNode;
int depth(treeNode* node, int dep);
int maxDepth(struct TreeNode* root) {
	return depth(root, 0);
}

int depth(treeNode* node, int dep) {
	if (node == NULL) return dep;
	dep++;
	int l = depth(node->left, dep), r = depth(node->right, dep);
	return l > r ? l : r;
}