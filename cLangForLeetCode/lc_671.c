
#include"leetCode.h"

typedef struct TreeNode* treeNode;
void find(treeNode node, long long* res, int rootVal);
int findSecondMinimumValue(struct TreeNode* root) {
	if (!root) return -1;
	long long res = LLONG_MAX;
	find(root, &res,root->val);
	return res == LLONG_MAX ? -1 : (int)res;
}

void find(treeNode node, long long* res, int rootVal) {
	if (node) {
		if (node->val > rootVal && node->val < *res)
			*res = node->val;
		if (node->left && node->right) {
			find(node->left, res, rootVal);
			find(node->right, res, rootVal);
		}
	}
}