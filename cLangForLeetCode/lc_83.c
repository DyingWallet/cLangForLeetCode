//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//ʾ��1 :
//����: 1->1->2
//��� : 1->2
//ʾ��2 :
//���� : 1->1->2->3->3
//��� : 1->2->3
#include"leetCode.h"

typedef struct ListNode listNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head || !head->next) return head;
	int temp = head->val;
	listNode* cur = head->next, * pre = head;
	while (cur) {
		if (pre->val == cur->val) {//�������ֵ
			pre->next = cur->next;
			cur = pre->next;
		} else {//�����
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}