//����һ�����������ҳ��������ȡ�
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//ʾ����
//����������[3, 9, 20, null, null, 15, 7]��
//    3
//   / \
//  9  20
// / \
//15  7
//��������������3 ��
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