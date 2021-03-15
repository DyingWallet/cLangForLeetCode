//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1 。
//示例 1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//示例 2：
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false
//示例 3：
//输入：root = []
//输出：true
//提示：
//树中的节点数在范围[0, 5000] 内
//-10e4 <= Node.val <= 10e4
#include"leetCode.h"

typedef struct TreeNode treeNode;
int height(treeNode* node);
bool isBalanced(struct TreeNode* root) {
	return height(root) >= 0;
}

int height(treeNode* node) {
	if (node == NULL) return 0;
	int lh = height(node->left), rh = height(node->right);
	if (lh == -1 || rh == -1 || fabs(lh - rh) > 1) return -1;
	else return fmax(lh, rh) + 1;
}