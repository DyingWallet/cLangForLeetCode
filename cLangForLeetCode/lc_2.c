//���������ǿյ�������ʾ�����Ǹ���������
//����ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
//���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
//����Լ����������0֮�⣬����������������0��ͷ��
//ʾ�� 1��
//���룺l1 = [2, 4, 3], l2 = [5, 6, 4]
//�����[7, 0, 8]
//���ͣ�342 + 465 = 807.
//ʾ�� 2��
//���룺l1 = [0], l2 = [0]
//�����[0]
//ʾ�� 3��
//���룺l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//�����[8, 9, 9, 9, 0, 0, 0, 1]
#include"leetCode.h"

typedef struct ListNode* listNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	listNode res = l1, pre = NULL;
	int isUp = 0;
	while (l1 && l2) {
		l1->val += l2->val + isUp;
		isUp = l1->val / 10;
		if (isUp) l1->val %= 10;
		pre = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (!l1 || !l2) {
		if (!l1 && l2) {//l1��l2��
			pre->next = l2;
			l1 = pre->next;
		}
		while (l1 && isUp) {
			l1->val += isUp;
			isUp = l1->val / 10;
			if (isUp) l1->val %= 10;
			pre = l1;
			l1 = l1->next;
		}
	}
	if (isUp) {
		listNode node = (listNode)calloc(1, sizeof(struct ListNode));
		node->val = isUp;
		node->next = NULL;
		pre->next = node;
	}
	return res;
}