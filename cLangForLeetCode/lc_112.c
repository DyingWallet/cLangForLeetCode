//����������ĸ��ڵ�root ��һ����ʾĿ��͵�����targetSum
//�жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��
//����·�������нڵ�ֵ��ӵ���Ŀ���targetSum ��
//Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
//ʾ�� 1��
//���룺root = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1], targetSum = 22
//�����true
//ʾ�� 2��
//���룺root = [1, 2, 3], targetSum = 5
//�����false
//ʾ�� 3��
//���룺root = [1, 2], targetSum = 0
//�����false
//��ʾ��
//���нڵ����Ŀ�ڷ�Χ[0, 5000] ��
//- 1000 <= Node.val <= 1000
//- 1000 <= targetSum <= 1000
#include"leetCode.h"

typedef struct TreeNode treeNode;

bool hasPathSum(struct TreeNode* root, int targetSum) {
	if (!root) return false;
	if (!root->left && !root->right)//Ҷ�ӽڵ�
		return targetSum == root->val;
	else {//��Ҷ�ӽڵ�
		return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
	}
}