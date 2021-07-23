#include"leetCode.h"
#include"leetCodeStructs.h"

typedef struct TreeNode treeNode;

//������ǰ�����-������
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	(*returnSize) = 0;
	if (!root) {
		return NULL;
	}

	//��ʼ��ջ
	treeNode** stk = (treeNode**)calloc(100, sizeof(treeNode*));
	int* res = (int*)calloc(100, sizeof(int));
	int top = -1, i = 0;

	while (root || top != -1) {
		if (!root) root = stk[top--];
		//���ʵ�ǰ�ڵ�
		res[i++] = root->val;
		//����ǰ�ڵ����ӽڵ���ջ
		if (root->right)
			stk[++top] = root->right;
		//���ʵ�ǰ�ڵ�����ӽڵ�
		root = root->left;
	}
	(*returnSize) = i;
	return res;
}