#include"leetCode.h"
#include"leetCodeStructs.h"

typedef struct TreeNode treeNode;

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	if (!root)
		return NULL;

	//³õÊ¼»¯Õ»
	int top = -1, i = 0;
	int* inOrderArr = calloc(100, sizeof(int));
	treeNode** stk = (treeNode**)calloc(100, sizeof(treeNode*));

	while (root || top != -1) {
		while (root) {
			stk[++top] = root;
			root = root->left;
		}
		root = stk[top--];
		inOrderArr[i++] = root->val;
		root = root->right;
	}
	*returnSize = i;
	return inOrderArr;
}