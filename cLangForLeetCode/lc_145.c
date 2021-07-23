#include"leetCode.h"
#include"leetCodeStructs.h"

typedef struct TreeNode treeNode;

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	treeNode** stk = (treeNode**)calloc(100, sizeof(treeNode*));
	treeNode* prev = NULL;
	int* res = (int*)calloc(100, sizeof(int));
	int top = -1, i = 0;

	while (root || top != -1) {
		while (root) {
			//遍历至最左
			stk[++top] = root;
			root = root->left;
		}
		//当走到左尽头，获取右兄弟节点
		root = stk[top--];
		//栈顶节点的右子节点为空或右子节点 == prev表示完成了右子树的遍历
		if (!root->right || root->right == prev) {
			res[i++] = root->val;
			prev = root;
			root = NULL;
		} else {
			stk[++top] = root;
			root = root->right;
		}
	}
	(*returnSize) = i;
	return res;
}