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
			//����������
			stk[++top] = root;
			root = root->left;
		}
		//���ߵ���ͷ����ȡ���ֵܽڵ�
		root = stk[top--];
		//ջ���ڵ�����ӽڵ�Ϊ�ջ����ӽڵ� == prev��ʾ������������ı���
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