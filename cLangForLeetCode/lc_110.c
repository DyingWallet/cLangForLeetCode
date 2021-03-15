//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
//ʾ�� 1��
//���룺root = [3, 9, 20, null, null, 15, 7]
//�����true
//ʾ�� 2��
//���룺root = [1, 2, 2, 3, 3, null, null, 4, 4]
//�����false
//ʾ�� 3��
//���룺root = []
//�����true
//��ʾ��
//���еĽڵ����ڷ�Χ[0, 5000] ��
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