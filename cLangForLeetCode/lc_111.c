//����һ�����������ҳ�����С��ȡ�
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//ʾ�� 1��
//���룺root = [3, 9, 20, null, null, 15, 7]
//�����2
//ʾ�� 2��
//���룺root = [2, null, 3, null, 4, null, 5, null, 6]
//�����5
//��ʾ��
//���нڵ����ķ�Χ��[0, 10e5] ��
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
	if (!node->left && !node->right) return dep;//Ҷ�ӽڵ�
	else {//��Ҷ�ӽڵ�
		if (!node->left) return minHelper(node->right, dep);
		else if (!node->right) return minHelper(node->left, dep);
		else return fmin(minHelper(node->left, dep), minHelper(node->right, dep));
	}
}