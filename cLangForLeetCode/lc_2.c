//给你两个非空的链表，表示两个非负的整数。
//它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字0之外，这两个数都不会以0开头。
//示例 1：
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 0, 8]
//解释：342 + 465 = 807.
//示例 2：
//输入：l1 = [0], l2 = [0]
//输出：[0]
//示例 3：
//输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//输出：[8, 9, 9, 9, 0, 0, 0, 1]
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
		if (!l1 && l2) {//l1比l2短
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