#include"leetCode.h"
#include"leetCodeStructs.h"

typedef struct TreeNode treeNode;

//二叉树前序遍历-迭代法
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	(*returnSize) = 0;
	if (!root) {
		return NULL;
	}

	//初始化栈
	treeNode** stk = (treeNode**)calloc(100, sizeof(treeNode*));
	int* res = (int*)calloc(100, sizeof(int));
	int top = -1, i = 0;

	while (root || top != -1) {
		if (!root) root = stk[top--];
		//访问当前节点
		res[i++] = root->val;
		//将当前节点右子节点入栈
		if (root->right)
			stk[++top] = root->right;
		//访问当前节点的左子节点
		root = root->left;
	}
	(*returnSize) = i;
	return res;
}