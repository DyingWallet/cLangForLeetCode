//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
//ʾ�� 1��
//���룺p = [1, 2, 3], q = [1, 2, 3]
//�����true
//ʾ�� 2��
//���룺p = [1, 2], q = [1, null, 2]
//�����false
//ʾ�� 3��
//���룺p = [1, 2, 1], q = [1, 1, 2]
//�����false
//��ʾ��
//�������ϵĽڵ���Ŀ���ڷ�Χ[0, 100] ��
//- 10e4 <= Node.val <= 10e4
#include"leetCode.h"

typedef struct TreeNode treeNode;
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if ((p && !q) || (q && !p)) return false;
	if (!p && !q) return true;

	if (p->val == q->val) {
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	return false;
}