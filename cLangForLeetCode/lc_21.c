//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//ʾ�� 1��
//���룺l1 = [1, 2, 4], l2 = [1, 3, 4]
//�����[1, 1, 2, 3, 4, 4]
//ʾ�� 2��
//���룺l1 = [], l2 = []
//�����[]
//ʾ�� 3��
//���룺l1 = [], l2 = [0]
//�����[0]
//��ʾ��
//��������Ľڵ���Ŀ��Χ��[0, 50]
//- 100 <= Node.val <= 100
//l1 �� l2 ���� �ǵݼ�˳�� ����

#include"leetCode.h"

//������ʽ
typedef struct ListNode listNode;
listNode* append(listNode** cur, listNode* node);
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (!l1 || !l2) return l1 == NULL ? l2 : l1;//�п�
	listNode* res = (listNode*)calloc(1, sizeof(listNode)), * pre = res;
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			l1 = append(&pre, l1);
		} else {
			l2 = append(&pre, l2);
		}
	}
	if (!l1) pre->next = l2;
	if (!l2) pre->next = l1;
	return res->next;
}

listNode* append(listNode** pre, listNode* node) {
	listNode* temp = node->next;
	(*pre)->next = node;
	node->next = NULL;
	*pre = (*pre)->next;
	return temp;
}